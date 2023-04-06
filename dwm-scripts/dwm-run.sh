#!/bin/sh

pasystray &
~/.local/share/JetBrains/Toolbox/bin/jetbrains-toolbox --minimize &
clipit &
blueman-applet &
nm-applet &
flameshot &
solaar -w hide &
/usr/lib/kdeconnectd &
picom &
dwmblocks &
# My personal screen layout
xrandr --output DP-0 --off --output DP-1 --off --output DP-2 --off --output DP-3 --off --output HDMI-0 --off --output HDMI-1 --mode 3440x1440 --rate 60.00 --pos 4480x0 --rotate normal --output HDMI-2 --mode 1920x1080 --rate 75.00 --pos 0x180 --rotate normal --output DP-4 --primary --mode 2560x1440 --rate 240.00 --pos 1920x0 --rotate normal --output DP-5 --off &
feh --bg-scale ~/Pictures/Wallpapers/1.png ~/Pictures/Wallpapers/2.jpg ~/Pictures/Wallpapers/3.jpg &

while type dwm >/dev/null; do dwm && continue || break; done
# dwm