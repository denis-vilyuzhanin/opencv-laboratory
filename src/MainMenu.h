/*
 * MainMenu.h
 *
 *  Created on: Jan 2, 2014
 *      Author: dvily_000
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <map>

using namespace std;

class MainMenu {

public:
	class Action {
	public:
		virtual void handle() = 0;

		char getKey() {
			return key;
		}

		string getDescription() {
			return description;
		}
	protected:
		char key;
		string description;
	};

public:
	MainMenu();
	virtual ~MainMenu();

	void addAction(Action* action);

	void show();

	Action& waitAction();
private:
	map<char, Action*> actions;
};

#endif /* MAINMENU_H_ */
