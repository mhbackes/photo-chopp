/*
 * plotwindow.cpp
 *
 *  Created on: 23/09/2015
 *      Author: mhbackes
 */

#include "plotwindow.h"

const int gui::PlotWindow::BORDER_WIDTH = 5;

gui::PlotWindow::PlotWindow(const std::string title,
		const std::vector<int>& data) :
		plotArea_(data) {
	set_title(title);
	set_resizable(false);
	set_size_request(256 + BORDER_WIDTH, 256 + BORDER_WIDTH);
	set_border_width(BORDER_WIDTH);
	add(plotArea_);
	plotArea_.show();
}

gui::PlotWindow::~PlotWindow() {
}

void gui::PlotWindow::setData(const std::vector<int>& data) {
	plotArea_.setData(data);
}
