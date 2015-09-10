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
#include <gtkmm/main.h>

int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);
  gui::MainWindow mainWindow;
  Gtk::Main::run(mainWindow);
  return 0;
}
