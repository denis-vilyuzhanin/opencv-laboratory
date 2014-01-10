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
    
    int volume() const;

    const vector<int>& getCount() const {
    	return counts;
    }

    int getMinY() const  {
    	return minY;
    }

    int getMinX() const {
    	return minX;
    }

    int getMaxX() const {
    	return maxX;
    }

    int getMaxY() const {
    	return maxY;
    }

private:
    Vec3b color;
    vector<int> counts;
    int maxDiameter;
    Mat image;
    Mat flags;
    int minY;
    int minX;
    int maxX;
    int maxY;
};

#endif	/* CANONICALDIMCOUNTER_H */

