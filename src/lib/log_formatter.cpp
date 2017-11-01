#include "../../include/bios_logger/log_formatter.h"

namespace BiosLogger {

  LogFormatter::~LogFormatter(void) { }

  std::string LogFormatter::format_message(std::string message, LogLevel level) {
    std::string output = "12-09-2009 11:22:33.123 [" + LogFormatter::level_to_string(level) + "] " + message;
    return output;
  }

  std::string LogFormatter::level_to_string(LogLevel level) {
    static std::string levelStrings[] = {
      "verbose", "info", "debug", "warning", "error"
    };

    return levelStrings[level];
  }

};
