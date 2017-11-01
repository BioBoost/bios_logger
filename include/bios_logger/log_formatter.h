#pragma once

#include "log_level.h"
#include <string>

namespace BiosLogger {

  class LogFormatter {

    public:
      virtual ~LogFormatter(void);

    public:
      // You can override this with custom format (for example json)
      virtual std::string format_message(std::string message, LogLevel level);

    public:
      static std::string level_to_string(LogLevel level);
      static std::string get_current_timestamp(void);

  };

};
