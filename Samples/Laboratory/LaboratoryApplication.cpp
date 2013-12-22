#include "StdAfx.h"
#include "LaboratoryApplication.h"

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

LaboratoryApplication::LaboratoryApplication(void)
{
}


LaboratoryApplication::~LaboratoryApplication(void)
{
}

int LaboratoryApplication::run() {
	namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
	while(1) {
	
		char ch = (char)waitKey(10);
		if (int(ch) < 0)
			continue;
		
		cout<<ch<<endl;
	}
}
