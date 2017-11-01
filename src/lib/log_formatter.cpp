#include "../../include/bios_logger/log_formatter.h"
#include <iostream>
#include <sys/time.h>
#include <ctime>

namespace BiosLogger {

  LogFormatter::~LogFormatter(void) { }

  std::string LogFormatter::format_message(std::string message, LogLevel level) {
    return LogFormatter::get_current_timestamp()
      + " [" + LogFormatter::level_to_string(level) + "] " + message;
  }

  std::string LogFormatter::level_to_string(LogLevel level) {
    static std::string levelStrings[] = {
      "verbose", "info", "debug", "warning", "error"
    };

    return levelStrings[level];
  }

  std::string LogFormatter::get_current_timestamp(void) {
    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [80];
    std::tm temp ;
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime_r(&curTime.tv_sec, &temp));

    char currentTime[84] = "";
    sprintf(currentTime, "%s:%03d", buffer, milli);
    return std::string(currentTime);
  }

};
