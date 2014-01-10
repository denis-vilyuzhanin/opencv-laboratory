/* 
 * File:   CanonicalDimCounter.cpp
 * Author: dvily_000
 * 
 * Created on January 9, 2014, 10:47 PM
 */

#include <math.h>

#include "CanonicalDimCounter.h"





CanonicalDimCounter::CanonicalDimCounter(const Vec3b& color, 
                                         int maxDiameter, 
                                         const Mat& image):
        color(color),
        maxDiameter(maxDiameter),
        image(image),
        flags(image.rows / maxDiameter, image.cols / maxDiameter, CV_8UC1, Scalar(0, 0, 0)),
        counts(maxDiameter, 0) {
    
}

CanonicalDimCounter::~CanonicalDimCounter() {
    
}


void CanonicalDimCounter::compute() {
    for(int diameter = 1; diameter < maxDiameter; diameter++) {
        for(int y = 0; y < image.cols; y++) {
            for(int x = 0; x < image.rows; x++) {
                Vec3b actualColor = image.at<Vec3b>(y, x);
                if (color == actualColor) {
                    int xx = x / maxDiameter;
                    int yy = y / maxDiameter;

                    flags.at<uchar>(yy, xx) = 1;
                }
            }
        }
    }
    
}

