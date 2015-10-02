/*
 * plotarea.h
 *
 *  Created on: 23/09/2015
 *      Author: mhbackes
 */

#ifndef GUI_PLOTAREA_H_
#define GUI_PLOTAREA_H_

#include <vector>
#include <gtkmm/drawingarea.h>

namespace graphicUserInterface {

class PlotArea: public Gtk::DrawingArea {
public:
	PlotArea(const std::vector<int>& data);
	virtual ~PlotArea();
	void setData(const std::vector<int>& data);

private:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	int maxValue();

	std::vector<int> data_;
};

} /* namespace graphicUserInterface */

namespace gui = graphicUserInterface;

#endif /* GUI_PLOTAREA_H_ */
