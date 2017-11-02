# Bios Logger


## Example

```C++
#include "../include/bios_logger/logger.h"
#include "../include/bios_logger/writers/terminal_log_writer.h"

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
```

Example compile: `g++ -std=c++11 main.cpp -lbioslogger`

## Dependencies

None for the moment

## Compilation and installation

Just do the make

```shell
sudo su
cd /usr/local/src
git clone https://github.com/BioBoost/bios_logger.git
cd bios_logger
make
cp -r include/bios_logger /usr/local/include
cp bin/bioslogger.so.1.0.0 /usr/local/lib
ln -s /usr/local/lib/bioslogger.so.1.0.0 /usr/local/lib/bioslogger.so
ln -s /usr/local/lib/bioslogger.so.1.0.0 /usr/local/lib/bioslogger.so.1
ldconfig
```
