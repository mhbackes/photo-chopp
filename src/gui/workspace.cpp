/*
 * workspace.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "workspace.h"

const guint gui::Workspace::BORDER_WIDTH = 5;

gui::Workspace::Workspace() :
		imageSpace_(), toolBox_(imageSpace_.getOriginalImage(),
				imageSpace_.getCurrentImage()) {
	set_border_width(BORDER_WIDTH);
	pack_start(imageSpace_, true, true);
	pack_end(toolBox_, false, false);
	show_all_children();
}

gui::Workspace::~Workspace() {
	// TODO Auto-generated destructor stub
}

gui::ImageSpace& gui::Workspace::getImageSpace() {
	return imageSpace_;
}
