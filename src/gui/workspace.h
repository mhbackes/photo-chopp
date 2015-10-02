/*
 * workspace.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_GUI_WORKSPACE_H_
#define PHOTO_CHOPPE_SRC_GUI_WORKSPACE_H_

#include "imagespace.h"
#include "toolbox.h"

namespace graphicUserInterface {

class Workspace: public Gtk::Box {
public:
	Workspace();
	virtual ~Workspace();

	ImageSpace& getImageSpace();

private:
	ImageSpace imageSpace_;
	ToolBox toolBox_;

	static const guint BORDER_WIDTH;
};

} /* namespace gui */

namespace gui = graphicUserInterface;

#endif /* WORKSPACE_H_ */
