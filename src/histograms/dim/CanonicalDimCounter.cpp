/* 
 * File:   CanonicalDimCounter.cpp
 * Author: dvily_000
 * 
 * Created on January 9, 2014, 10:47 PM
 */

#include "CanonicalDimCounter.h"


CanonicalDimCounter::~CanonicalDimCounter() {
    
}


void CanonicalDimCounter::process() {
    newRun();
    for(int y = 0; y < image.cols; y++) {
        for(int x = 0; x < image.rows; x++) {
            Vec3b actualColor = image.at<Vec3b>(y, x);
            if (color == actualColor) {
                int xx = x / diameter;
                int yy = y / diameter;
                flags.at<uchar>(yy, xx) = runCounter;
            }
        }
    }
}
    
int CanonicalDimCounter::compute() {
    int counter = 0;
    for(int y = 0; y < flags.cols; y++) {
        for(int x = 0; x < flags.rows; x++) {
            uchar flag = flags.at<uchar>(y, x);
            if (flag == runCounter) {
                counter++;
            }
        }
    }
    return counter;
}


void CanonicalDimCounter::newRun() {
    runCounter++;
    if (runCounter == 255) {
        runCounter = 1;
        flags.zeros(flags.rows, flags.cols, CV_8U);
    }
}