#include <bios_logger/logger.h>
#include <bios_logger/writers/terminal_log_writer.h>
#include <bios_logger/formatters/json_log_formatter.h>

#include <unistd.h>

using namespace BiosLogger;

int main(void)
{
  TerminalLogWriter * jsonTerminalLogger = new TerminalLogWriter(logINFO);
  jsonTerminalLogger->register_log_formatter(new JsonLogFormatter());

  DoLog.register_log_writer(jsonTerminalLogger);
  DoLog.error("Its happening! Skynet has awoken.");
  sleep(1);
  DoLog.info("Never mind, it was a pokemon.");

  return 0;
}
