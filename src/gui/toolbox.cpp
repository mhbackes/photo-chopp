/*
 * tools.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "toolbox.h"
#include <iostream>
#include <limits>
#include "../img/pixmat.h"

const guint gui::ToolBox::BORDER_WIDTH = 5;
const guint gui::ToolBox::BOX_BORDER_WIDTH = 5;

const Glib::ustring gui::ToolBox::FRAME_LABEL = "Toolbox";
const Glib::ustring gui::ToolBox::COPY_LABEL = "Copy";
const Glib::ustring gui::ToolBox::HFLIP_LABEL = "Horizontal Flip";
const Glib::ustring gui::ToolBox::VFLIP_LABEL = "Vertical Flip";
const Glib::ustring gui::ToolBox::GRAYSCALE_LABEL = "Gray Scale";
const Glib::ustring gui::ToolBox::QUANTIZATION_LABEL = "Quantization";
const Glib::ustring gui::ToolBox::HISTOGRAM_LABEL = "Histogram";
const Glib::ustring gui::ToolBox::CUMULATIVE_HISTOGRAM_LABEL = "Cumulative Histogram";
const Glib::ustring gui::ToolBox::BRIGHTNESS_LABEL = "Brightness";
const Glib::ustring gui::ToolBox::CONTRAST_LABEL = "Contrast";
const Glib::ustring gui::ToolBox::NEGATIVE_LABEL = "Negative";
const Glib::ustring gui::ToolBox::EQUALIZE_LABEL = "Equalize";

gui::ToolBox::ToolBox(const Gtk::Image& original, Gtk::Image& current) :
		Gtk::Frame(FRAME_LABEL), buttonBox_(Gtk::ORIENTATION_VERTICAL), imageOriginal_(
				original), imageCurrent_(current) {
	set_border_width(BORDER_WIDTH);
	histogramWindow_ = nullptr;
	initButtons();
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
	brightness_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onBrightnessClicked));
	contrast_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onContrastClicked));
	negative_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onNegativeClicked));
	equalize_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onEqualizeClicked));
	histogram_.signal_clicked().connect(
			sigc::mem_fun(*this, &ToolBox::onHistogramClicked));
}

void gui::ToolBox::addAll() {
	buttonBox_.set_border_width(BOX_BORDER_WIDTH);
	buttonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
	buttonBox_.add(copy_);
	buttonBox_.add(hFlip_);
	buttonBox_.add(vFlip_);
	buttonBox_.add(grayScale_);
	quantBox_.add(quantValue_);
	quantBox_.add(quantization_);
	quantFrame_.add(quantBox_);
	buttonBox_.add(quantFrame_);
	brightBox_.add(brightValue_);
	brightBox_.add(brightness_);
	brightFrame_.add(brightBox_);
	buttonBox_.add(brightFrame_);
	contBox_.add(contValue_);
	contBox_.add(contrast_);
	contFrame_.add(contBox_);
	buttonBox_.add(contFrame_);
	buttonBox_.add(negative_);
	buttonBox_.add(equalize_);
	buttonBox_.add(histogram_);
	add(buttonBox_);
}

void gui::ToolBox::initButtons() {
	copy_.set_label(COPY_LABEL);
	hFlip_.set_label(HFLIP_LABEL);
	vFlip_.set_label(VFLIP_LABEL);
	grayScale_.set_label(GRAYSCALE_LABEL);
	quantFrame_.set_label(QUANTIZATION_LABEL);
	quantBox_.set_border_width(BORDER_WIDTH);
	quantValue_.set_adjustment(Gtk::Adjustment::create(1.0, 1.0, 256.0));
	quantization_.set_label(QUANTIZATION_LABEL);
	brightFrame_.set_label(BRIGHTNESS_LABEL);
	brightBox_.set_border_width(BORDER_WIDTH);
	brightValue_.set_adjustment(Gtk::Adjustment::create(0.0, -256.0, 256.0));
	brightness_.set_label(BRIGHTNESS_LABEL);
	contFrame_.set_label(CONTRAST_LABEL);
	contBox_.set_border_width(BORDER_WIDTH);
	contValue_.set_adjustment(
			Gtk::Adjustment::create(1.0, 0.001, 256.0, 0.001, 10.0, 0.0));
	contValue_.set_digits(3);
	contrast_.set_label(CONTRAST_LABEL);
	negative_.set_label(NEGATIVE_LABEL);
	equalize_.set_label(EQUALIZE_LABEL);
	histogram_.set_label(HISTOGRAM_LABEL);
}

gui::ToolBox::~ToolBox() {
	if (histogramWindow_)
		delete histogramWindow_;
	if (cumHistogramWindow_)
		delete cumHistogramWindow_;
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

void gui::ToolBox::onHistogramClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	std::vector<int> data, cumData;
	pixmat.cumulativeHistogram(data, cumData);
	if (!histogramWindow_) {
		histogramWindow_ = new PlotWindow(HISTOGRAM_LABEL, data);
		cumHistogramWindow_ = new PlotWindow(CUMULATIVE_HISTOGRAM_LABEL, cumData);
	} else {
		histogramWindow_->setData(data);
		cumHistogramWindow_->setData(cumData);
	}
	histogramWindow_->show();
	histogramWindow_->present();
	cumHistogramWindow_->show();
	cumHistogramWindow_->present();
}

void gui::ToolBox::onBrightnessClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.linearTransformation(1, brightValue_.get_value_as_int());
	imageCurrent_.set(pixbuf);
}

void gui::ToolBox::onContrastClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.linearTransformation(contValue_.get_value(), 0);
	imageCurrent_.set(pixbuf);
}

void gui::ToolBox::onNegativeClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.linearTransformation(-1, 255);
	imageCurrent_.set(pixbuf);
}

void gui::ToolBox::onEqualizeClicked() {
	if (imageCurrent_.get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf = imageCurrent_.get_pixbuf();
	img::PixMat pixmat(pixbuf);
	pixmat.histogramEqualization();
	std::vector<int> histogram;
	pixmat.histogram(histogram);
	imageCurrent_.set(pixbuf);
}
