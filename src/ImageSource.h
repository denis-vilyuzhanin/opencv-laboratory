/*
 * ImageSource.h
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#ifndef IMAGESOURCE_H_
#define IMAGESOURCE_H_

#include <opencv2/core/core.hpp>
using namespace cv;
class ImageSource {
public:
	ImageSource();
	virtual ~ImageSource();

	virtual void readImage(Mat& image) = 0;

public:
	
};

class NoImage: public ImageSource {
	public:
	NoImage(){}
	void readImage(Mat& image);
};
#endif /* IMAGESOURCE_H_ */
