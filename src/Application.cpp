/*
 * Application.cpp
 *
 *  Created on: Dec 31, 2013
 *      Author: dvily_000
 */

#include "Application.h"
#include "ApplicationActions.h"
#include "FileImageSource.h"
using namespace std;
using namespace cv;



int main(int argc, char** argv) {
	Application application;

	if (argc >= 2) {
		string imagefile = argv[1];
		application.getImageView().changeImageSource(new FileImageSource(imagefile));
	}
	return application.run();
}

Application::Application() :
		isClosed(false) {
	mainMenu.addAction(new ApplicationActions::CloseAction(*this));
	mainMenu.addAction(new ApplicationActions::ShowMainMenuAction(*this));
	mainMenu.addAction(new ApplicationActions::OpenFile(*this));
	mainMenu.addAction(new ApplicationActions::AddHistogramAction(*this));
	mainMenu.addAction(new ApplicationActions::AddEdgeDetectorAction(*this));
}

Application::~Application() {
	// TODO Auto-generated destructor stub
}

int Application::run() {
	cout << "OpenCV Laboratory" << endl;

	
	while(!isClosed) {
		       // Show our image inside it.
		showMainMenu();
		imageView.paint();
		refreshPerspectives();
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

void Application::addPerspective(Perspective* newPerspective) {
	perspectives.push_back(newPerspective);
}

void  Application::refreshPerspectives() {
	for (std::vector<Perspective*>::iterator it = perspectives.begin() ;
		 it != perspectives.end();
		 ++it){
		Perspective* next = *it;
		next->update(imageView.getImage());
	}
}
