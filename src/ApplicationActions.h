/*
 * ApplicationActions.h
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#ifndef APPLICATIONACTIONS_H_
#define APPLICATIONACTIONS_H_

#include "Application.h"

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
};

#endif /* APPLICATIONACTIONS_H_ */
