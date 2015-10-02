/*
 * PixMat.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_IMG_PIXMAT_H_
#define PHOTO_CHOPPE_SRC_IMG_PIXMAT_H_

#include <gdkmm/pixbuf.h>
#include <glibmm/refptr.h>
#include <vector>

#include "pixel.h"

namespace image {

class PixMat {
public:
	PixMat(Glib::RefPtr<Gdk::Pixbuf> pixbuf);
	virtual ~PixMat();

	int n_channels() const;
	int width() const;
	int height() const;
	int rowstride() const;
	guint size() const;

	Pixel operator[](int n) const;
	Pixel at(int x, int y) const;
	guint8* row_ptr(int y);

	void linearTransformation(double a, double b);
	void grayScale();
	void horizontalFlip();
	void verticalFlip();
	void grayQuantization(int numShades);
	void histogram(std::vector<int>& result) const;
	void cumulativeHistogram(std::vector<int>& histogram,
			std::vector<int>& comHistogram) const;
	void histogramEqualization();

private:
	int n_channels_, width_, height_, rowstride_;
	guint8* pixels_;
};

} /* namespace image */

namespace img = image;

#endif /* PHOTO_CHOPPE_SRC_IMG_PIXMAT_H_ */
