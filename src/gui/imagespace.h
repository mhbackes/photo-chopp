/*
 * imagespace.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_GUI_IMAGESPACE_H_
#define PHOTO_CHOPPE_SRC_GUI_IMAGESPACE_H_

#include <gtkmm/paned.h>

#include "scrolledimage.h"

namespace graphicUserInterface {

class ImageSpace: public Gtk::Paned {
public:
	ImageSpace();
	virtual ~ImageSpace();

	Gtk::Image& getOriginalImage();
	Gtk::Image& getCurrentImage();

	void loadImage(const std::string fileName);
	void saveImage(const std::string& fileName, const std::string& extension);
	void clearImage();

private:
	ScrolledImage originalImage_;
	ScrolledImage currentImage_;

	static const guint BORDER_WIDTH;
};

} /* namespace gui */

namespace gui = graphicUserInterface;

#endif /* PHOTO_CHOPPE_SRC_GUI_IMAGESPACE_H_ */
