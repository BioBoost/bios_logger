#include "../../include/bios_logger/logger.h"

namespace BiosLogger {

  Logger::Logger(void) { }

  Logger::~Logger(void) { }

  void Logger::register_log_writer(LogWriter * writer) {
    writers.push_back(writer);
  }

  void Logger::verbose(std::string message) {
    send_message_to_all_writers(message, logVERBOSE);
  }

  void Logger::info(std::string message) {
    send_message_to_all_writers(message, logINFO);
  }

  void Logger::debug(std::string message) {
    send_message_to_all_writers(message, logDEBUG);
  }

  void Logger::warning(std::string message) {
    send_message_to_all_writers(message, logWARNING);
  }

  void Logger::error(std::string message) {
    send_message_to_all_writers(message, logERROR);
  }

  void Logger::send_message_to_all_writers(std::string message, LogLevel level) {
    for (unsigned int i = 0; i < writers.size(); i++) {
      writers[i]->deliver_message(message, level);
    }
  }

};
