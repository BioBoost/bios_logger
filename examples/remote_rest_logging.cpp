#include <bios_logger/logger.h>
#include <bios_logger/writers/terminal_log_writer.h>
#include <bios_logger/writers/remote_rest_log_writer.h>

#include <unistd.h>

using namespace BiosLogger;

int main(void)
{
  DoLog.register_log_writer(new RemoteRestLogWriter("1234567l", "/messages.json", "localhost", 3000));
  DoLog.error("Its happening! Skynet has awoken.");
  sleep(1);
  DoLog.info("Never mind, it was a pokemon.");

  return 0;
}
