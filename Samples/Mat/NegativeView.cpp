#include "StdAfx.h"
#include "NegativeView.h"

#include <opencv2/highgui/highgui.hpp>


NegativeView::NegativeView(void):lookUpTable(1, 256, CV_8U)
{
	isShown = false;
	MatIterator_<uchar>it = lookUpTable.begin<uchar>();
	MatIterator_<uchar>end = lookUpTable.end<uchar>();
    for(int i = 0; it != end; ++it)
		*it = 255 - (i++);
}


NegativeView::~NegativeView(void)
{
	hide();
}

void NegativeView::show() {
	if (isShown) 
		return;
	namedWindow( "Negative", CV_WINDOW_AUTOSIZE );// Create a window for display.
	isShown = true;
	refresh();
}

void NegativeView::hide() {
	if (!isShown)
		return;
	destroyWindow("Negative");
	isShown=false;
}

void NegativeView::refresh() {
	if (!isShown)
		return;
	imshow( "Negative", negative );
}

void NegativeView::update(Mat& source) {
	LUT(source, lookUpTable, negative);
		 
}
