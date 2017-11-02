# Bios Logger


## Example

```C++
#include "../include/bios_logger/logger.h"
#include "../include/bios_logger/writers/terminal_log_writer.h"

#include <unistd.h>

using namespace BiosLogger;

Check out the examples subdir.

Making the examples:

```shell
make examples
```

You can check your dynamic loaded libraries for the executable:

```shell
ldd <executable>
linux-vdso.so.1 =>  (0x00007fff175f8000)
libbioslogger.so.1 => /usr/local/lib/libbioslogger.so.1 (0x00007fe706ab4000)
libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fe706732000)
libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fe70651c000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fe706152000)
libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fe705e49000)
/lib64/ld-linux-x86-64.so.2 (0x00007fe706d17000)
```

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
sudo make install
```
