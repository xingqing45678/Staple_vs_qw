/*getCamera功能是获取电脑摄像头图像*/

#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image;
	VideoCapture capture;
	capture.open(0);
	cout << "Capture is opened" << endl;
	for (;;)
	{
		capture >> image;
		if (image.empty())
			break;
		imshow("Sample", image);
		if (waitKey(10) >= 0)
			break;
	}

	return 0;
}
