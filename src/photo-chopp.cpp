/*
 ============================================================================
 Name        : photo-chopp.cpp
 Author      : mhbackes
 Version     :
 Copyright   : 
 Description : Hello World in gttkmm
 ============================================================================
 */

#include "gui/mainwindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
	auto app = Gtk::Application::create(argc, argv, "photo.chopp");
	gui::MainWindow mainWindow;
	return app->run(mainWindow);
}
