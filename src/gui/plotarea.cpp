/*
 * plotarea.cpp
 *
 *  Created on: 23/09/2015
 *      Author: mhbackes
 */

#include "plotarea.h"

#include <gdkmm/rgba.h>

gui::PlotArea::PlotArea(const std::vector<int>& data) {
	set_size_request(256, 256);
	Gdk::RGBA backgroundColor;
	backgroundColor.set_rgba(1.0, 1.0, 1.0);
	override_background_color(backgroundColor);
	data_ = data;
}

gui::PlotArea::~PlotArea() {
}

bool gui::PlotArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	Gtk::Allocation allocation = get_allocation();
	const int maxHeight = maxValue();
	const int height = allocation.get_height();
	const double scale = (double) 256 / maxHeight;
	cr->set_line_width(1.0);
	cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->set_antialias(Cairo::ANTIALIAS_NONE);
	for (std::size_t i = 0; i < data_.size(); ++i) {
		cr->move_to(i + 1, height);
		cr->line_to(i + 1, height - data_[i] * scale);
	}
	cr->stroke();
	return true;
}

int gui::PlotArea::maxValue() {
	int maxVal = 0;
	for (std::size_t i = 0; i < data_.size(); i++) {
		if (maxVal < data_[i]) {
			maxVal = data_[i];
		}
	}
	return maxVal;
}

void gui::PlotArea::setData(const std::vector<int>& data) {
	data_ = data;
	queue_draw();
}
