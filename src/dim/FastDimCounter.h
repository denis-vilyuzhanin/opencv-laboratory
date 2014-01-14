/*
 * FastDimCounter.h
 *
 *  Created on: Jan 14, 2014
 *      Author: Denys_Viliuzhanin
 */

#ifndef FASTDIMCOUNTER_H_
#define FASTDIMCOUNTER_H_

#include <opencv2/core/core.hpp>

class FastDimCounter {
public:
	class Counter {
	public:
		virtual void increment(const cv::Vec3b& value) = 0;
		virtual const cv::Vec3i& getResult() = 0;
	};

public:
	FastDimCounter(int size);
	virtual ~FastDimCounter();

	cv::Vec3d compute(const cv::Mat& image);
private:
	void assertImage(const cv::Mat& image);
private:
	int size;
	Counter* counter;
};

class SimpleCounter: public FastDimCounter::Counter {

public:
	SimpleCounter();
	SimpleCounter(const cv::Vec3b& step);
	SimpleCounter(const cv::Vec3b& step, const cv::Vec3b& zeroColor);

	void increment(const cv::Vec3b& value);
	const cv::Vec3i& getResult();
private:
	cv::Vec3i result;
	cv::Vec3b step;
	const cv::Vec3b zeroColor;
};

#endif /* FASTDIMCOUNTER_H_ */
