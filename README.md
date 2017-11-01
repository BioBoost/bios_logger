# Bios Logger


## Example

```C++
#include "lib/logger/logger.h"
#include "lib/logger/log_writers/terminal_logger.h"

int main(void)
{
    BiosLogger::Logger * logger = new BiosLogger::Logger();
    logger->register_log_writer(new BiosLogger::TerminalLogger());
    logger->info("Its happening! Skynet has awoken.");

    delete logger;

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
