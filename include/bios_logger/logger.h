#pragma once

#include <string>
#include <vector>
#include "log_writer.h"
#include "log_level.h"

namespace BiosLogger {

  class Logger {

    private:
      std::vector<LogWriter *> writers;

    public:
      Logger(void);
      virtual ~Logger(void);

    public:
      void register_log_writer(LogWriter * writer);

    public:
      void verbose(std::string message);
      void info(std::string message);
      void debug(std::string message);
      void warning(std::string message);
      void error(std::string message);

    private:
      void send_message_to_all_writers(std::string message, LogLevel level);

  };
};
