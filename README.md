# Zynskey's DDC Control PaneL
This is a basic gui application for controlling various display settings (like brightness, colour, VGA sync, etc) on DDC/CI compatible monitors. It's meant to be a bit more user-friendly alternative to [ddcui](https://github.com/rockowitz/ddcui).

To contribute: If your monitor exposes additional controls you would like to see in this program, check their feature id in ddcui and drop an issue. ^w^

Dependencies:
- Qt 5 or 6
- ddcutil

Building:
```
mkdir build
cd build
qmake
make
sudo make install
```
If your monitor supports DDC/CI but doesn't show up in the dropdown list, make sure that:
- It's not disabled in the monitor's menu
- The `i2c-dev` kernel module is loaded
