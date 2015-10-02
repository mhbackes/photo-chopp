/*
 * MainWindow.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_GUI_MAINWINDOW_H_
#define PHOTO_CHOPPE_SRC_GUI_MAINWINDOW_H_

#include <gtkmm/window.h>

#include "workspace.h"
#include "menu.h"

namespace graphicUserInterface {

class MainWindow: public Gtk::Window {
public:
	MainWindow();
	virtual ~MainWindow();

private:
	Workspace workspace_;
	Gtk::Box layout_;
	Menu menu_;

	static const guint BORDER_WIDTH;
	
};

} /* namespace gui */

#endif /* MAINWINDOW_H_ */
