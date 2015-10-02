/*
 * menu.cpp
 *
 *  Created on: 07/09/2015
 *      Author: mhbackes
 */

#include "menu.h"

#include <gtkmm/stock.h>
#include <gtkmm/main.h>
#include <gtkmm/filechooserdialog.h>

#include "../util/string.h"

gui::Menu::Menu(ImageSpace& imageSpace) :
		file_("File"), fileOpen_(Gtk::Stock::OPEN), fileSave_(Gtk::Stock::SAVE), fileClose_(
				Gtk::Stock::CLOSE), fileQuit_(Gtk::Stock::QUIT), imageSpace_(
				imageSpace) {
	append(file_);
	file_.set_submenu(fileMenu_);
	fileMenu_.append(fileOpen_);
	fileOpen_.signal_activate().connect(
			sigc::mem_fun(*this, &gui::Menu::onOpenClicked));
	fileMenu_.append(fileSave_);
	fileSave_.signal_activate().connect(
			sigc::mem_fun(*this, &gui::Menu::onSaveClicked));
	fileMenu_.append(fileClose_);
	fileClose_.signal_activate().connect(
			sigc::mem_fun(*this, &gui::Menu::onCloseClicked));
	fileMenu_.append(fileQuit_);
	fileQuit_.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
	show_all_children();
}

gui::Menu::~Menu() {
}

void gui::Menu::onOpenClicked() {
	Gtk::FileChooserDialog dialog("Open File", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("Open", Gtk::RESPONSE_OK);
	int result = dialog.run();
	if (result == Gtk::RESPONSE_OK) {
		std::string fileName = dialog.get_filename();
		imageSpace_.loadImage(fileName);
	}
}

void gui::Menu::onSaveClicked() {
	if (imageSpace_.getCurrentImage().get_storage_type() == Gtk::IMAGE_EMPTY)
		return;
	Gtk::FileChooserDialog dialog("Open File", Gtk::FILE_CHOOSER_ACTION_SAVE);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("Save", Gtk::RESPONSE_OK);
	int result = dialog.run();
	if (result == Gtk::RESPONSE_OK) {
		std::string fileName = dialog.get_filename();
		std::string extension = util::String::getExtension(fileName);
		if (extension == "png" || extension == "jpeg" || extension == "ico"
				|| extension == "bmp")
			imageSpace_.saveImage(fileName, extension);
		else
			imageSpace_.saveImage(fileName, "jpeg");
	}
}

void gui::Menu::onCloseClicked() {
	imageSpace_.clearImage();
}

