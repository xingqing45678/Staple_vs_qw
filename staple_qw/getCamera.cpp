/*getCamera�����ǻ�ȡ��������ͷͼ��*/

#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//����ÿһ֡��ͼ��
	Mat image;
	//����һ��VideoCapture�ṹ�����ڴ���Ƶ������ͷ
	VideoCapture capture;
	//bool VideoCapture::open(const string& filename)
	//bool VideoCapture::open(int device)
	//������
	//filename - -����Ƶ��ͼƬ�ļ������ƣ�����video.avi ��img_001.jpg
	//device - -�豸���ƣ��磺a camera index��Device = 0����ʾ��Ĭ�������豸
	//������ͷ
	capture.open(0);
	cout << "Capture is opened" << endl;
	for (;;)
	{
		capture >> image;
		if (image.empty())
			break;
		//��ʾ����ͷ����
		imshow("Sample", image);
		if (waitKey(10) >= 0)
			break;
	}

	return 0;
}
