#include "../../../include/bios_logger/writers/remote_rest_log_writer.h"
#include "../../../include/bios_logger/formatters/json_log_formatter.h"
#include <iostream>
#include <restclient-cpp/restclient.h>
#include <json.hpp>

namespace BiosLogger {

  RemoteRestLogWriter::RemoteRestLogWriter(std::string authenticationKey, std::string apiPath,
    std::string remoteServerAddress, unsigned int port, LogLevel level)
    : LogWriter(level) {
      this->authenticationKey = authenticationKey;
      this->apiPath = apiPath;
      this->register_log_formatter(new JsonLogFormatter());
      setup_rest_client(remoteServerAddress, port);
      keepAcceptingLogs = true;
      logSendingThread = std::thread(&RemoteRestLogWriter::log_sending_thread, this);
  }

  RemoteRestLogWriter::~RemoteRestLogWriter(void) {
    keepAcceptingLogs = false;
    logSendingThread.join();
      // deinit RestClient. After calling this you have to call RestClient::init()
      // again before you can use it
    RestClient::disable();
    delete restConnection;
  }

  void RemoteRestLogWriter::setup_rest_client(std::string remoteServerAddress, unsigned int port) {
    RestClient::init();
    restConnection = new RestClient::Connection("http://" + remoteServerAddress + ":" + std::to_string(port));
    restConnection->SetTimeout(5);
    restConnection->SetUserAgent("bios/logger");   // (this will result in the UA "bios/logger restclient-cpp/VERSION")
    restConnection->FollowRedirects(true);

    RestClient::HeaderFields headers;
    headers["Accept"] = "application/json";
    headers["Content-Type"] = "application/json";
    restConnection->SetHeaders(headers);
  }

  void RemoteRestLogWriter::write_message(std::string fullMessage) {
    if (keepAcceptingLogs) {
      nlohmann::json jsonMessage = {
        {"auth_key", authenticationKey},
        {"messages", { nlohmann::json::parse(fullMessage) }}
      };
      std::string logMessage = jsonMessage.dump();
      messageQueue.enqueue(logMessage);
    }
  }

  void RemoteRestLogWriter::log_sending_thread(void) {
    while(keepAcceptingLogs || !messageQueue.is_empty()) {
      if (!messageQueue.is_empty()) {
        std::string logMessage = messageQueue.dequeue();
        RestClient::Response response = restConnection->post(apiPath, logMessage);
        if (response.code != CREATED) {
          // TODO - Here we should be able to throw exception:
          // https://stackoverflow.com/questions/233127/how-can-i-propagate-exceptions-between-threads
          // Maybe we should be able to register a handle from our app itself which can then be called here
          std::cout << "Failed to send logmessage" << std::endl;
        }
      } else {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }

};
