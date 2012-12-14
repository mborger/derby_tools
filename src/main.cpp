#include <gtkmm.h>
#include "DerbyTools.h"
#include "InputReader.h"

int main(int argc, char* argv[]) {
	Glib::thread_init();

	Gtk::Main kit(argc, argv);

	DerbyTools app;

	Gtk::Main::run(app);

	return EXIT_SUCCESS;
}
