#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Basic Function
/// </summary>
//void main() {
//	string path = "Resources/test.png";
//	Mat img=imread(path);//matrix data type ��opencv����������ͼ��
//	Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
//
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);//cvt��convert����д����ͼ���һ����ɫ�ռ�ת��Ϊ��һ����ɫ�ռ䡣
//	GaussianBlur(imgGray, imgBlur,Size(7,7),5,0);//ʹ�ø�˹�˲���ģ��ͼ�񡣸ú�����Դͼ����ָ���ĸ�˹�˽��о��,Size(7,7)�Ǻ˴�С,����Խ��Խģ��
//	Canny(imgBlur, imgCanny, 25, 75);//��Ե��⣬��ֵ1��2�ɵ���Ŀ�ģ���ʾ����ı�Ե
//	
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//����һ���ˣ�����Size��ֻ����������������/��ʴ����
//	dilate(imgCanny, imgDil, kernel);//���ű�Ե�����ӱ�Ե��ȣ�
//	erode(imgDil, imgErode, kernel);//��ʴ��Ե����С��Ե��ȣ�
//	imshow("Image", img);
//	imshow("Image Gray", imgGray);
//	imshow("Image Blur", imgBlur);
//	imshow("Image Canny", imgCanny);
//	imshow("Image Dilation", imgDil);
//	imshow("Image Erode", imgErode);
//	waitKey(0);//������ʱ��0��ʾ����
//}