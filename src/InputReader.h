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
