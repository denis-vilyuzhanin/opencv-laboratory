/*
 * MainMenu.cpp
 *
 *  Created on: Jan 2, 2014
 *      Author: dvily_000
 */

#include "MainMenu.h"

#include <iostream>
#include <string>

#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

const char NO_ACTION = -1;

MainMenu::MainMenu() {
	unknownAction = new UnknownAction();
	noAction = new NoAction();
	lastAction = 0;
}

MainMenu::~MainMenu() {
	//TODO: remove all actions
}


void MainMenu::addAction(Action* action) {
	actions[action->getKey()] = action;
}

void MainMenu::show() {
	if (!shouldReprint())
		return;
	cout<<endl<<endl<<"Please Select Next Action"<<endl;
	for (map<char,Action*>::iterator it=actions.begin(); it!=actions.end(); ++it) {
		if (it->first < 0) {
			continue;
		}
		cout<<"\t"<<"["<<it->second->getDisplayKey()<<"] "<<it->second->getDescription()<<endl;
	}

}

MainMenu::Action& MainMenu::waitAction() {
	if (shouldReprint())
		cout<<"?: ";

	char key = waitKey(300);
	Action* nextAction = noAction;
	if (key >= 0)
		nextAction = findNextAction(key);
	lastAction = nextAction;

	if (shouldReprint())
		cout<<nextAction->getDescription()<<endl;

	return *(nextAction);
}

MainMenu::Action* MainMenu::findNextAction(char key) {
	map<char, Action*>::iterator it  = actions.find(key);
	if (it != actions.end()) {
		return it->second;
	}
	return unknownAction;
}

bool MainMenu::shouldReprint() {
	return lastAction != noAction;
}

MainMenu::UnknownAction::UnknownAction(){
	key = -1;
	displayKey = "";
	description = "Unknown Action";
}

void MainMenu::UnknownAction::handle() {
	
}
