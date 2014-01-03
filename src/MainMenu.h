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
	class Action;

public:
	MainMenu();
	virtual ~MainMenu();

	void addAction(Action* action);

	void show();

	Action& waitAction();

private:
	map<char, Action*> actions;
	Action* lastAction;
	Action* unknownAction;
	Action* noAction;
private:
	Action* findNextAction(char key);
	bool shouldReprint();
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

		string getDisplayKey() {
			return displayKey;
		}
	protected:
		char key;
		string displayKey;
		string description;
	};


	class UnknownAction: public Action {
	public:
		UnknownAction();
		void handle();
	};

	class NoAction: public Action {
	public:
		void handle(){}
	};
};

#endif /* MAINMENU_H_ */
