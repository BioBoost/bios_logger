See https://github.com/mrtazz/restclient-cpp

## Dependencies

```shell
sudo apt-get install libcurl4-gnutls-dev
```

## Install

```shell
sudo su
cd /usr/local/src
git clone https://github.com/mrtazz/restclient-cpp.git
cd restclient-cpp
./autogen.sh
./configure
make install
```

Checkout `ls /usr/local/lib`. The lib files should be there.
