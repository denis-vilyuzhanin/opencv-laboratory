/*
 * FastDIMHistogram.h
 *
 *  Created on: Jan 14, 2014
 *      Author: Denys_Viliuzhanin
 */

#ifndef FASTDIMHISTOGRAM_H_
#define FASTDIMHISTOGRAM_H_

#include <opencv2/core/core.hpp>

#include "histograms/Histogram.h"

class FastDIMHistogram: public Histogram  {
public:
	FastDIMHistogram();
	virtual ~FastDIMHistogram();

	void update(cv::Mat image);
private:
	int size;
};

#endif /* FASTDIMHISTOGRAM_H_ */
