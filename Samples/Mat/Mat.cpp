// Mat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include "NegativeView.h"

using namespace cv;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	Mat image;
    image = imread("E:/opencv-laboratory/Samples/images/cat.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

	NegativeView negativeView;
	negativeView.update(image);
	negativeView.show();
	waitKey(0);
	
	return 0;
}

