#!/usr/bin/env bash

#   An alternative to the official tmux-battery plugin
#   written mostly in C++ with a nice gauge
#
#   Copyright (C) 2018/2019 Geoffroy Montane 
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.


# In order to install it, see README.md.
# In order to change colors or other things, see battery_default.cpp.
# In order to use acpi instead of upower, see the lines below.

path=~/.tmux/plugins/battery

# Comment the following line in order to use acpi instead of upower 
$path/battery.out "$(upower -i $(upower -e | grep 'BAT') | grep -E 'state|to\ full|percentage')"

# Uncomment the following line in order to use acpi instead of upower 
#$path/battery.out "$(acpi)"
