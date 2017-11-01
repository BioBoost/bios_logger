#include "../../include/bios_logger/log_writer.h"

namespace BiosLogger {

  LogWriter::LogWriter(LogLevel level) {
    set_log_level(level);
    formatter = new LogFormatter();     // Basic formatter
  }

  LogWriter::~LogWriter(void) {
    delete formatter;
  }

  void LogWriter::set_log_level(LogLevel level) {
    this->logLevel = level;
  }

  void LogWriter::deliver_message(std::string message, LogLevel level) {
    if (level >= logLevel) {
      write_message(formatter->format_message(message, level));
    }
  }

  void LogWriter::register_log_formatter(LogFormatter * formatter) {
    delete this->formatter;
    this->formatter = formatter;
  }

};
