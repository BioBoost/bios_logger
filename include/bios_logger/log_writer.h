#pragma once

#include <string>
#include "log_level.h"
#include "log_formatter.h"

namespace BiosLogger {

  class LogWriter {
    private:
      LogLevel logLevel;
      LogFormatter * formatter;

    public:
      LogWriter(LogLevel level=logINFO);
      virtual ~LogWriter(void);

    public:
      void set_log_level(LogLevel level);
      void deliver_message(std::string message, LogLevel level);
      void register_log_formatter(LogFormatter * formatter);

    public:
      virtual void write_message(std::string fullMessage) = 0;

  };

};
