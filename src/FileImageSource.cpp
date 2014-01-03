/*
 * FileImageSource.cpp
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */



#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

#include "FileImageSource.h"

FileImageSource::FileImageSource(string path): filePath(path) {

}

FileImageSource::~FileImageSource() {
	// TODO Auto-generated destructor stub
}

void FileImageSource::readImage(Mat& image) {
	image = imread(filePath);
}
