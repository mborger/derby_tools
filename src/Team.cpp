/*
 * Copyright 2012 Matthew Borger
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
