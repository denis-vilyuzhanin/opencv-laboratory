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

	const int MAX_DIAMETER = min(image.rows, image.cols);
	Vec3b white;
	white[0] = white[1] = white[2] = 255;
	CanonicalDimCounter counter(white, MAX_DIAMETER, image);
	counter.compute();

	int hist_w = 512;
	int hist_h = 100;
	int border = 20;
	double range = log10((double) MAX_DIAMETER) / log10((double) 2);
	int bin_w = cvRound((double) hist_w / range);
	int bin_h = cvRound((double) (hist_h - border) / counter.getCount().size());
	int step = 1;
	Mat histImage(hist_h * counter.getCount().size(), hist_w, CV_8UC3,
			Scalar(0, 0, 0));

	

	int max = counter.getCount()[0];
	int prevH = hist_h - border;
	for (int i = 1; i < counter.getCount().size(); i++) {
		int h = cvRound((hist_h - border) * (double) counter.getCount()[i] / max);
		line(histImage, Point(bin_w * (i - 1), hist_h  - prevH),
				Point(bin_w * i, hist_h  - h),
				Scalar(white[2], white[1], white[0]), 2, 8, 0);
		prevH = h;
	}
	

	namedWindow("DIM Histogram", CV_WINDOW_AUTOSIZE);
	imshow("DIM Histogram", histImage);

}

