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

MainMenu::MainMenu() {

}

MainMenu::~MainMenu() {
	//TODO: remove all actions
}

void MainMenu::Action::handle() {
}

void MainMenu::addAction(Action* action) {
	actions[action->getKey()] = action;
}

void MainMenu::show() {
	for (map<char,Action*>::iterator it=actions.begin(); it!=actions.end(); ++it) {
		cout<<"\t"<<"["<<it->first<<"] "<<it->second->getDescription()<<endl;
	}

}

MainMenu::Action& MainMenu::waitAction() {
	char key;
	cout<<"Please select next action: ";
	key = waitKey(0);
	Action* selectedAction = actions[key];
	return *selectedAction;
}



