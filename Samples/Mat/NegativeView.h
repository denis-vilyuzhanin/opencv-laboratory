#pragma once
#include <opencv2/core/core.hpp>

using namespace cv;

class NegativeView
{
public:
	NegativeView(void);
	~NegativeView(void);

	void show();
	void hide();
	void refresh();
	void update(Mat& source);

private:
	Mat lookUpTable;
	Mat negative;

	bool isShown;
};

