#include "opencv/cv.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

#include <iostream>    
#include <fstream>    
#include <string>    
#include <vector>    
using namespace cv;    
using namespace cv::ml;
using namespace std;    

#define CROPPED_WIN_WIDTH 80
#define CROPPED_WIN_HEIGHT 248
#define CROPPED_WIN_X 700
#define CROPPED_WIN_Y 200

bool cropImagegGetResult(Ptr<cv::ml::SVM> pmodel, cv::HOGDescriptor hog,
cv::Mat frame,cv::Rect rect)
{
	bool bRet = false;
    Mat trainImg = Mat::zeros(CROPPED_WIN_WIDTH, CROPPED_WIN_HEIGHT, CV_8UC3);//需要分析的图片
	cv::Mat matFrame = frame(rect);
    resize(matFrame, trainImg, cv::Size(CROPPED_WIN_WIDTH, CROPPED_WIN_HEIGHT), 0, 0, INTER_CUBIC);

    std::vector<float> descriptors; 
    hog.compute(trainImg, descriptors, cv::Size(CROPPED_WIN_WIDTH/4, CROPPED_WIN_HEIGHT/4)); 
    cv::Mat SVMtrainMat =  Mat::zeros(1,descriptors.size(),CV_32FC1);  
 
	for (int i = 0; i<descriptors.size(); i++)
		SVMtrainMat.at<float>(0, i) = descriptors[i];

	int ret = pmodel->predict(SVMtrainMat);
	if(ret != 0) {
		bRet = true;
	}
	return bRet;
}

int main(int argc, char** argv)      
{ 
    cv::HOGDescriptor hog = cv::HOGDescriptor(cv::Size(CROPPED_WIN_WIDTH, CROPPED_WIN_HEIGHT), 
							cv::Size(CROPPED_WIN_WIDTH/2, CROPPED_WIN_HEIGHT/2), 
							cv::Size(CROPPED_WIN_WIDTH/4, CROPPED_WIN_HEIGHT/4),
							cv::Size(CROPPED_WIN_WIDTH/4, CROPPED_WIN_HEIGHT/4), 9);
	Ptr<cv::ml::SVM> pmodel = StatModel::load<SVM>("./factory.xml");;

VideoCapture cap("./L2_M_55X7500F_XX_521-1.mp4");
//VideoCapture cap("/home/bivl/svm/factory-new/ch16_20180507120000.mp4");
	cv::Mat frame;	
	char result[100];
	memset(result,0x00,sizeof(result) );

	string str,str2,str3,str4;
    string str5,str6,str7,str8;
	int retcount = 0;
	int retcount2 = 0;
	int retcount3 = 0;
	int retcount4 = 0;

	int retcount5 = 0;
	int retcount6 = 0;
	int retcount7 = 0;
	int retcount8 = 0;

	cv::Rect rect= cv::Rect(CROPPED_WIN_X,CROPPED_WIN_Y,CROPPED_WIN_WIDTH, CROPPED_WIN_HEIGHT); 
	//cv::Rect rect2= cv::Rect(482,356,40,72);
	//cv::Rect rect3= cv::Rect(496,368,40,72);
	//cv::Rect rect4= cv::Rect(532,368,40,72);


	//cv::Rect rect5= cv::Rect(482,344,40,72);
	//cv::Rect rect6= cv::Rect(536,344,40,72);

bool bRet =false;
//bool bRet2 =false;
//bool bRet3 =false;
//bool bRet4 =false;


//bool bRet5 =false;
//bool bRet6 =false;
//bool bRet7 =false;
//bool bRet8 =false;

int record =0;
//int record2 =0;
//int record3 =0;
//int record4 =0;

//int record5 =0;
//int record6 =0;
//int record7 =0;
//int record8 =0;

	while(1)
	{
		cap>>frame;
		if(frame.empty() ) break;

		bRet =cropImagegGetResult(pmodel,hog, frame,rect);
		if(bRet) 
		{
			retcount ++;
			cout<<"Pos found! count ="<<retcount<<endl;
		}
		else
		{
			record =0;
			cout<<"Pos not found!"<<endl;
		}
/*
		bRet2 = cropImagegGetResult(pmodel,hog, frame,rect2);
		if(bRet2 ) {
			if(record2 == 2)	
				retcount2 ++;
			if(record2 < 3)
				record2 ++;
		}else{
			record2 =0;
		}


		bRet3 = cropImagegGetResult(pmodel,hog, frame,rect3);

		if(bRet3 ) {
			if(record3 == 2)	
				retcount3 ++;
			if(record3 < 3)
				record3 ++;
		}else{
			record3 =0;
		}

		
		bRet4 = cropImagegGetResult(pmodel,hog, frame,rect4);
		if(bRet4 ) {
			if(record4 == 2)	
				retcount4 ++;
			if(record4 < 3)
				record4 ++;
		}else{
			record4 =0;
		}

		bRet5 = cropImagegGetResult(pmodel,hog, frame,rect5);
		if(bRet5 ) {
			if(record5 == 2)	
				retcount5 ++;
			if(record5 < 3)
				record5 ++;
		}else{
			record5 =0;
		}

		bRet6 = cropImagegGetResult(pmodel,hog, frame,rect6);
		if(bRet6 ) {
			if(record6 == 2)	
				retcount6 ++;
			if(record6 < 3)
				record6 ++;
		}else{
			record6 =0;
		}

*/
//circle(frame,cv::Point(556,443),8,Scalar(255,0,0),2.0);
//circle(frame,cv::Point(502,443),8,Scalar(255,0,0),2.0);
//circle(frame,cv::Point(516,455),8,Scalar(255,0,0),2.0);
//circle(frame,cv::Point(552,455),8,Scalar(255,0,0),2.0);

//circle(frame,cv::Point(502,431),8,Scalar(255,0,0),2.0);
//circle(frame,cv::Point(556,431),8,Scalar(255,0,0),2.0);


		memset(result,0x00,sizeof(result) );
        std::sprintf( result, ":%d", retcount);   
		str = result;
        putText(frame, str, Point(570, 450), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0), 2.0);
 /*	
		memset(result,0x00,sizeof(result) );
        std::sprintf( result, ":%d", retcount2);   
		str2 = result;
        putText(frame, str2, Point(516, 450), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0), 2.0);

		memset(result,0x00,sizeof(result) );
        std::sprintf( result, ":%d", retcount3);   
		str3 = result;
        putText(frame, str3, Point(530, 462), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0), 2.0);

		memset(result,0x00,sizeof(result) );
        std::sprintf( result, ":%d", retcount4);   
		str4 = result;
        putText(frame, str4, Point(566, 462), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0), 2.0);


		memset(result,0x00,sizeof(result) );
        std::sprintf( result, ":%d", retcount5);   
		str5 = result;
       // putText(frame, str5, Point(516, 438), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0), 2.0);
 		
		memset(result,0x00,sizeof(result) );
        std::sprintf( result, ":%d", retcount6);   
		str6 = result;
     //   putText(frame, str6, Point(572, 438), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0), 2.0);
*/
		//resize(frame, frame, cv::Size(1280,760), 0, 0, INTER_CUBIC);
		cv::imshow("video",frame);
        char c = (char)waitKey(10);
        if( c == 27 || c == 'q' || c == 'Q' )
             break;
	}


	return 0;    
} 
