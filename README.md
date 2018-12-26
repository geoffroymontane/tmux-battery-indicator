# tmux-battery-indicator
An alternative to the official tmux-battery plugin, written mostly in C++ with a nice battery indicator, easy to customize.

### Compatibility
It works well with two power management tools :
	- upower (by default)
	- acpi (see "Use acpi" section)
Check if these softwares are available in your terminal.

### Screenshots
![1](img/1.png)<br>
High but discharging (- means discharging) <br>
![2](img/2.png)<br>
Low but charging (+ means charging) <br>
![3](img/3.png)<br><br>

### An example in tmux
![4](img/4.png)<br>

### Installation

Go to ~/.tmux/plugins/ or create the directories if they do not yet exist.

	cd ~/.tmux/plugins/

Clone the repository :

	git clone https://github.com/geoffroymontane/tmux-battery-indicator.git


Note : if you want to change the path, you just have to update battery.sh with the new value of "path" variable.

Execute install.sh (you need g++ to compile the software):
	
	cd tmux-battery-indicator
	chmod +x install.sh
	sudo install.sh

If ~/.tmux.conf does not exist, create it. You have to add the following line at the bottom :

	run-shell 'bash ~/.tmux/plugins/tmux-battery-indicator/battery.tmux'

Then, you just have to add #{battery} to you status bar. For instance, you can use :

	set -g status-right 'Datetime : %H:%M %d/%m Battery : #{battery}'

or just : 

	set -g status-right '#{battery}'

### Use acpi instead of upower

In order to use acpi instead of upower, take a look to battery.sh and edit it. All is explained.

### Customization/Changing colors

In order to customize this plugin, edit battery\_default.cpp and recompile by executing install.sh again.
