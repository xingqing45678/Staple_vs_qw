/*getCamera功能是获取电脑摄像头图像*/

#include <opencv.hpp>
#include <cmath>
#include <iostream>

using namespace cv;
using namespace std;

/*******全局变量区******/
//承载每一帧的图像
Mat Image;
//建立一个VideoCapture结构，用于打开视频或摄像头
VideoCapture Capture;
//读入图像的高,对应y
int ImageHeight;
//读入图像的宽,对应x
int ImageWidth;
//训练框的高,对应y
int BoxHeight;
//训练框的高,对应x
int BoxWidth;
//结束目标跟踪
bool StopTracking = false;
//开始训练
bool DoTraining = true;

int main()
{
	//训练图像帧数
	int frameTraining = 0;
	//初始键值
	char keyValues = 0;
	//bool VideoCapture::open(const string& filename)
	//bool VideoCapture::open(int device)
	//参数：
	//filename - -打开视频或图片文件的名称，例如video.avi 、img_001.jpg
	//device - -设备名称，如：a camera index。Device = 0，表示打开默认摄像设备
	//打开摄像头获取图像
	Capture.open(0);
	cout << "Capture is opened" << endl;
	while (DoTraining)
	{
		//获取图像帧
		Capture >> Image;
		if (Image.empty())
			break;
		//y
		ImageHeight = Image.rows;
		//x
		ImageWidth = Image.cols;
		//训练框的初始大小（默认为正方形）
		BoxHeight = min(ImageHeight, ImageWidth) / 3;
		BoxWidth = BoxHeight;
		//Rect(x,y,width,height)四个整数来初始化矩形左上角的横坐标、纵坐标以及矩形的宽度、高度
		Rect rec = Rect((ImageWidth - BoxWidth) / 2, (ImageHeight - BoxHeight) / 2, BoxWidth, BoxHeight);
		//画矩形函数（图像，矩形参数，颜色，粗细，类型，坐标点小数点位数）
		rectangle(Image, rec, Scalar(0, 0, 255), 1, 8, 0);
		//显示图像窗口
		imshow("Sample", Image);
		//获取键值
		keyValues = waitKey(10);
		//调取按键子函数
		keyPressFuc(keyValues);
		if (waitKey(10) >= 0||StopTracking)
			break;
	}

	return 0;
}
void keyPressFuc(const char keyValues)
{
	char keyPress = keyValues;
	switch (keyPress)
	{
	case 0:
		break;
		//回车
	case 0xD:
	{
		cout << "Stop training and start tracking" << endl;
		//训练结束开始跟踪
		DoTraining = false; 
		break;
	}
	//ESC退出
	case 0x1B:
	{
		cout << "Stop tracking" << endl;
		//结束跟踪
		StopTracking = true;
		break;
	}
		//左
	case 0x25:
		//上
	case 0x26:
		//右
	case 0x27:
		//下
	case 0x28:
		//W放大
	case 87:
		//S缩小
	case 83:
		//其他
	default:
	}
}
