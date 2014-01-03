/*
 * ImageSourceView.cpp
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#include "ImageSourceView.h"

ImageSourceView::ImageSourceView():
		window("Image View"),
		image(1, 1, CV_8UC3) {
	imageSource = new NoImage();
	namedWindow(window, CV_WINDOW_AUTOSIZE);
}

ImageSourceView::~ImageSourceView() {
	// TODO Auto-generated destructor stub
}

void ImageSourceView::paint() {

	imageSource->readImage(image);
	imshow(window, image);
}

void ImageSourceView::changeImageSource(ImageSource* imageSource) {
	this->imageSource = imageSource;
}
