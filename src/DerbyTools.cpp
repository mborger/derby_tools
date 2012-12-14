#include "DerbyTools.h"

DerbyTools::DerbyTools() : teamRegex("^team .*"), endRegex("^end transaction$"), currentTeam(NULL) {
	set_title("Derby Tools");
	set_default_size(500,500);
	set_border_width(5);

	//Build ListStore
	rowStore = Gtk::TreeStore::create(db);
	tv.set_model(rowStore);

	//Setup TreeView
	tv.append_column("Team Name", db.teamName);
	tv.append_column("Tools Checked Out", db.toolName);

	addTeam("team 1");
	addTeam("team 2");
	addTeam("team 3");
	addTeam("team 4");
	addTeam("team 5");
	addTeam("team 6");
	addTeam("team 7");
	addTeam("team 8");
	addTeam("team 9");
	addTeam("team 10");
	addTeam("team 11");
	addTeam("team 12");
	addTeam("team 13");
	addTeam("team 14");
	addTeam("team 15");
	addTeam("team 16");
	addTeam("team 17");
	addTeam("team 18");
	addTeam("team 19");
	addTeam("team 20");
	addTeam("team 21");
	addTeam("team 22");
	addTeam("team 23");
	addTeam("team 24");
	addTeam("team 25");
	addTeam("team 26");
	addTeam("team 27");
	addTeam("team 28");
	addTeam("team 29");
	addTeam("team 30");

	scroll1.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
	add(scroll1);

	scroll1.add(tv);

	show_all_children();

	input = new InputReader("/dev/input/by-id/usb-ﾩSymbol_Technologies__Inc__2002_Symbol_Bar_Code_Scanner_S_N:565FEA89CA6F2246B49E66E83B659270_Rev:NBRMIAAB3-event-kbd");
	input->start();

	input->sig_input.connect(sigc::mem_fun(*this, &DerbyTools::readInput));
}

DerbyTools::~DerbyTools() {
	delete(input);
	input = 0;
}

void
DerbyTools::addTeam(Glib::ustring name) {
	Team* newTeam = new Team(name, rowStore, &allTools);
	teams[name] = newTeam;
}

void
DerbyTools::readInput(Glib::ustring input) {
	boost::cmatch match;
	if(boost::regex_match(input.c_str(), match, teamRegex)) {
		currentTeam = teams[input];
	} else if(boost::regex_match(input.c_str(), match, endRegex)) {
		currentTeam = NULL;
	} else { //assume tool
		if(currentTeam==NULL)
			return;
		else
			currentTeam->checkInOutTool(input);
	}
	tv.expand_all();
}
