/*
 * imagespace.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "imagespace.h"

const guint gui::ImageSpace::BORDER_WIDTH = 5;

gui::ImageSpace::ImageSpace()  {
	set_border_width(BORDER_WIDTH);
	originalImage_.set_label("Original Image");
	currentImage_.set_label("Current Image");
	pack1(originalImage_,false, false);
	pack2(currentImage_, false, false);
	show_all_children();
}

gui::ImageSpace::~ImageSpace() {
	// TODO Auto-generated destructor stub
}

Gtk::Image& gui::ImageSpace::getOriginalImage() {
	return originalImage_.getImage();
}

Gtk::Image& gui::ImageSpace::getCurrentImage() {
	return currentImage_.getImage();
}

void gui::ImageSpace::loadImage(const std::string fileName) {
	Gtk::Image& oriImage = originalImage_.getImage();
	Gtk::Image& curImage = currentImage_.getImage();
	oriImage.set(fileName);
	curImage.set(oriImage.get_pixbuf()->copy());
}

void gui::ImageSpace::saveImage(const std::string& fileName, const std::string& extension) {
	currentImage_.getImage().get_pixbuf()->save(fileName, extension);
}

void graphicUserInterface::ImageSpace::clearImage() {
	originalImage_.getImage().clear();
	currentImage_.getImage().clear();
}
