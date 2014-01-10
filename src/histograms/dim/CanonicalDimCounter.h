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

#include<vector>
using namespace std;

class CanonicalDimCounter {
public:
    CanonicalDimCounter(const Vec3b& color, int maxDiameter, const Mat& image);
    
    virtual ~CanonicalDimCounter();
    
    void compute();
    
    const vector<int>& getCount() const {
    	return counts;
    }
private:
    Vec3b color;
    vector<int> counts;
    int maxDiameter;
    Mat image;
    Mat flags;
};

#endif	/* CANONICALDIMCOUNTER_H */

