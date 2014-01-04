/*
 * Application.h
 *
 *  Created on: Dec 31, 2013
 *      Author: dvily_000
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

#include "MainMenu.h"
#include "ImageSourceView.h"
#include "histograms/Histogram.h"
#include "histograms/RGBHistogram.h"


using std::string;
using namespace cv;

class Application {
public:
	Application();
	virtual ~Application();

	int run();
	void close();

	void showMainMenu();

	ImageSourceView& getImageView() {
		return imageView;
	}

	void addHistogram(Histogram*);
	void refreshHistograms();

private:
	Mat sourceImage;
	MainMenu mainMenu;
	bool isClosed;
	ImageSourceView imageView;
	vector<Histogram*> histograms;
};

#endif /* APPLICATION_H_ */
