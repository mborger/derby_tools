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

#ifndef TEAM_H
#define TEAM_H

#include <gtkmm.h>
#include <map>
#include "DerbyModel.h"

class Team {
	public:
	Glib::ustring name;

	Team(Glib::ustring,Glib::RefPtr<Gtk::TreeStore>,std::map<Glib::ustring,Team*>*);
	void checkInOutTool(Glib::ustring);

	protected:
	Gtk::TreeModel::iterator rowIterator;
	std::map<Glib::ustring,Gtk::TreeModel::iterator> tools;
	std::map<Glib::ustring,Team*>* allTools;
	Glib::RefPtr<Gtk::TreeStore> rowStore;
	DerbyModel db;

	void addTool(Glib::ustring);
	void removeTool(Glib::ustring);
};

#endif // TEAM_H
