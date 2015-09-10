/*
 * tools.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_GUI_TOOLBOX_H_
#define PHOTO_CHOPPE_SRC_GUI_TOOLBOX_H_

#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/frame.h>
#include <gtkmm/image.h>
#include <gtkmm/spinbutton.h>

namespace graphicUserInterface {

class ToolBox: public Gtk::Frame {
public:
	ToolBox(const Gtk::Image& original, Gtk::Image& current);
	virtual ~ToolBox();

private:
	void onCopyClicked();
	void onHFlipClicked();
	void onVFlipClicked();
	void onGrayScaleClicked();
	void onQuantizationClicked();

	void addAll();
	void connectAll();

	Gtk::ButtonBox buttonBox_;
	Gtk::Button copy_;
	Gtk::Button hFlip_;
	Gtk::Button vFlip_;
	Gtk::Button grayScale_;
	Gtk::SpinButton quantValue_;
	Gtk::Button quantization_;

	const Gtk::Image& imageOriginal_;
	Gtk::Image& imageCurrent_;

	static const guint BORDER_WIDTH;
	static const guint BOX_BORDER_WIDTH;

	static const Glib::ustring FRAME_LABEL;
	static const Glib::ustring COPY_LABEL;
	static const Glib::ustring HFLIP_LABEL;
	static const Glib::ustring VFLIP_LABEL;
	static const Glib::ustring GRAYSCALE_LABEL;
	static const Glib::ustring QUANTIZATION_LABEL;
};

} /* namespace graphicUserInterface */

namespace gui = graphicUserInterface;

#endif /* GUI_TOOLS_H_ */
