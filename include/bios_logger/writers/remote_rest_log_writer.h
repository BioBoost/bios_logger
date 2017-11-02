#pragma once

#include <restclient-cpp/connection.h>
#include <string>
#include <thread>
#include <thread_safe/safe_queue.h>
#include "../log_writer.h"

namespace BiosLogger {

  enum HTTPCode { CREATED = 201 };

  class RemoteRestLogWriter : public LogWriter {

    private:
      std::string authenticationKey;
      RestClient::Connection* restConnection;
      std::string apiPath;

      // Threading stuff
      bool keepAcceptingLogs;
      std::thread logSendingThread;
      ThreadSafe::SafeQueue<std::string> messageQueue;

    public:
      RemoteRestLogWriter(std::string authenticationKey, std::string apiPath, std::string remoteServerAddress, unsigned int port, LogLevel level=logINFO);
      virtual ~RemoteRestLogWriter(void);

    public:
      virtual void write_message(std::string fullMessage) override;

    private:
      void setup_rest_client(std::string remoteServerAddress, unsigned int port);
      void log_sending_thread(void);

  };

};
