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

using std::string;
using namespace cv;

class Application {
public:
	Application();
	virtual ~Application();

	int run();

private:
	const string sourceWindow;

	Mat sourceImage;
};

#endif /* APPLICATION_H_ */
