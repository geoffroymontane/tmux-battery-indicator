/*   An alternative to the official tmux-battery plugin
 *   written mostly in C++ with a nice gauge
 *
 *   Copyright (C) 2018/2019 Geoffroy Montane
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// In order to install it, see README.md.

// In order to change colors or other things, change the code below and
// recompile by using the "make" command in the current directory
// once you have finished.

// In order to use acpi instead of upower, see battery.sh.

#include <iostream>
#include <string>
#include <math.h>

using namespace std;



int main(int argc,char *argv[]){

	// Gauge length (count of chars)
	int bLen(6);

	// Path to the directory of this plugin
	string path(argv[0]);

	// Output from upower or acpi
	string cliOutput(argv[1]);

	/*
	COLORS - (Execute tmuxcolors.sh to see all colors available in your terminal.)
	*/

	// Color supposed to be red
	string colorR("colour1");

	// Color supposed to be green
	string colorG("colour2");

	// Color supposed to be yellow
	string colorY("colour3");

	// Background color
	string color("colour15");

	// Text color
	string colorTxt("colour16");

	// Critical threshold of battery in % : if less, the bar turns to yellow.
	int thresholdY(70);

	// Critical threshold of battery in % : if less, the bar turns to red.
	int thresholdR(30);


	/*
	PARSING
	*/
	int index(cliOutput.find("%"));

	string percentage;
	int percentage_;

	int progress(-1);
	string progress_("");
	string blank_("");

	char state('~');

	if(index==string::npos){
		cout << "?" << endl;
		return 0;
	}
	else{
		percentage=cliOutput.substr(index-3,3);
		percentage_=stoi(percentage);
		progress=roundf(stof(percentage)*bLen/100);
	}

	if(cliOutput.find("discharging")!=string::npos || cliOutput.find("Discharging")!=string::npos){
		state='-';
	}
	else if(cliOutput.find("charging")!=string::npos || cliOutput.find("Charging")!=string::npos){
		state='+';
	}


	for(int i=0;i<progress;i++){
		progress_=progress_+state;
		state=' ';
	}

	for(int i=0;i<bLen-progress;i++){
		blank_=blank_+state;
		state=' ';
	}

	/*
	Output
	*/
	string *gaugeColor(&colorG);
	if(percentage_<=thresholdY){
		gaugeColor=&colorY;
	}
	if(percentage_<=thresholdR){
		gaugeColor=&colorR;
	}

	if(progress!=bLen){
		cout << string("#[fg=")+colorTxt+string(",bg=")+*gaugeColor+string(",bold][")+progress_+string("#[bg=")+color+string(",bold]")+blank_+string("]#[fg=")+colorTxt+string(",bg=")+color+string(",bold]")+percentage+string("%") << endl;
	}
	else{
		cout << string("#[fg=")+colorTxt+string(",bg=")+colorG+string(",bold][")+progress_+string("]#[bg=")+color+string(",bold]#[fg=")+colorTxt+string(",bg=")+color+string(",bold]")+percentage+string("%") << endl;
	}


	return 0;
}
