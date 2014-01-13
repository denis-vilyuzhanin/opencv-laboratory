/*
 * SobelEdgeDetector.h
 *
 *  Created on: Jan 13, 2014
 *      Author: Denys_Viliuzhanin
 */

#ifndef SOBELEDGEDETECTOR_H_
#define SOBELEDGEDETECTOR_H_

#include "../Perspective.h"

class SobelEdgeDetector: public Perspective {
public:
	SobelEdgeDetector();
	virtual ~SobelEdgeDetector();

	void update(Mat image);
};

#endif /* SOBELEDGEDETECTOR_H_ */
