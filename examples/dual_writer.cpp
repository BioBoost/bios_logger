#include <bios_logger/bios_logger.h>

#include <unistd.h>

using namespace BiosLogger;

int main(void)
{
    DoLog.register_log_writer(new TerminalLogWriter(logINFO));
    DoLog.register_log_writer(new TerminalLogWriter(logERROR));
    DoLog.error("Its happening! Skynet has awoken.");
    sleep(1);
    DoLog.info("Never mind, it was a pokemon.");

    return 0;
}
