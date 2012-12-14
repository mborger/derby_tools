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
