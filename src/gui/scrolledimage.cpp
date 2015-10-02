/*
 * scrolledimage.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "scrolledimage.h"

const guint gui::ScrolledImage::BORDER_WIDTH = 0;

gui::ScrolledImage::ScrolledImage() {
	set_border_width(BORDER_WIDTH);
	add(scrollWindow_);
	scrollWindow_.add(image_);
	show_all_children();
}

gui::ScrolledImage::~ScrolledImage() {
}

Gtk::Image& gui::ScrolledImage::getImage() {
	return image_;
}
