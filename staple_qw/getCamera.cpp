/*getCamera功能是获取电脑摄像头图像*/

#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//承载每一帧的图像
	Mat image;
	//建立一个VideoCapture结构，用于打开视频或摄像头
	VideoCapture capture;
	//bool VideoCapture::open(const string& filename)
	//bool VideoCapture::open(int device)
	//参数：
	//filename - -打开视频或图片文件的名称，例如video.avi 、img_001.jpg
	//device - -设备名称，如：a camera index。Device = 0，表示打开默认摄像设备
	//打开摄像头
	capture.open(0);
	cout << "Capture is opened" << endl;
	for (;;)
	{
		capture >> image;
		if (image.empty())
			break;
		//显示摄像头窗口
		imshow("Sample", image);
		if (waitKey(10) >= 0)
			break;
	}

	return 0;
}
