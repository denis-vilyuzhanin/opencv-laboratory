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
	friend static void onMouse( int event, int x, int y, int, void* );
public:
	FastDIMHistogram();
	virtual ~FastDIMHistogram();

	void update(cv::Mat image);
private:
	int size;

	int xToShow;
	int yToShow;
};

#endif /* FASTDIMHISTOGRAM_H_ */
