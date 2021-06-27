#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Project 2 �C Document Scanner
/// ͼ��Ԥ����ת��Ϊ�Ҷȡ����ģ����ʹ��Canny��Ե������ҵ���Ե��֪��ֽ�������������ֽ�ŵ�������ȡ�ĸ��ǵõ�����ͼ
/// </summary>

//Mat imgOriginal, imgGray, imgBlur, imgCanny, imgDil, imgErode, imgThre, imgWarp, imgCrop;
//vector<Point> initialPoints,docPoints;
//float w = 420, h = 596;
//Mat preProcessing(Mat img) {
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);//cvt��convert����д����ͼ���һ����ɫ�ռ�ת��Ϊ��һ����ɫ�ռ䡣
//	GaussianBlur(imgGray, imgBlur,Size(7,7),5,0);//ʹ�ø�˹�˲���ģ��ͼ�񡣸ú�����Դͼ����ָ���ĸ�˹�˽��о��,Size(7,7)�Ǻ˴�С,����Խ��Խģ��
//	Canny(imgBlur, imgCanny, 25, 75);//��Ե��⣬��ֵ1��2�ɵ���Ŀ�ģ���ʾ����ı�Ե
//	
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//����һ���ˣ�����Size��ֻ����������������/��ʴ����
//	dilate(imgCanny, imgDil, kernel);//���ű�Ե�����ӱ�Ե��ȣ�
//	//erode(imgDil, imgErode, kernel);//��ʴ��Ե����С��Ե��ȣ�
//	return imgDil;
//}
//
//vector<Point>/*����ֽ�ŵ�4���ǵ�*/ getContours(Mat imgDil) {//imgDil�Ǵ�������ű�Ե��ͼ����������������img��Ҫ�����ϻ���������ͼ��
//	vector<vector<Point>> contours;//������⵽��������ÿ�������ߴ洢Ϊһ���������
//
//	vector<Vec4i> hierarchy;//��������ӳ�����˵���Ϣ  typedef Vec<int, 4> Vec4i;����4������ֵ
//
//	//�ڶ�ֵͼ���в����������ú������ø��㷨�Ӷ�ֵͼ������ȡ����
//	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);//img��Ҫ����������ʲôͼƬ�ϣ�contours��Ҫ���Ƶ�������-1����Ҫ���Ƶ������ţ�-1��ʾ������������Saclar��ʾ������ɫ��2��ʾ���
//	
//	vector<vector<Point>> conPoly(contours.size());//conploy������ӦС��contours
//	vector<Rect> boundRect(contours.size());
//
//	vector<Point> biggest;
//	int maxArea = 0;
//
//	//��������ͨ�������������������
//	for (int i = 0; i < contours.size(); i++) {//������⵽������
//		int area = contourArea(contours[i]);
//		
//		//cout << area << endl;
//
//		string objectType;
//		if (area > 1000) {//���������1000�Ż���
//			//���������ܳ��򰼿ӳ��ȡ��ú������������߳��Ⱥͷ�յ��ܳ���
//			float peri = arcLength(contours[i], true);//�����������ܳ�
//			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//��ָ���ľ��Ƚ��ƶ�������ߡ��ڶ�������conPloy[i]�洢���ƵĽ�����������
//			
//			if (area > maxArea&&conPoly[i].size()==4) {
//				biggest = { conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3] };
//				maxArea = area;
//			}
//
//			//rectangle/*���Ʊ߽����*/(imgOriginal, boundRect[i].tl()/*tl()��topleft�������Ͻ�����*/, boundRect[i].br()/*br()��bottom right�������½�����*/, Scalar(0, 255, 0), 5);
//			//drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 2);
//			
//		}
//	}
//	return biggest;
//}
//
//void drawPoints(vector<Point> points, Scalar color) {
//	for (int i = 0; i < points.size(); i++) {
//		circle(imgOriginal, points[i], 10, color, FILLED);
//		putText(imgOriginal, to_string(i), points[i], FONT_HERSHEY_PLAIN, 4, color, 4);
//	}
//}
//
//vector<Point> reorder(vector<Point> points) {//��ǵ��˳���䣬Ҫȷ��һ��˳�� 0 1
//											//								 2 3
//	vector<Point> newPoints;
//	vector<int>  sumPoints, subPoints;
//	for (int i = 0; i < 4; i++) {
//		sumPoints.push_back(points[i].x + points[i].y);
//		subPoints.push_back(points[i].x - points[i].y);
//	}
//	
//	newPoints.push_back(points[min_element/* find smallest element*/(sumPoints.begin(), sumPoints.end())-sumPoints.begin()]);
//	newPoints.push_back(points[max_element/* find largest element*/(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
//	newPoints.push_back(points[min_element/* find smallest element*/(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
//	newPoints.push_back(points[max_element/* find largest element*/(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);
//
//	return newPoints;
//}
//
//Mat getWarp(Mat img,vector<Point> points,float w,float h) {
//	Point2f src[4] = { points[0],points[1],points[2],points[3] };//Point2f��ʾ������
//	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };//Point2f��ʾ������
//
//	Mat matrix = getPerspectiveTransform(src, dst);
//	warpPerspective(img, imgWarp, matrix, Point(w,h));
//
//	return imgWarp;
//}
//
//void main() {
//	string path = "Resources/paper.jpg";
//	imgOriginal=imread(path);
//
//	//resize(imgOriginal/*source*/, imgOriginal/*destination*/, Size()/*������ߴ�*/, 0.5/*�������*/, 0.5/*�������*/);
//
//	//Ԥ����
//	imgThre = preProcessing(imgOriginal);
//	//�������--���������
//	initialPoints=getContours(imgThre);
//	//drawPoints(initialPoints, Scalar(0, 0, 255));
//	docPoints = reorder(initialPoints);
//	//drawPoints(docPoints, Scalar(0, 255, 0));
//	//Ť��
//	imgWarp = getWarp(imgOriginal, docPoints, w, h);
//	//�ü�����ı�--ͨ������һ������
//	int cropValue = 5;
//	Rect roi(cropValue/*ÿ����Ҫ��ȥ������*/, cropValue, w - 2 * cropValue/*���*/, h - 2 * cropValue/*�߶�*/);
//	imgCrop = imgWarp(roi);
//	imshow("Image", imgOriginal);
//	imshow("Image Dilation", imgThre);
//	imshow("Image Warp", imgWarp);
//	imshow("Image Crop", imgCrop);
//	waitKey(0);
//}
