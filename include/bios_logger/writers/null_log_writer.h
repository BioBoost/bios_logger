#pragma once

#include <string>
#include "../log_writer.h"

namespace BiosLogger {

  class NullLogWriter : public LogWriter {

    public:
      NullLogWriter(LogLevel level=logINFO)
        : LogWriter(level) { }

    public:
      virtual void write_message(std::string fullMessage) override { }

  };

};
