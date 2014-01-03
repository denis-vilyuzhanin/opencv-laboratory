/*
 * ImageSource.cpp
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#include "ImageSource.h"

ImageSource::ImageSource() {
	// TODO Auto-generated constructor stub

}

ImageSource::~ImageSource() {
	// TODO Auto-generated destructor stub
}

void NoImage::readImage(Mat& image) {
	image.create(1, 1, CV_8UC3);
}
