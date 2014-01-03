/*
 * Application.cpp
 *
 *  Created on: Dec 31, 2013
 *      Author: dvily_000
 */

#include "Application.h"
#include "ApplicationActions.h"
using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	Application application;

	return application.run();
}

Application::Application() :
		isClosed(false) {
	mainMenu.addAction(new ApplicationActions::CloseAction(*this));
	mainMenu.addAction(new ApplicationActions::ShowMainMenuAction(*this));
}

Application::~Application() {
	// TODO Auto-generated destructor stub
}

int Application::run() {
	cout << "OpenCV Laboratory" << endl;

	
	while(!isClosed) {
		       // Show our image inside it.
		showMainMenu();
		MainMenu::Action& nextAction = mainMenu.waitAction();
		nextAction.handle();
	}

	return 0;
}

void Application::showMainMenu() {
	mainMenu.show();
}

void Application::close() {
	isClosed = true;
}


