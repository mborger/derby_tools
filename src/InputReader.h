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

#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <linux/input.h>
#include <iostream>
#include <fstream>
#include <map>
#include <gtkmm.h>

using namespace std;

class InputReader {
	private:
	filebuf file;
	istream  is;
	struct input_event ev;
	Glib::Thread* thread;
	bool thread_running;
	bool stop_requested;
	stringstream buffer;
	map<int,char> charCodes;

	void read();
	void buildBuffer(int);
	void buildCharCodes();

	public:
	sigc::signal<void, string> sig_input;

	InputReader(string);
	~InputReader();
	void start();
};

#endif // INPUTREADER_H
