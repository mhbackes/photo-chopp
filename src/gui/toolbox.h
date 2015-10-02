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

#include "plotwindow.h"

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
	void onHistogramClicked();
	void onBrightnessClicked();
	void onContrastClicked();
	void onNegativeClicked();
	void onEqualizeClicked();

	void addAll();
	void connectAll();
	void initButtons();
	void enableButtons(bool enabled = true);

	Gtk::ButtonBox buttonBox_;
	Gtk::Button copy_;
	Gtk::Button hFlip_;
	Gtk::Button vFlip_;
	Gtk::Button grayScale_;
	Gtk::Frame quantFrame_;
	Gtk::VBox quantBox_;
	Gtk::SpinButton quantValue_;
	Gtk::Button quantization_;
	Gtk::Frame brightFrame_;
	Gtk::VBox brightBox_;
	Gtk::SpinButton brightValue_;
	Gtk::Button brightness_;
	Gtk::Frame contFrame_;
	Gtk::VBox contBox_;
	Gtk::SpinButton contValue_;
	Gtk::Button contrast_;
	Gtk::Button negative_;
	Gtk::Button equalize_;
	Gtk::Button histogram_;

	PlotWindow* histogramWindow_;
	PlotWindow* cumHistogramWindow_;

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
	static const Glib::ustring HISTOGRAM_LABEL;
	static const Glib::ustring CUMULATIVE_HISTOGRAM_LABEL;
	static const Glib::ustring BRIGHTNESS_LABEL;
	static const Glib::ustring CONTRAST_LABEL;
	static const Glib::ustring NEGATIVE_LABEL;
	static const Glib::ustring EQUALIZE_LABEL;
};

} /* namespace graphicUserInterface */

namespace gui = graphicUserInterface;

#endif /* GUI_TOOLS_H_ */
