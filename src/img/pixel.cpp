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

img::Pixel::Pixel(guint8* pixel) : R(pixel[R_OFFSET]), G(pixel[G_OFFSET]), B(pixel[B_OFFSET]) {
	pixel_ = pixel;
}

img::Pixel::~Pixel() {
	// TODO Auto-generated destructor stub
}

img::Pixel& image::Pixel::operator =(const img::Pixel& p) {
	memcpy(pixel_, p.pixel_, SIZE_BYTES);
	return *this;
}

void img::Pixel::linearTransformation(double a, double b) {
	int ltR = a * R + b;
	int ltG = a * G + b;
	int ltB = a * B + b;
	R = CLAMP(ltR, COLOR_MIN, COLOR_MAX);
	G = CLAMP(ltG, COLOR_MIN, COLOR_MAX);
	B = CLAMP(ltB, COLOR_MIN, COLOR_MAX);
}

void img::Pixel::grayScale() {
	int luminance = R * R_LUMINANCE + G * G_LUMINANCE + B * B_LUMINANCE;
	R = G = B = CLAMP(luminance, COLOR_MIN, COLOR_MAX);
}

void image::Pixel::grayQuantization(int numShades) {
	grayScale();
	if (numShades == 1)
		R = G = B = 0;
	else {
		int color = R * numShades / NUM_COLOR * NUM_COLOR / (numShades - 1);
		R = G = B = CLAMP(color, COLOR_MIN, COLOR_MAX);
	}
}
