/*
 *
 *
 *  Created on: Sep 3, 2015
 *      Author: mhbackes
 */

#include "pixmat.h"

img::PixMat::PixMat(Glib::RefPtr<Gdk::Pixbuf> pixbuf) {
	n_channels_ = pixbuf->get_n_channels();
	width_ = pixbuf->get_width();
	height_ = pixbuf->get_height();
	rowstride_ = pixbuf->get_rowstride();
	pixels_ = pixbuf->get_pixels();
}

img::PixMat::~PixMat() {
	// TODO Auto-generated destructor stub
}

img::Pixel img::PixMat::operator [](int n) {
	return Pixel(pixels_ + n * n_channels_);
}

img::Pixel img::PixMat::at(int x, int y) {
	return Pixel(pixels_ + y * rowstride_ + x * n_channels_);
}

guint8* img::PixMat::row_ptr(int y) {
	return pixels_ + y * rowstride_;
}

int img::PixMat::n_channels() const {
	return n_channels_;
}

int img::PixMat::width() const {
	return width_;
}

int img::PixMat::height() const {
	return height_;
}

int img::PixMat::rowstride() const {
	return rowstride_;
}

guint image::PixMat::size() const {
	return width_ * height_;
}

void img::PixMat::linearTransformation(double a, double b) {
	for (guint i = 0; i < size(); i++) {
		operator[](i).grayScale();
	}
}

void image::PixMat::grayScale() {
	for (guint i = 0; i < size(); i++) {
		operator[](i).grayScale();
	}
}

void image::PixMat::horizontalFlip() {
	int lastCol = width_ - 1;
	int halfWidth = width_ / 2;
	guint8 tempPixel[Pixel::SIZE_BYTES];
	Pixel temp(tempPixel);
	for (int i = 0; i < halfWidth; i++) {
		for (int j = 0; j < height_; j++) {
			Pixel pixA = at(i, j);
			Pixel pixB = at(lastCol - i, j);
			temp = pixA;
			pixA = pixB;
			pixB = temp;
		}
	}
}

void image::PixMat::verticalFlip() {
	int lastRow = height_ - 1;
	guint8* temp = new guint8[rowstride_];
	for (int i = 0; i < height_ / 2; i++) {
		guint8* rowA = row_ptr(i);
		guint8* rowB = row_ptr(lastRow - i);
		memcpy(temp, rowA, rowstride_);
		memcpy(rowA, rowB, rowstride_);
		memcpy(rowB, temp, rowstride_);
	}
	delete[] temp;
}

void image::PixMat::grayQuantization(int numShades) {
	for (guint i = 0; i < size(); i++) {
		operator[](i).grayQuantization(numShades);
	}
}

std::vector<int> image::PixMat::grayFrequences() {
	grayScale();
	std::vector<int> freq(256);
	for (guint i = 0; i < size(); i++) {
		freq[operator[](i).R]++;
	}
	return freq;
}
