/* 
 * File:   CanonicalDimCounter.cpp
 * Author: dvily_000
 * 
 * Created on January 9, 2014, 10:47 PM
 */

#include "CanonicalDimCounter.h"


CanonicalDimCounter::~CanonicalDimCounter() {
    
}


int CanonicalDimCounter::compute() {
    int count = 0;
    for(int y = 0; y < image.cols; y++) {
        for(int x = 0; x < image.rows; x++) {
            Vec3b actualColor = image.at<Vec3b>(y, x);
            if (color == actualColor) {
                int xx = x / diameter;
                int yy = y / diameter;
                if (flags.at<uchar>(yy, xx) == 0)
                    count++;
                
                flags.at<uchar>(yy, xx) = 1;
            }
        }
    }
    return count;
}

