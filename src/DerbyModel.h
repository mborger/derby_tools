#ifndef DERBYMODEL_H
#define DERBYMODEL_H

#include <gtkmm.h>

class DerbyModel : public Gtk::TreeModelColumnRecord {
	public:
	DerbyModel() {
		add(teamName);
		add(toolName);
	}

	Gtk::TreeModelColumn<Glib::ustring> teamName;
	Gtk::TreeModelColumn<Glib::ustring> toolName;
};

#endif // DERBYMODEL_H
