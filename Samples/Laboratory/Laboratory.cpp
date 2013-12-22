// Laboratory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "LaboratoryApplication.h"

using namespace std;

int _tmain(int argc, const char* argv[]) {
	string source;
	if( argc != 2) {
		cout<<"Please input file path of any source: ";
		getline(cin,source);
    } else {
		source = argv[1];
	}
 

    /*Mat image;
    image = imread(argv[1], CVs_LOAD_IMAGE_COLOR);   // Read the file
	LaboratoryApplication application;
	return application.run();*/
	return 1;
}

