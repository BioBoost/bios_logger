#pragma once

#include "../log_formatter.h"
#include <string>

namespace BiosLogger {

  class JsonLogFormatter : public LogFormatter {

    public:
      virtual ~JsonLogFormatter(void);

    public:
      virtual std::string format_message(std::string message, LogLevel level);

  };

};
