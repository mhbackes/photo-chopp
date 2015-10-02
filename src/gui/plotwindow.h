/*
 * plotwindow.h
 *
 *  Created on: 23/09/2015
 *      Author: mhbackes
 */

#ifndef GUI_PLOTWINDOW_H_
#define GUI_PLOTWINDOW_H_

#include <gtkmm/window.h>
#include <vector>

#include "../gui/plotarea.h"

namespace graphicUserInterface {

class PlotWindow : public Gtk::Window {
public:
	PlotWindow(const std::string title, const std::vector<int>& data);
	virtual ~PlotWindow();

	void setData(const std::vector<int>& data);

private:

	static const int BORDER_WIDTH;

	gui::PlotArea plotArea_;
};

} /* namespace graphicUserInterface */

namespace gui = graphicUserInterface;

#endif /* GUI_PLOTWINDOW_H_ */
