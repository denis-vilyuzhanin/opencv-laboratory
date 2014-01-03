/*
 * FileImageSource.h
 *
 *  Created on: Jan 3, 2014
 *      Author: dvily_000
 */

#ifndef FILEIMAGESOURCE_H_
#define FILEIMAGESOURCE_H_


#include <string>
using namespace std;

#include <opencv2/core/core.hpp>
using namespace cv;


#include "ImageSource.h"

class FileImageSource: public ImageSource {
public:
	FileImageSource(string path);
	virtual ~FileImageSource();
	void readImage(Mat&image);
private:
	string filePath;
};

#endif /* FILEIMAGESOURCE_H_ */
