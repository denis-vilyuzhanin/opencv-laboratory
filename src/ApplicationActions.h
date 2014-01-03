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

	class CloseAction: public MainMenu::Action {
		public:
			CloseAction(Application& app): application(app)  {
				key = 27;
				displayKey = "ESC";
				description = "Click escape to exit";
			}


			void handle() {
				application.close();
			}

		private:
			Application& application;
	};

};

#endif /* APPLICATIONACTIONS_H_ */
