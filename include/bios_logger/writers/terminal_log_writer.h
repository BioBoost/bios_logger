#pragma once

#include <string>
#include <iostream>
#include "../log_writer.h"

namespace BiosLogger {

  class TerminalLogWriter : public LogWriter {

    public:
      TerminalLogWriter(LogLevel level=logINFO)
        : LogWriter(level) { }

    public:
      virtual void write_message(std::string fullMessage) override {
        std::cout << fullMessage << std::endl;
      }

  };

};
