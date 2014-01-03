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
	actions[-1] = new Nothing();
}

MainMenu::~MainMenu() {
	//TODO: remove all actions
}


void MainMenu::addAction(Action* action) {
	actions[action->getKey()] = action;
}

void MainMenu::show() {
	cout<<endl<<endl<<"Please Select Next Action"<<endl;
	for (map<char,Action*>::iterator it=actions.begin(); it!=actions.end(); ++it) {
		if (it->first < 0) {
			continue;
		}
		cout<<"\t"<<"["<<it->second->getDisplayKey()<<"] "<<it->second->getDescription()<<endl;
	}

}

MainMenu::Action& MainMenu::waitAction() {
	char key;
	cout<<"?: ";
	key = waitKey(0);
	map<char, Action*>::iterator it  = actions.find(key);
	Action* nextAction;
	if (it != actions.end()) {
		nextAction = actions[key];
	} else {
		nextAction = actions[-1];
	}
	cout<<nextAction->getDescription()<<endl;
	return *(nextAction);
}


MainMenu::Nothing::Nothing(){
	key = -1;
	displayKey = "";
	description = "Unknown Action";
}

void MainMenu::Nothing::handle() {
	
}
