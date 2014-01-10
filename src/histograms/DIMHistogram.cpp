/*
 * DIMHistogram.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: dvily_000
 */

#include "DIMHistogram.h"
#include "dim/CanonicalDimCounter.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <list>
#include <math.h> 
using namespace std;

DIMHistogram::DIMHistogram() {
	// TODO Auto-generated constructor stub
}

DIMHistogram::~DIMHistogram() {

}

void DIMHistogram::update(Mat image) {

    Vec3b white;
    white[0] = white[1] = white[2] = 255;
    CanonicalDimCounter counter(white, 1, image);
    counter.compute();
    
    
    /*int hist_w = 512;
	int hist_h = 100;
	int border = 20;
	double range = log10((double)maxCoveringSize) / log10((double)2);
	int bin_w = cvRound((double) hist_w / range);
	int bin_h = cvRound((double) (hist_h - border) / colorsCovering->size());
	int step = 1;
	Mat histImage(hist_h * colorsCovering->size(), hist_w, CV_8UC3, Scalar(0, 0, 0));

	int n = 1;
	for (set<ColorCoveringHolder>::iterator it = colorsCovering->begin();
			it != colorsCovering->end(); it++) {
		ColorCovering* covering = *(it);
		const vector<int> values = covering->getCovering();

		int max = values[0];
		int prevH = hist_h - border;
		for (int i = 1; i < values.size(); i++) {
			int h = cvRound((hist_h - border) * (double)values[i] / max);
			line(histImage,
				 Point(bin_w * (i - 1), hist_h * n - prevH),
				 Point(bin_w * i, hist_h * n - h),
				 Scalar(covering->getRed(), covering->getGreen(), covering->getBlue()),
				 2, 8, 0
				 );
			prevH  = h;
		}
		n++;
		 
		namedWindow("DIM Histogram", CV_WINDOW_AUTOSIZE);
		imshow("DIM Histogram", histImage);
		 
	}

	for (set<ColorCoveringHolder>::iterator it = colorsCovering->begin();
			it != colorsCovering->end(); it++) {
		ColorCoveringHolder covering = *(it);
		covering.release();
	}
	delete colorsCovering;*/
}

