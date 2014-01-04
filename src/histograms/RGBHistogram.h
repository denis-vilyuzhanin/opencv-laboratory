/*
 * RGBHistogram.h
 *
 *  Created on: Jan 4, 2014
 *      Author: dvily_000
 */

#ifndef RGBHISTOGRAM_H_
#define RGBHISTOGRAM_H_

#include <opencv2/core/core.hpp>
using namespace cv;

#include "Histogram.h"

class RGBHistogram: public Histogram {
public:
	RGBHistogram();
	virtual ~RGBHistogram();
	void update(Mat image);

};

#endif /* RGBHISTOGRAM_H_ */
