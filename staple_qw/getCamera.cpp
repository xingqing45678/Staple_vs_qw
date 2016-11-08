/*getCamera�����ǻ�ȡ��������ͷͼ��*/

#include <opencv.hpp>
#include <cmath>
#include <iostream>

using namespace cv;
using namespace std;

/*******ȫ�ֱ�����******/
//����ÿһ֡��ͼ��
Mat Image;
//����һ��VideoCapture�ṹ�����ڴ���Ƶ������ͷ
VideoCapture Capture;
//����ͼ��ĸ�,��Ӧy
int ImageHeight;
//����ͼ��Ŀ�,��Ӧx
int ImageWidth;
//ѵ����ĸ�,��Ӧy
int BoxHeight;
//ѵ����ĸ�,��Ӧx
int BoxWidth;
//����Ŀ�����
bool StopTracking = false;
//��ʼѵ��
bool DoTraining = true;

int main()
{
	//ѵ��ͼ��֡��
	int frameTraining = 0;
	//��ʼ��ֵ
	char keyValues = 0;
	//bool VideoCapture::open(const string& filename)
	//bool VideoCapture::open(int device)
	//������
	//filename - -����Ƶ��ͼƬ�ļ������ƣ�����video.avi ��img_001.jpg
	//device - -�豸���ƣ��磺a camera index��Device = 0����ʾ��Ĭ�������豸
	//������ͷ��ȡͼ��
	Capture.open(0);
	cout << "Capture is opened" << endl;
	while (DoTraining)
	{
		//��ȡͼ��֡
		Capture >> Image;
		if (Image.empty())
			break;
		//y
		ImageHeight = Image.rows;
		//x
		ImageWidth = Image.cols;
		//ѵ����ĳ�ʼ��С��Ĭ��Ϊ�����Σ�
		BoxHeight = min(ImageHeight, ImageWidth) / 3;
		BoxWidth = BoxHeight;
		//Rect(x,y,width,height)�ĸ���������ʼ���������Ͻǵĺ����ꡢ�������Լ����εĿ�ȡ��߶�
		Rect rec = Rect((ImageWidth - BoxWidth) / 2, (ImageHeight - BoxHeight) / 2, BoxWidth, BoxHeight);
		//�����κ�����ͼ�񣬾��β�������ɫ����ϸ�����ͣ������С����λ����
		rectangle(Image, rec, Scalar(0, 0, 255), 1, 8, 0);
		//��ʾͼ�񴰿�
		imshow("Sample", Image);
		//��ȡ��ֵ
		keyValues = waitKey(10);
		//��ȡ�����Ӻ���
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
		//�س�
	case 0xD:
	{
		cout << "Stop training and start tracking" << endl;
		//ѵ��������ʼ����
		DoTraining = false; 
		break;
	}
	//ESC�˳�
	case 0x1B:
	{
		cout << "Stop tracking" << endl;
		//��������
		StopTracking = true;
		break;
	}
		//��
	case 0x25:
		//��
	case 0x26:
		//��
	case 0x27:
		//��
	case 0x28:
		//W�Ŵ�
	case 87:
		//S��С
	case 83:
		//����
	default:
	}
}
