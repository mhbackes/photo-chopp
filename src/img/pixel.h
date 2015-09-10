/*
 * Pixel.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#ifndef PHOTO_CHOPPE_SRC_IMG_PIXEL_H_
#define PHOTO_CHOPPE_SRC_IMG_PIXEL_H_

#include <gdkmm/pixbuf.h>

namespace image {

class Pixel {
public:
	guint8 &R, &G, &B;

	Pixel(guint8* pixel);
	virtual ~Pixel();

	Pixel& operator=(const Pixel& p);

	void linearTransformation(double a, double b);
	void grayScale();
	void grayQuantization(int numShades);

	static const int SIZE_BYTES;

private:
	guint8* pixel_;

	static const double R_LUMINANCE;
	static const double G_LUMINANCE;
	static const double B_LUMINANCE;

	static const int COLOR_MIN;
	static const int COLOR_MAX;
	static const int NUM_COLOR;

	static const int R_OFFSET;
	static const int G_OFFSET;
	static const int B_OFFSET;
};

} /* namespace image */

namespace img = image;

#endif /* PHOTO_CHOPPE_SRC_IMG_PIXEL_H_ */
