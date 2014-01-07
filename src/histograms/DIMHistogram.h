/*
 * DIMHistogram.h
 *
 *  Created on: Jan 5, 2014
 *      Author: dvily_000
 */

#ifndef DIMHISTOGRAM_H_
#define DIMHISTOGRAM_H_

#include <opencv2/core/core.hpp>
using namespace cv;

#include "Histogram.h"

class DimCounter;

class DIMHistogram: public Histogram {
public:
	DIMHistogram();
	virtual ~DIMHistogram();
	void update(Mat image);
private:

};


#endif /* DIMHISTOGRAM_H_ */
