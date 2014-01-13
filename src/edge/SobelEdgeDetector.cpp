/*
 * SobelEdgeDetector.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Denys_Viliuzhanin
 */

#include "SobelEdgeDetector.h"

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


SobelEdgeDetector::SobelEdgeDetector(): Perspective() {
	// TODO Auto-generated constructor stub

}

SobelEdgeDetector::~SobelEdgeDetector() {
	// TODO Auto-generated destructor stub
}

void SobelEdgeDetector::update(Mat src) {

	 Mat src_gray;
	  Mat grad;
	  char* window_name = "Sobel Demo - Simple Edge Detector";
	  int scale = 1;
	  int delta = 0;
	  int ddepth = CV_16S;

	  int c;

	  
	  GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );

	  /// Convert it to gray
	  cvtColor( src, src_gray, CV_RGB2GRAY );

	  /// Create window
	  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

	  /// Generate grad_x and grad_y
	  Mat grad_x, grad_y;
	  Mat abs_grad_x, abs_grad_y;

	  /// Gradient X
	  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	  Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
	  convertScaleAbs( grad_x, abs_grad_x );

	  /// Gradient Y
	  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	  Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
	  convertScaleAbs( grad_y, abs_grad_y );

	  /// Total Gradient (approximate)
	  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

	  imshow( window_name, grad );
}

