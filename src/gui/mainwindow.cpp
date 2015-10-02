/*
 * MainWindow.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "mainwindow.h"

const guint gui::MainWindow::BORDER_WIDTH = 0;

gui::MainWindow::MainWindow() :
		workspace_(), menu_(workspace_.getImageSpace()) {
	maximize();
	set_border_width(BORDER_WIDTH);
	add(layout_);
	layout_.pack_start(menu_, Gtk::PACK_SHRINK);
	layout_.pack_end(workspace_);

	show_all_children();
}

gui::MainWindow::~MainWindow() {
}

