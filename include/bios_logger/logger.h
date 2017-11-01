#pragma once

#include <string>
#include <vector>
#include "log_writer.h"
#include "log_level.h"

namespace BiosLogger {

  #define DoLog Logger::get_instance()

  class Logger final {

    private:
      std::vector<LogWriter *> writers;

    public:
      static Logger& get_instance();

    private:
      Logger(void);   // Make constructor private
      ~Logger(void);

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

      // Dont forget to declare these two. You want to make sure they
      // are unacceptable otherwise you may accidentally get copies of
      // your singleton appearing.
    public:
      Logger(Logger const&)          = delete;
      void operator=(Logger const&)  = delete;
      // Note: Scott Meyers mentions in his Effective Modern
      //       C++ book, that deleted functions should generally
      //       be public as it results in better error messages
      //       due to the compilers behavior to check accessibility
      //       before deleted status

  };
};
