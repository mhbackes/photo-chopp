/*
 * tools.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "toolbox.h"
#include <iostream>
#include "../img/pixmat.h"

const guint gui::ToolBox::BORDER_WIDTH = 5;
const guint gui::ToolBox::BOX_BORDER_WIDTH = 5;

const Glib::ustring gui::ToolBox::FRAME_LABEL = "Toolbox";
const Glib::ustring gui::ToolBox::COPY_LABEL = "Copy";
const Glib::ustring gui::ToolBox::HFLIP_LABEL = "Horizontal Flip";
const Glib::ustring gui::ToolBox::VFLIP_LABEL = "Vertical Flip";
const Glib::ustring gui::ToolBox::GRAYSCALE_LABEL = "Gray Scale";
const Glib::ustring gui::ToolBox::QUANTIZATION_LABEL = "Quantization";

gui::ToolBox::ToolBox(const Gtk::Image& original, Gtk::Image& current) :
		Gtk::Frame(FRAME_LABEL), buttonBox_(Gtk::ORIENTATION_VERTICAL), copy_(
				COPY_LABEL), hFlip_(HFLIP_LABEL), vFlip_(VFLIP_LABEL), grayScale_(
				GRAYSCALE_LABEL), quantization_(QUANTIZATION_LABEL), imageOriginal_(
				original), imageCurrent_(current) {
	set_border_width(BORDER_WIDTH);
	connectAll();
	addAll();
	show_all_children();
}

void gui::ToolBox::connectAll() {
	copy_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onCopyClicked));
	hFlip_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onHFlipClicked));
	vFlip_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onVFlipClicked));
	grayScale_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onGrayScaleClicked));
	quantization_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onQuantizationClicked));
}

void gui::ToolBox::addAll() {
	buttonBox_.set_border_width(BOX_BORDER_WIDTH);
	buttonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
	buttonBox_.add(copy_);
	buttonBox_.add(hFlip_);
	buttonBox_.add(vFlip_);
	buttonBox_.add(grayScale_);
	quantValue_.set_adjustment(Gtk::Adjustment::create(1.0, 1.0, 256.0));
	buttonBox_.add(quantValue_);
	buttonBox_.add(quantization_);
	add(buttonBox_);
}

gui::ToolBox::~ToolBox() {
	// TODO Auto-generated destructor stub
}

void gui::ToolBox::onCopyClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<const Gdk::Pixbuf> pixbuf = imageOriginal_.get_pixbuf();
	imageCurrent_.set(pixbuf->copy());
}

void gui::ToolBox::onHFlipClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.horizontalFlip();
	imageCurrent_.set(pixbuf);
}

void gui::ToolBox::onVFlipClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.verticalFlip();
	imageCurrent_.set(pixbuf);
}

void gui::ToolBox::onGrayScaleClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.grayScale();
	imageCurrent_.set(pixbuf);
}

void gui::ToolBox::onQuantizationClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.grayQuantization(quantValue_.get_value_as_int());
	imageCurrent_.set(pixbuf);
}


