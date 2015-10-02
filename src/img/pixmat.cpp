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
}

img::Pixel img::PixMat::operator [](int n) const {
	return Pixel(pixels_ + n * n_channels_);
}

img::Pixel img::PixMat::at(int x, int y) const {
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

guint img::PixMat::size() const {
	return width_ * height_;
}

void img::PixMat::linearTransformation(double a, double b) {
	for (guint i = 0; i < size(); i++) {
		operator[](i).linearTransformation(a, b);
	}
}

void img::PixMat::grayScale() {
	for (guint i = 0; i < size(); i++) {
		operator[](i).grayScale();
	}
}

void img::PixMat::horizontalFlip() {
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

void img::PixMat::verticalFlip() {
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

void img::PixMat::grayQuantization(int numShades) {
	for (guint i = 0; i < size(); i++) {
		operator[](i).grayQuantization(numShades);
	}
}

void img::PixMat::histogram(std::vector<int>& result) const {
	result.resize(Pixel::NUM_COLOR);
	for (std::size_t i = 0; i < size(); i++) {
		const Pixel p = operator[](i);
		result[p.luminance()]++;
	}
}

void img::PixMat::cumulativeHistogram(std::vector<int>& histogram,
		std::vector<int>& cumHistogram) const {
	this->histogram(histogram);
	cumHistogram.resize(Pixel::NUM_COLOR);
	cumHistogram[0] = histogram[0];
	for (int i = 1; i < Pixel::NUM_COLOR; i++) {
		cumHistogram[i] = cumHistogram[i - 1] + histogram[i];
	}
}

void img::PixMat::histogramEqualization() {
	std::vector<int> histogram, cumHistogram(Pixel::NUM_COLOR, 0);
	double alpha = (double) Pixel::COLOR_MAX / (double) size();
	this->histogram(histogram);
	double sum = 0;
	for (int i = 0; i < Pixel::NUM_COLOR; i++) {
		sum += CLAMP(alpha * histogram[i], Pixel::COLOR_MIN, Pixel::COLOR_MAX);
		cumHistogram[i] = round(sum);
	}
	for (std::size_t i = 1; i < size(); i++) {
		guint8 color = operator[](i).luminance();
		operator[](i).setColor(cumHistogram[color]);
	}
}
