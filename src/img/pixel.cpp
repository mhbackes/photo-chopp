/*
 * Pixel.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "pixel.h"

const double img::Pixel::R_LUMINANCE = 0.299;
const double img::Pixel::G_LUMINANCE = 0.587;
const double img::Pixel::B_LUMINANCE = 0.114;

const int img::Pixel::COLOR_MIN = 0;
const int img::Pixel::COLOR_MAX = 255;
const int img::Pixel::NUM_COLOR = 256;

const int img::Pixel::R_OFFSET = 0;
const int img::Pixel::G_OFFSET = 1;
const int img::Pixel::B_OFFSET = 2;
const int img::Pixel::SIZE_BYTES = 3;

img::Pixel::Pixel(guint8* pixel) :
		R(pixel[R_OFFSET]), G(pixel[G_OFFSET]), B(pixel[B_OFFSET]) {
	pixel_ = pixel;
}

img::Pixel::~Pixel() {
}

img::Pixel& img::Pixel::operator =(const img::Pixel& p) {
	memcpy(pixel_, p.pixel_, SIZE_BYTES);
	return *this;
}

void img::Pixel::linearTransformation(double a, double b) {
	double ltR = a * R + b;
	double ltG = a * G + b;
	double ltB = a * B + b;
	R = CLAMP(ltR, COLOR_MIN, COLOR_MAX);
	G = CLAMP(ltG, COLOR_MIN, COLOR_MAX);
	B = CLAMP(ltB, COLOR_MIN, COLOR_MAX);
}

void img::Pixel::grayScale() {
	R = G = B = luminance();
}

void img::Pixel::setColor(guint8 color) {
	R = G = B = color;
}

void img::Pixel::grayQuantization(int numShades) {
	if (numShades == 1)
		R = G = B = 0;
	else {
		int color = luminance() * numShades / NUM_COLOR * NUM_COLOR
				/ (numShades - 1);
		R = G = B = CLAMP(color, COLOR_MIN, COLOR_MAX);
	}
}

guint8 img::Pixel::luminance() const {
	if (R == G && R == B)
		return R;
	int l = round(R * R_LUMINANCE + G * G_LUMINANCE + B * B_LUMINANCE);
	return CLAMP(l, COLOR_MIN, COLOR_MAX);
}
