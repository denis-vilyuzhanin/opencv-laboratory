/*
 * Perspective.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Denys_Viliuzhanin
 */

#ifndef PERSPECTIVE_H_
#define PERSPECTIVE_H_

#include <opencv2/core/core.hpp>
using namespace cv;


class Perspective {
public:
	Perspective();
	virtual ~Perspective();

	virtual void update(Mat image) = 0;
};

#endif /* PERSPECTIVE_H_ */
