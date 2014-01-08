/*
 * DIMHistogram.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: dvily_000
 */

#include "DIMHistogram.h"

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <list>
using namespace std;

DIMHistogram::DIMHistogram() {
	// TODO Auto-generated constructor stub
}

DIMHistogram::~DIMHistogram() {

}


class ColorCovering {
public:
	ColorCovering(uchar red, uchar green, uchar blue, int maxCoveringSize) :
		red(red), green(green), blue(blue), wasCombined(0) {
		covering.reserve(maxCoveringSize);
	}

	uchar getRed() const {
		return red;
	}

	uchar getGreen() const {
		return green;
	}

	uchar getBlue() const {
		return blue;
	}

	void combine(ColorCovering& other) {
		for(int i = 0; i < other.covering.size(); i++) {
			covering[i] = covering[i] + other.covering[i];
		}
		wasCombined++;
	}

	void addCoveringLevel() {
		covering.push_back(wasCombined + 1);
		wasCombined = 0;
	}

	const vector<int>& getCovering() const {
		return covering;
	}

private:
	uchar red;
	uchar green;
	uchar blue;
	vector<int> covering;
	int wasCombined;
};
bool operator< (const ColorCovering& lhs, const ColorCovering& rhs) {
	if (lhs.getRed() < rhs.getRed()) {
		return true;
	} else if (lhs.getRed() > rhs.getRed()) {
		return false;
	}
	if (lhs.getGreen() < rhs.getGreen()) {
		return true;
	} else if (lhs.getGreen() > rhs.getGreen()) {
		return false;
	}
	return lhs.getBlue() < lhs.getBlue();
}

bool operator== (const ColorCovering& lhs, const ColorCovering& rhs) {
	return lhs.getRed() == rhs.getRed() &&
		   lhs.getGreen() == rhs.getGreen() &&
		   lhs.getBlue() == rhs.getBlue();
}



class Area {
public:
	Area(int maxCoveringSize):
		parent(0),
		size(maxCoveringSize),
		x(0),
		y(0),
		maxCoveringSize(maxCoveringSize) {
		creatSubArea();
	}

	~Area() {
		delete subArea;
	}

	void compute(Mat image) {
		reset();
		if (subArea == 0) {
			Vec3b pixel = image.at<Vec3b>(y, x);
			colorsCovering->insert(new ColorCovering(pixel[2], pixel[1], pixel[0], maxCoveringSize));
		} else {
			int i = 0;
			subArea->position(x, y);
			do {
				subArea->compute(image);
				subColorsCovering.push_back(subArea->fetchColorCovering());
			} while(subArea->next());

			while(true) {
				set<ColorCovering*>* colorsCoveringWithMinColor = subColorsCovering[0];
				for(int i = 1; i < subColorsCovering.size(); i++) {
					if (colorsCoveringWithMinColor->empty()) {
						colorsCoveringWithMinColor = subColorsCovering[i];
						continue;
					}
					ColorCovering* minColorCovering = *(colorsCoveringWithMinColor->begin());

					if (subColorsCovering[i]->empty()) {
						continue;
					}
					ColorCovering* colorCovering = *(subColorsCovering[i]->begin());

					if (*colorCovering < *minColorCovering) {
						colorsCoveringWithMinColor = subColorsCovering[i];
					} else if (*colorCovering == *minColorCovering) {
						minColorCovering->combine(*colorCovering);
						subColorsCovering[i]->erase(subColorsCovering[i]->begin());
						delete colorCovering;
					}
				}
				if (colorsCoveringWithMinColor->empty()) {
					break;
				}
				ColorCovering* colorCovering = *(colorsCoveringWithMinColor->begin());
				colorsCoveringWithMinColor->erase(colorsCoveringWithMinColor->begin());

				colorCovering->addCoveringLevel();
				colorsCovering->insert(colorCovering);
			};

			for(int i = 0; i < subColorsCovering.size(); i++) {
				delete (subColorsCovering[i]);
			}
			subColorsCovering.clear();
		}
	}

	set<ColorCovering*>* fetchColorCovering() {
		set<ColorCovering*>* result = colorsCovering;
		colorsCovering = 0;
		return result;
	}

private:
	Area(Area* parent, int maxCoveringSize, int size):
		parent(parent),
		size(size),
		x(0),
		y(0),
		maxCoveringSize(maxCoveringSize){
		creatSubArea();
	}

	void creatSubArea() {
		if (size > 1) {
			subArea = new Area(this, maxCoveringSize, size / 2);
		} else {
			subArea = 0;
		}
	}

	Area* bottom() {
		Area* bottom = this;
		while(bottom->subArea != 0) {
			bottom = bottom->subArea;
		}
		return bottom;
	}

	void reset() {
		for(vector<set<ColorCovering*>*>::iterator it = subColorsCovering.begin();
			it != subColorsCovering.end();
			it++) {
			set<ColorCovering*>* covering = *it;
			delete covering;
		}
		subColorsCovering.clear();
		colorsCovering = new set<ColorCovering*>();

	}

	bool next() {
		x += size;
		if (x < parent->x + parent->size) {
			return true;
		}
		x = parent->x;
		y += size;
		if (y < parent->y + parent->size) {
			return true;
		}
		y = parent->y;
		return false;
	}

	void position(int x, int y) {
		this->x = x;
		this->y = y;
	}

private:
	int x;
	int y;
	int maxCoveringSize;
	int size;

	Area* parent;
	Area* subArea;
	set<ColorCovering*>* colorsCovering;
	vector<set<ColorCovering*>*> subColorsCovering;

};

void DIMHistogram::update(Mat image) {
	int maxCoveringSize = min(image.cols, image.rows);
	Area root(maxCoveringSize);
	root.compute(image);
	set<ColorCovering*>* colorsCovering = root.fetchColorCovering();

	for(set<ColorCovering*>::iterator it = colorsCovering->begin();
		it != colorsCovering->end();
		it++) {
		ColorCovering* covering = *(it);
		cout<<"["<<(int)covering->getRed()
			<<","<<(int)covering->getGreen()
			<<","<<(int)covering->getBlue()
			<<"]";
		cout<<": ";
		const vector<int> values = covering->getCovering();
		for(int i = 0; i < values.size(); i++) {
			cout<<values[i]<<" ";
		}
		cout<<endl;
	}
}

