/*
 * ImageSourceView.h
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#ifndef IMAGESOURCEVIEW_H_
#define IMAGESOURCEVIEW_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

#include "ImageSource.h"

class ImageSourceView {
public:
	ImageSourceView();
	virtual ~ImageSourceView();

	void paint();
private:
	const string window;
	Mat image;
	ImageSource* imageSource;
};

#endif /* IMAGESOURCEVIEW_H_ */
