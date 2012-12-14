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
