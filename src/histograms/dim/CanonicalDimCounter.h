/* 
 * File:   CanonicalDimCounter.h
 * Author: dvily_000
 *
 * Created on January 9, 2014, 10:47 PM
 */

#ifndef CANONICALDIMCOUNTER_H
#define	CANONICALDIMCOUNTER_H

#include<opencv2/core/core.hpp>
using namespace cv;

#include<algorithm>
using namespace std;

class CanonicalDimCounter {
public:
    CanonicalDimCounter(const Vec3b& color, int diameter, const Mat& image): 
    color(color),
    diameter(diameter),
    image(image),
    flags(image.rows / diameter, image.cols / diameter, CV_8UC1, Scalar(0, 0, 0))
    {
        
    };
    
    virtual ~CanonicalDimCounter();
    
    void process();
    
    int compute();
    
private:
    Vec3b color;
    int diameter;
    Mat image;
    Mat flags;
};

#endif	/* CANONICALDIMCOUNTER_H */

