/* 
 * File:   CanonicalDimCounter.cpp
 * Author: dvily_000
 * 
 * Created on January 9, 2014, 10:47 PM
 */

#include "CanonicalDimCounter.h"





CanonicalDimCounter::CanonicalDimCounter(const Vec3b& color, 
                                         int maxDiameter, 
                                         const Mat& image):
        color(color),
        maxDiameter(maxDiameter),
        image(image),
        flags(image.rows, image.cols, CV_8UC1, Scalar(0, 0, 0)),
        counts(maxDiameter, 0) {
    
}

CanonicalDimCounter::~CanonicalDimCounter() {
    
}


void CanonicalDimCounter::compute() {
    for(int diameter = 1; diameter <= maxDiameter; diameter++) {
    	counts[diameter - 1] = 0;
        for(int y = 0; y < image.cols; y++) {
            for(int x = 0; x < image.rows; x++) {
                Vec3b actualColor = image.at<Vec3b>(y, x);
                if (color == actualColor) {
                    int xx = x / diameter;
                    int yy = y / diameter;
                    if (flags.at<uchar>(yy, xx) != diameter) {
                    	counts[diameter - 1]++;
                    }
                    flags.at<uchar>(yy, xx) = diameter;
                }
            }
        }
    }
    
}

