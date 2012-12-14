/*
** Copyright 2012 Matthew Borger
** 
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
** 
** http://www.apache.org/licenses/LICENSE-2.0
** 
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "InputReader.h"

InputReader::InputReader(string device) : file(), is(&file), thread_running(false), stop_requested(false), buffer(stringstream::out) {
	file.open(device.c_str(), ios::binary|ios::in);
	buildCharCodes();
}

InputReader::~InputReader() {
	std::cout << "InputReader destructor" << std::endl;

	stop_requested = true;

	if(thread_running)
		thread->join();
}

void
InputReader::start() {
	thread_running = true;
	thread = Glib::Thread::create(sigc::mem_fun(*this, &InputReader::read), true);
}

void
InputReader::read() {
	while(true) {
		is.read((char*)&ev, sizeof(struct input_event));

		if(ev.type == EV_KEY && ev.value == 1) {
			buildBuffer(ev.code);
		}

		if(stop_requested)
			return;
	}
}

void
InputReader::buildBuffer(int code) {
	map<int,char>::iterator it = charCodes.find(code);
	if(it!=charCodes.end()) {
		char letter = it->second;
		if(letter == ';') {
			sig_input.emit(buffer.str());
			buffer.str("");
		} else {
			buffer << letter;
		}
	}
}

void
InputReader::buildCharCodes() {
	charCodes[2] = '1';
	charCodes[3] = '2';
	charCodes[4] = '3';
	charCodes[5] = '4';
	charCodes[6] = '5';
	charCodes[7] = '6';
	charCodes[8] = '7';
	charCodes[9] = '8';
	charCodes[10] = '9';
	charCodes[11] = '0';
	charCodes[16] = 'q';
	charCodes[17] = 'w';
	charCodes[18] = 'e';
	charCodes[19] = 'r';
	charCodes[20] = 't';
	charCodes[21] = 'y';
	charCodes[22] = 'u';
	charCodes[23] = 'i';
	charCodes[24] = 'o';
	charCodes[25] = 'p';
	charCodes[30] = 'a';
	charCodes[31] = 's';
	charCodes[32] = 'd';
	charCodes[33] = 'f';
	charCodes[34] = 'g';
	charCodes[35] = 'h';
	charCodes[36] = 'j';
	charCodes[37] = 'k';
	charCodes[38] = 'l';
	charCodes[39] = ';';
	charCodes[44] = 'z';
	charCodes[45] = 'x';
	charCodes[46] = 'c';
	charCodes[47] = 'v';
	charCodes[48] = 'b';
	charCodes[49] = 'n';
	charCodes[50] = 'm';
	charCodes[57] = ' ';
}
