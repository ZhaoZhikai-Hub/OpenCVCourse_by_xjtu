//ѧϰ��μ����״��ͼ���е�����
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Shapes
/// </summary>


//! ��ȡ����
void getContours(Mat imgDil,Mat img) {//imgDil�Ǵ�������ű�Ե��ͼ����������������img��Ҫ�����ϻ���������ͼ��
	vector<vector<Point>> contours;//������⵽��������ÿ�������ߴ洢Ϊһ���������
	
	vector<Vec4i> hierarchy;//��������ӳ�����˵���Ϣ  typedef Vec<int, 4> Vec4i;����4������ֵ
	
	//�ڶ�ֵͼ���в����������ú������ø��㷨�Ӷ�ֵͼ������ȡ����
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);//img��Ҫ����������ʲôͼƬ�ϣ�contours��Ҫ���Ƶ�������-1����Ҫ���Ƶ������ţ�-1��ʾ������������Saclar��ʾ������ɫ��2��ʾ���
	vector<vector<Point>> conPoly(contours.size());//conploy������ӦС��contours
	vector<Rect> boundRect(contours.size());
	//��������ͨ�������������������
	for (int i = 0; i < contours.size(); i++) {//������⵽������
		int area = contourArea(contours[i]);
		
		//cout << area << endl;
		
		string objectType;
		if (area > 1000) {//���������1000�Ż���
			//���������ܳ��򰼿ӳ��ȡ��ú������������߳��Ⱥͷ�յ��ܳ���
			float peri = arcLength(contours[i], true);//�����������ܳ�
			approxPolyDP(contours[i], conPoly[i],0.02*peri,true);//��ָ���ľ��Ƚ��ƶ�������ߡ��ڶ�������conPloy[i]�洢���ƵĽ�����������
			
			
			boundRect[i]=boundingRect(conPoly[i]);//����߽����
			
			int objCor = (int)conPoly[i].size();//�ҽ��ƶ���εĽǵ�,��������3���ǵ㣬����/��������4���ǵ㣬Բ��>4���ǵ�
			cout << objCor << endl;
			if (objCor == 3) {objectType = "Tri";}
			else if (objCor == 4) {
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;//��߱�
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square";}//���εĿ�߱Ȳ������õ���1
				else objectType = "Rect";
			}
			else if (objCor > 4) { objectType = "Circle";}
			
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle/*���Ʊ߽����*/(img, boundRect[i].tl()/*tl()��topleft�������Ͻ�����*/, boundRect[i].br()/*br()��bottom right�������½�����*/, Scalar(0, 255, 0), 5);
			putText(img, objectType, {boundRect[i].x,boundRect[i].y-5}/*��������*/, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}

//void main() {
//	string path = "Resources/shapes.png";
//	Mat img=imread(path);
//	
//	//�ڼ����״ǰ����ͼƬԤ����ת��Ϊ�Ҷȡ���Ӹ�˹ģ����ʹ��Canny��Ե����������ű�Ե
//	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);//cvt��convert����д����ͼ���һ����ɫ�ռ�ת��Ϊ��һ����ɫ�ռ䡣
//	GaussianBlur(imgGray, imgBlur,Size(3,3),3,0);//ʹ�ø�˹�˲���ģ��ͼ�񡣸ú�����Դͼ����ָ���ĸ�˹�˽��о��,Size(7,7)�Ǻ˴�С,����Խ��Խģ��
//	Canny(imgBlur, imgCanny, 25, 75);//��Ե��⣬��ֵ1��2�ɵ���Ŀ�ģ���ʾ����ı�Ե
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//����һ���ˣ�����Size��ֻ����������������/��ʴ����
//	dilate(imgCanny, imgDil, kernel);//���ű�Ե�����ӱ�Ե��ȣ�
//	
//	getContours(imgDil,img);//img�������ϻ�������ͼƬ
//
//	imshow("Image", img);
//	/*imshow("Image Gray", imgGray);
//	imshow("Image Blur", imgBlur);
//	imshow("Image Canny", imgCanny);
//	imshow("Image Dil", imgDil);*/
//	waitKey(0);//������ʱ��0��ʾ����
//}