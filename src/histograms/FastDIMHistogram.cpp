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
#include <iostream>



FastDIMHistogram::FastDIMHistogram(): size(3), xToShow(-1), yToShow(-1) {
	cv::namedWindow("FastDIM Histogram", CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("Size", "FastDIM Histogram", &size, 256 - 2);

	cv::setMouseCallback("FastDIM Histogram", onMouse, this);
}

FastDIMHistogram::~FastDIMHistogram() {

}

static uchar toColor(double v) {
	return 255 / 2 * v;
}



void FastDIMHistogram::update(cv::Mat image) {
	const int TOTAL_SIZE = std::min(image.rows, image.cols);
	const int SIZE = std::min(size + 2, TOTAL_SIZE);

	cv::Mat histImage(image.rows , image.cols, CV_8UC3, cv::Scalar(0, 0, 0));
	FastDimCounter counter(SIZE);
	for(int i = 0; i < TOTAL_SIZE; i += SIZE) {
		for(int j = 0; j < TOTAL_SIZE; j += SIZE) {
			Mat subImage = image.colRange(i, std::min(i + SIZE - 1, image.cols))
								.rowRange(j, std::min(j + SIZE - 1, image.rows));
			const cv::Vec3d& dim = counter.compute(subImage);
			cv::Scalar color(toColor(dim[2]), toColor(dim[1]), toColor(dim[0]));
			cv::rectangle( histImage,
				           Point( i, j ),
				           Point( i + SIZE, j + SIZE),
				           color,
				           -1,
				           8 );
		}
	}
	cv::imshow("FastDIM Histogram", histImage);

	if (xToShow > -1 && yToShow > -1) {
		cv::Vec3b toShow = histImage.at<cv::Vec3b>(yToShow, xToShow);
		std::cout<<"dim["<<xToShow<<","<<yToShow<<"] = "<< double(toShow[0] / 127)<<std::endl;
		xToShow = yToShow = -1;
	}
}

static void onMouse( int event, int x, int y, int flags, void* data) {
	if( event != EVENT_LBUTTONDOWN )
	        return;
	FastDIMHistogram* thisHistogram = static_cast<FastDIMHistogram*>(data);
	thisHistogram->xToShow = x;
	thisHistogram->yToShow = y;
}
