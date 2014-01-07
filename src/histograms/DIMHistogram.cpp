/*
 * DIMHistogram.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: dvily_000
 */

#include "DIMHistogram.h"

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

DIMHistogram::DIMHistogram() {
	// TODO Auto-generated constructor stub
}

DIMHistogram::~DIMHistogram() {

}

void DIMHistogram::update(Mat image) {

	int histSize[] = {256, 256, 256};
	float hranges[] = {0.0, 255.0};
	const float* ranges[] = {hranges, hranges, hranges};
	int channels[] = {0, 1, 2};


	MatND histogram;
	    // Compute histogram
	calcHist(&image,
	        1, // histogram of 1 image only
	        channels, // the channel used
	        cv::Mat(), // no mask is used
	        histogram, // the resulting histogram
	        3, // it is a 3D histogram
	        histSize, // number of bins
	        ranges // pixel value range
	        );

	int colorsCount = 0;
	for (int c0 = 0; c0 < histogram.size[0]; c0++) {
		for (int c1 = 0; c1 < histogram.size[1]; c1++) {
			for (int c2 = 0; c2 < histogram.size[2]; c2++) {
				int count = histogram.at<int>(c0, c1, c2);
				if (count > 0) {
					colorsCount++;
				}
			}
		}
	}

	cout<<"Colors: "<<colorsCount<<endl;
}

/*void DIMHistogram::update(Mat image) {
 Range processedRegion(0, min(image.cols, image.rows));
 Mat rectangleImage = image(processedRegion, processedRegion);
 int sizes[] = { 256, 256, 256 };
 Mat histogram(3, sizes, CV_32SC1, cv::Scalar(0));
 bool index[3][256] = {{false}};

 int colorCount = 0;
 for(int row = 0; row < image.rows; row++) {
 for(int column = 0; column < image.cols; column++) {
 if (image.channels() == 3) {
 Vec3b pixel = image.at<Vec3b>(row, column);
 if (histogram.at<int>(pixel[0], pixel[1], pixel[2]) == 0) {
 colorCount++;
 }
 histogram.at<int>(pixel[0], pixel[1], pixel[2])++;
 index[0][pixel[0]] = true;
 index[1][pixel[1]] = true;
 index[2][pixel[2]] = true;
 }
 }
 }


 vector<int> colors;
 for(int blue = 0; blue < 256; blue++) {
 if (!index[0][blue]) continue;
 for(int green = 0; green < 256; green++) {
 if (!index[1][green]) continue;
 for(int red = 0; red < 256; red++) {
 if (!index[2][red]) continue;
 int count = histogram.at<int>(blue, green, red);
 if (count > 0) {
 //cout<<"["<<blue<<","<<green<<","<<red<<"] = "<<count<<endl;
 colors.push_back(count);
 }
 }
 }
 }
 cout<<"Colors Found: "<<colorCount<<endl;
 }*/
