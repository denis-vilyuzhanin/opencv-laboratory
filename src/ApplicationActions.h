/*
 * ApplicationActions.h
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#ifndef APPLICATIONACTIONS_H_
#define APPLICATIONACTIONS_H_
#include <iostream>
#include <string>

#include "Application.h"
#include "FileImageSource.h"
using namespace std;

class ApplicationActions {
public:

	class ApplicationAction: public MainMenu::Action {
	public:
		ApplicationAction(Application& app) :
				application(app) {
		}
	protected:
		Application& application;
	};

	class CloseAction: public ApplicationAction {
	public:
		CloseAction(Application& app) :
				ApplicationAction(app) {
			key = 27;
			displayKey = "ESC";
			description = "Click escape to exit";
		}

		void handle() {
			application.close();
		}

	};

	class ShowMainMenuAction: public ApplicationAction {
	public:
		ShowMainMenuAction(Application& app) :
				ApplicationAction(app) {
			key = 13;
			displayKey = "Enter";
			description = "Print Main Menu";
		}

		void handle() {


		}

	};

	class OpenFile: public ApplicationAction {
	public:
		OpenFile(Application& app): ApplicationAction(app) {
			key = 'o';
			displayKey = 'o';
			description = "Open Image/Video file";
		}

		void handle() {
			cout<<endl<< "Please input path to file you want to open: ";
			string path;
			getline(cin, path);

			application.getImageView().changeImageSource(new FileImageSource(path));
		}
	};
};

#endif /* APPLICATIONACTIONS_H_ */