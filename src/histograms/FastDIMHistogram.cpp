/*
 * FastDIMHistogram.cpp
 *
 *  Created on: Jan 14, 2014
 *      Author: Denys_Viliuzhanin
 */

#include "FastDIMHistogram.h"
#include "dim/FastDimCounter.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <algorithm>

FastDIMHistogram::FastDIMHistogram(): size(64) {
	cv::namedWindow("FastDIM Histogram", CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("Size", "FastDIM Histogram", &size, 256);
}

FastDIMHistogram::~FastDIMHistogram() {

}

static uchar toColor(double v) {
	return 255 / 2 * v;
}

void FastDIMHistogram::update(cv::Mat image) {
	const int TOTAL_SIZE = std::min(image.rows, image.cols);
	const int SIZE = std::min(size, TOTAL_SIZE);

	cv::Mat histImage(image.rows , image.cols, CV_8UC3, cv::Scalar(0, 0, 0));
	FastDimCounter counter(SIZE);
	for(int i = 0; i < TOTAL_SIZE; i += SIZE) {
		for(int j = 0; j < TOTAL_SIZE; j += SIZE) {
			const cv::Vec3d& dim = counter.compute(image);
			cv::Scalar color(toColor(dim[2]), toColor(dim[1]), toColor(dim[0]));
			cv::rectangle( histImage,
				           Point( i, j ),
				           Point( i + size, size),
				           color,
				           -1,
				           8 );
		}
	}

	cv::imshow("FastDIM Histogram", histImage);

}
