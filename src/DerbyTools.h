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

#ifndef DERBYTOOLS_H
#define DERBYTOOLS_H

#include <gtkmm.h>
#include <map>
#include <boost/regex.hpp>
#include "DerbyModel.h"
#include "InputReader.h"
#include "Team.h"

class DerbyTools : public Gtk::Window {
	public:
	DerbyTools();
	~DerbyTools();
	void addTeam(Glib::ustring);
	void readInput(Glib::ustring);

	protected:
	std::map<Glib::ustring,Team*> teams;
	std::map<Glib::ustring,Team*> allTools;
	Team* currentTeam;
	const boost::regex teamRegex;
	const boost::regex endRegex;
	Gtk::ScrolledWindow scroll1;
	Gtk::TreeView tv;
	Glib::RefPtr<Gtk::TreeStore> rowStore;
	DerbyModel db;
	InputReader* input;
};

#endif // DERBYTOOLS_H
