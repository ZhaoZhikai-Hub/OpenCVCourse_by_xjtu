//ѧϰ��μ�⳵�ƺ���βü���������Щ����

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>//������ͷ�ļ�
#include<iostream>

using namespace std;
using namespace cv;


/// <summary>
/// Project 3 �C License Plate(����) Detector
/// </summary>


void main() {

	
	VideoCapture cap(0);//���id=0
	Mat img;

	//����ģ��
	CascadeClassifier plateCascade;/*���ڶ�����ļ�����������*/
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");//���ļ����ط�����(�Ѿ�ѵ���õ�ģ��)
	if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }//����ļ��Ƿ���سɹ�

	vector<Rect> plates;

	while (true) {
		cap.read(img);
		//���Ը��ı������Ӻ���С�ھ����������ɹ���
		plateCascade.detectMultiScale(img/*����*/, plates/*���*/, 1.1/*��������*/, 10/*��С�ھ�*/);//������ͼ���м�ⲻͬ��С�Ķ��󡣼�⵽�Ķ����Ծ����б����ʽ���ء�

		
		
		for (int i = 0; i < plates.size(); i++) {
			Mat imgCrop = img(plates[i]);//plates�Ǿ����б�plates[i]�Ǿ���
			//imshow(to_string(i), imgCrop);
			imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);//���ƾ���
		}

		imshow("Image", img);
		waitKey(1);//������ʱ��0��ʾ����
	}
}