/*
 * menu.h
 *
 *  Created on: 07/09/2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_GUI_MENU_H_
#define PHOTO_CHOPPE_SRC_GUI_MENU_H_

#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/imagemenuitem.h>

#include "imagespace.h"

namespace graphicUserInterface {

class Menu: public Gtk::MenuBar {
public:
	Menu(ImageSpace& imageSpace);
	virtual ~Menu();

private:
	Gtk::MenuItem file_;
	Gtk::Menu fileMenu_;
	Gtk::ImageMenuItem fileOpen_;
	Gtk::ImageMenuItem fileSave_;
	Gtk::ImageMenuItem fileClose_;
	Gtk::ImageMenuItem fileQuit_;
	ImageSpace& imageSpace_;

	void onOpenClicked();
	void onSaveClicked();
	void onCloseClicked();
};

} /* namespace graphicUserInterface */

namespace gui = graphicUserInterface;

#endif /* PHOTO_CHOPPE_SRC_GUI_MENU_H_ */
