/*
 * MainWindow.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "mainwindow.h"

const guint graphicUserInterface::MainWindow::BORDER_WIDTH = 5;

graphicUserInterface::MainWindow::MainWindow() :
		workspace_(), menu_(workspace_.getImageSpace()) {
	maximize();
	set_border_width(BORDER_WIDTH);
	add(layout_);
	layout_.pack_start(menu_, Gtk::PACK_SHRINK);
	layout_.pack_end(workspace_);

	show_all_children();
}

graphicUserInterface::MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}

