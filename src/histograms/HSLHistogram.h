/*
 * HSLHistogram.h
 *
 *  Created on: Jan 4, 2014
 *      Author: dvily_000
 */

#ifndef HSLHISTOGRAM_H_
#define HSLHISTOGRAM_H_

#include <opencv2/core/core.hpp>
using namespace cv;

#include "Histogram.h"

class HSLHistogram: public Histogram {
public:
	HSLHistogram();
	virtual ~HSLHistogram();
	void update(Mat image);
};

#endif /* HSLHISTOGRAM_H_ */
