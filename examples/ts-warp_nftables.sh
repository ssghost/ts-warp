#!/bin/sh

# ---------------------------------------------------------------------------- #
# TS-Warp - NFTABLES configuration for Linux example                           #
# ---------------------------------------------------------------------------- #

nft add chain ip nat SOCKS

# Exclude SOCKS servers
nft add rule ip nat SOCKS ip daddr 10.0.12.1 counter return
nft add rule ip nat SOCKS ip daddr 192.168.1.237 counter return
nft add rule ip nat SOCKS ip daddr 123.45.1.11 counter return

# Destination network/address definitions
nft add rule ip nat SOCKS ip protocol tcp ip daddr 10.0.0.0/16 counter redirect to :10800
nft add rule ip nat SOCKS ip protocol tcp ip daddr 192.168.1.0/24 counter redirect to :10800
nft add rule ip nat SOCKS ip protocol tcp ip daddr 192.168.3.0/24 counter redirect to :10800
nft add rule ip nat SOCKS ip protocol tcp ip daddr 123.45.123.0/24 counter redirect to :10800
nft add rule ip nat SOCKS ip protocol tcp ip daddr 123.45.234.96/24 counter redirect to :10800

# NB! User 'frodo' is a process owner username of the applictions to redirect to
# SOCKS servers. Change it to your username on localhost.
nft add rule ip nat OUTPUT ip protocol tcp skuid frodo counter jump SOCKS