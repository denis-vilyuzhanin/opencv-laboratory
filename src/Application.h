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


private:
	Mat sourceImage;
	MainMenu mainMenu;
	bool isClosed;
	ImageSourceView imageView;
};

#endif /* APPLICATION_H_ */
