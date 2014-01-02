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

using std::string;
using namespace cv;

class Application {
public:
	Application();
	virtual ~Application();

	int run();

private:
	class DoNothingAction: public MainMenu::Action {
	public:
		DoNothingAction() {
			key = 'n';
			description = "Do nothing";
		}

		void handle() {
			std::cout<<"Nothing Done"<<std::endl;
		}
	};

private:
	const string sourceWindow;

	Mat sourceImage;

	MainMenu mainMenu;
};

#endif /* APPLICATION_H_ */
