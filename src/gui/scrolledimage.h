/*
 * scrolledimage.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_GUI_SCROLLEDIMAGE_H_
#define PHOTO_CHOPPE_SRC_GUI_SCROLLEDIMAGE_H_

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/image.h>

namespace graphicUserInterface {

class ScrolledImage: public Gtk::Frame {
public:
	ScrolledImage();
	virtual ~ScrolledImage();

	Gtk::Image& getImage();

private:
	Gtk::ScrolledWindow scrollWindow_;
	Gtk::Image image_;

	static const guint BORDER_WIDTH;
};

} /* namespace gui */

namespace gui = graphicUserInterface;

#endif /* SCROLLEDIMAGE_H_ */
