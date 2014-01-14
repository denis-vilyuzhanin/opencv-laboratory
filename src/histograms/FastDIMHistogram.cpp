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

FastDIMHistogram::FastDIMHistogram() {


}

FastDIMHistogram::~FastDIMHistogram() {

}

static uchar toColor(double v) {
	return 255 / 2 * v;
}

void FastDIMHistogram::update(cv::Mat image) {
	const int SIZE = std::min(image.rows, image.cols);

	FastDimCounter counter(SIZE);
	const cv::Vec3d& dim = counter.compute(image);


	cv::Mat histImage(SIZE , SIZE, CV_8UC3, cv::Scalar(toColor(dim[2]), toColor(dim[1]), toColor(dim[0])));
	cv::namedWindow("FastDIM Histogram", CV_WINDOW_AUTOSIZE);
	cv::imshow("FastDIM Histogram", histImage);

}
