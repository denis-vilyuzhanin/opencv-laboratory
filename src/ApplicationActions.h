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
using namespace std;

#include "Application.h"
#include "FileImageSource.h"
#include "histograms/Histogram.h"
#include "histograms/RGBHistogram.h"
#include "histograms/HSLHistogram.h"
#include "histograms/DIMHistogram.h"
#include "histograms/FastDIMHistogram.h"

#include "edge/SobelEdgeDetector.h"

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
		OpenFile(Application& app) :
				ApplicationAction(app) {
			key = 'o';
			displayKey = 'o';
			description = "Open Image/Video file";
		}

		void handle() {
			cout << endl << "Please input path to file you want to open: ";
			string path;
			getline(cin, path);

			application.getImageView().changeImageSource(
					new FileImageSource(path));
		}
	};

	class AddHistogramAction: public ApplicationAction {
	public:
		AddHistogramAction(Application& app) :
				ApplicationAction(app) {
			key = 'h';
			displayKey = 'h';
			description = "Add Histogram";
		}

		void handle() {
			cout << endl << "Available Histograms: "<< endl;
			cout << "\t[rgb] " << "RGB historgam" << endl;
			cout << "\t[hsl] " << "RGB historgam" << endl;
			cout << "\t[dim] " << "DIM historgam" << endl;
			cout << endl << "Please select histogram from list above: ";
			string type;
			getline(cin, type);

			Histogram* histogram = 0;

			if (type == "rgb") {
				histogram = new RGBHistogram();
			} else if (type == "hsl") {
				histogram = new HSLHistogram();
			} else if (type == "dim") {
				histogram = new DIMHistogram();
			} else if (type == "fastDIM") {
				histogram = new FastDIMHistogram();
			}

			if (histogram != 0) {
				application.addPerspective(histogram);
			}
		}
	};

	class AddEdgeDetectorAction: public ApplicationAction {
	public:
		AddEdgeDetectorAction(Application& app) :
				ApplicationAction(app) {
			key = 'e';
			displayKey = 'e';
			description = "Add Edge Detector";
		}

		void handle() {
			cout << endl << "Available Edge Detectors: " <<endl;
			cout << "\t[sobel] " << "Sobel Derivatives" << endl;
			cout << endl << "Please select detector type from list above: ";
			string type;
			getline(cin, type);


			if (type == "sobel") {
				application.addPerspective(new SobelEdgeDetector());
			}
		}

	};
};

#endif /* APPLICATIONACTIONS_H_ */
