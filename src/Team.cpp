#include "Team.h"

Team::Team(Glib::ustring name, Glib::RefPtr<Gtk::TreeStore> rowStore, std::map<Glib::ustring,Team*>* allTools) {
	this->name = name;
	this->rowStore = rowStore;
	this->allTools = allTools;
	rowIterator = rowStore->append();
	Gtk::TreeModel::Row row = *rowIterator;
	row[db.teamName] = this->name;
}

void
Team::addTool(Glib::ustring tool) {
	Gtk::TreeModel::Row teamRow = *rowIterator;
	Gtk::TreeModel::iterator toolIterator = rowStore->append(teamRow.children());
	tools[tool] = toolIterator;
	Gtk::TreeModel::Row toolRow = *toolIterator;
	toolRow[db.toolName] = tool;

	std::map<Glib::ustring,Team*>::iterator it;
	it = allTools->find(tool);
	if(it!=allTools->end())
		(it->second)->removeTool(tool);
	(*allTools)[tool] = this;

}

void
Team::removeTool(Glib::ustring tool) {
	Gtk::TreeModel::iterator toolIterator = tools[tool];
	rowStore->erase(toolIterator);
	tools.erase(tool);
	allTools->erase(tool);
}

void
Team::checkInOutTool(Glib::ustring tool) {
	std::map<Glib::ustring,Gtk::TreeModel::iterator>::iterator it;
	it = tools.find(tool);
	if(it==tools.end()) {
		addTool(tool);
	} else {
		removeTool(tool);
	}
}
