/*
 * FastDimCounter.cpp
 *
 *  Created on: Jan 14, 2014
 *      Author: Denys_Viliuzhanin
 */

#include "FastDimCounter.h"
#include <math.h>

FastDimCounter::FastDimCounter(int size): size(size), counter(new SimpleCounter()) {


}

FastDimCounter::~FastDimCounter() {
	delete counter;
}

static cv::Vec3b getValue(const cv::Mat& image, int x, int y) {
	if (image.channels() == 1) {
		uchar v = image.at<uchar>(y, x);
		return cv::Vec3b(v, v, v);
	} else if (image.channels() == 3) {
		return image.at<cv::Vec3b>(y, x);
	}
	return cv::Vec3b(0, 0, 0);
}

static double dim(int n, int size) {
	return log(double(n)) / log(double(size));
}



cv::Vec3d FastDimCounter::compute(const cv::Mat& image) {
	assertImage(image);
	counter->reset();
	for (int x = 0; x < size && x < image.cols; x++) {
		for (int y = 0; y < size && y < image.rows; y++) {
			const cv::Vec3b& value = getValue(image, x, y);
			counter->increment(value);
		}
	}
	const cv::Vec3i& sum = counter->getResult();
	return cv::Vec3d(dim(sum[0], size), dim(sum[1], size), dim(sum[2], size));
}


void FastDimCounter::assertImage(const cv::Mat& image) {
}

SimpleCounter::SimpleCounter(): result(0), step(1, 1, 1), zeroColor(0, 0, 0){

}

SimpleCounter::SimpleCounter(const cv::Vec3b& step): result(0, 0, 0), step(step), zeroColor(0, 0, 0) {

}

SimpleCounter::SimpleCounter(const cv::Vec3b& step, const cv::Vec3b& zeroColor):
		result(0), step(step), zeroColor(zeroColor) {

}

void SimpleCounter::reset() {
	result[0] = result[1] = result[2] = 0;
}

void SimpleCounter::increment(const cv::Vec3b& value) {
	if (zeroColor != value) {
		result += step;
	}
}

const cv::Vec3i& SimpleCounter::getResult() {
	return result;
}
