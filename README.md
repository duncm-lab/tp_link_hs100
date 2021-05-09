# TP-Link HS100 Smart Plug

## Building

cd ./src && make

## Usage

Send commands to a TP-LINK HS100 smart plug.

Invocation:
    ./hs100 -d device:port -c command

Short options:
    -h      show help
    -d      device ip and port (device:port)
    -c      command

Available sub-commands:

    info
    on
    off
    ledoff
    ledon
    cloudinfo
    wlanscan
    time
    schedule
    countdown
    antitheft
    reboot
    reset
    energy


## Credit

Credit for the encryption logic goes to "https://github.com/softScheck/tplink-smartplug"
