/*
 * Histogram.h
 *
 *  Created on: Jan 4, 2014
 *      Author: dvily_000
 */

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include <opencv2/core/core.hpp>
using namespace cv;

#include "../Perspective.h"

class Histogram: public Perspective {
public:
	Histogram();
	virtual ~Histogram();

	virtual void update(Mat image) = 0;
};

#endif /* HISTOGRAM_H_ */
