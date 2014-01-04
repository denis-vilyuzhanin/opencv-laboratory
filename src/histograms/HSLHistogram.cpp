/*
 * HSLHistogram.cpp
 *
 *  Created on: Jan 4, 2014
 *      Author: dvily_000
 */

#include "HSLHistogram.h"

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>


HSLHistogram::HSLHistogram() {
	// TODO Auto-generated constructor stub

}

HSLHistogram::~HSLHistogram() {
	// TODO Auto-generated destructor stub
}

void HSLHistogram::update(Mat image) {
	Mat imageHLS;
	cvtColor(image,imageHLS,CV_RGB2HLS);

	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split(imageHLS, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true;
	bool accumulate = false;

	Mat hue_hist, light_hist, saturation_hist;

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), hue_hist, 1, &histSize, &histRange,
			uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), light_hist, 1, &histSize, &histRange,
			uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), saturation_hist, 1, &histSize, &histRange,
			uniform, accumulate);

	// Draw the histograms for B, G and R
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double) hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(hue_hist, hue_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(light_hist, light_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(saturation_hist, saturation_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++) {
		line(histImage,
				Point(bin_w * (i - 1),
						hist_h - cvRound(hue_hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(hue_hist.at<float>(i))),
				Scalar(255, 0, 0), 2, 8, 0);
		line(histImage,
				Point(bin_w * (i - 1),
						hist_h - cvRound(light_hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(light_hist.at<float>(i))),
				Scalar(255, 255, 255), 2, 8, 0);
		line(histImage,
				Point(bin_w * (i - 1),
						hist_h - cvRound(saturation_hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(saturation_hist.at<float>(i))),
				Scalar(127, 127, 127), 2, 8, 0);
	}

	/// Display
	namedWindow("HSL Histogram", CV_WINDOW_AUTOSIZE);
	imshow("HSL Histogram", histImage);
}

