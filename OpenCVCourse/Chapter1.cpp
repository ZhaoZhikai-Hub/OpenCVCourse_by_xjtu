#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Images
/// </summary>
//void main() {
//	string path = "Resources/test.png";
//	Mat img=imread(path);//matrix data type ��opencv����������ͼ��
//	imshow("Image", img);
//	waitKey(0);//������ʱ��0��ʾ����
//}


/// <summary>
/// Video
/// //��Ƶ��һϵ��ͼ����Ҫ��������ͼ���֡ һһ������ʾ����˽�ʹ��whileѭ��
/// </summary>
//void main() {
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);//������ʱ 20ms
//	}
//	
//}

/// <summary>
/// Webcam
/// �뵼����Ƶ��ͬ���ǣ�����Ҫ��Ƶ·����ֻ��Ҫ�����ID��id=0��ʾĬ�ϵ�����ͷ
/// </summary>
//void main() {
//	VideoCapture cap(0);//���id=0
//	Mat img;
//
	//while (true) {
	//	cap.read(img);
	//	imshow("Image", img);
	//	waitKey(1);//������ʱ 1ms������̫��
	//}
//
//}
