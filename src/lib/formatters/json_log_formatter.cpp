#include "../../../include/bios_logger/formatters/json_log_formatter.h"
#include <json.hpp>

namespace BiosLogger {

  JsonLogFormatter::~JsonLogFormatter(void) { }

  std::string JsonLogFormatter::format_message(std::string message, LogLevel level) {
    nlohmann::json jsonMessage = {
      {"content", message},
      {"severity", LogFormatter::level_to_string(level)},
      {"logtime", LogFormatter::get_current_timestamp()}
    };
    std::string logMessage = jsonMessage.dump();
    return logMessage;
  }

};
