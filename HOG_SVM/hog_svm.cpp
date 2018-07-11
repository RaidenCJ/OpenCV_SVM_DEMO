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

int main(int argc, char** argv)      
{      
    int ImgWidht = 80;  
    int ImgHeight = 248;  

    vector<string> img_path;    
    vector<int> img_catg;    

    int nLine = 0;    
    unsigned long n; 
   
    string tempstr;
    int tempi=-1;
    char strPath[60] = {0};
    string buf;  

    ifstream svm_data( "./traininglist.txt" );   
    while( svm_data )    
    {    
        if( getline( svm_data, buf ) )    
        {    
            nLine ++;
            size_t position = buf.find(".jpg");
            if(position != string::npos ) {
                string prefix = buf.substr(0, position+4);
                string suffix = buf.substr(position+5);
                if(prefix.empty() || suffix.empty()){
                    continue;
                }
                tempi=atoi(suffix.c_str());
                
                img_path.push_back( prefix );//图像路径 
                img_catg.push_back(tempi);  
                //cout<< "tempi: "<<tempi<<endl;
                }
            }    
    }    
    svm_data.close();  
    
    Mat data_mat,label_mat;    
    int nImgNum = nLine;            //读入样本数量     

   //检测窗口,块尺寸,块步长,cell尺寸,直方图bin个数9   
    //检测窗口=SVM处理窗口大小  块步长=cell尺寸
    cv::HOGDescriptor hog(cv::Size(80, 248), cv::Size(40, 124), cv::Size(20, 62), cv::Size(20, 62), 9);

    Mat trainImg = Mat::zeros(ImgHeight, ImgWidht, CV_8UC3);//需要分析的图片
    for( string::size_type i = 0; i != img_path.size(); i++ )    
    {    
        cout<<"processing "<<img_path[i].c_str()<<endl;
        cout<<"img: "<<strlen( img_path[i].c_str() )<<endl;
//return 0;
        cv::Mat src = imread(img_path[i].c_str(), 1);
        if(src.empty()) {
            cout<<"image empty"<<endl;
            continue;
        }
        cv::resize(src, trainImg, cv::Size(ImgHeight,ImgWidht), 0, 0, INTER_CUBIC);



    //cv::imshow("test",src);
    //waitKey(100000000);

        //HOG描述子向量  
        std::vector<float> descriptors;  
        //计算HOG描述子，检测窗口移动步长(8,8)   
        hog.compute(src, descriptors, cv::Size(20, 62));
        cout<<"HOG dims: "<<descriptors.size()<<endl;
        if (i==0)  
        {  
             data_mat = Mat::zeros( nImgNum, descriptors.size(), CV_32FC1 ); //根据输入图片大小进行分配空间   
            label_mat = Mat::zeros( nImgNum, 1, CV_32SC1 );
        }  

        n=0;    
        for(vector<float>::iterator iter=descriptors.begin(); iter!=descriptors.end(); iter++)    
        {    
            data_mat.at<float>(i,n) = *iter;    
            n++;    
        }
        label_mat.at<int>(i, 0) =  img_catg[i];    
        cout<<" end processing "<<img_path[i].c_str()<<" tag: "<<img_catg[i]<<endl; 
    }  
    std::cout << "processing finished" << std::endl;

    Ptr<SVM> svm = SVM::create();
    svm->setType(SVM::C_SVC);
    svm->setKernel(SVM::LINEAR);
    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 10000, 1e-6));

    //Ptr<TrainData> trainData = TrainData::create(data_mat, COL_SAMPLE, res_mat);
    //svm->train(trainData);
    svm->train(data_mat, ROW_SAMPLE,  label_mat);
    std::cout << "training finished" << std::endl;
    svm->save("./factory.xml");

    //检测样本    
    vector<string> img_tst_path;    
    ifstream img_tst( "./testlist.txt" );    
    char strTestImg[60];
    while( img_tst )    
    {    
        if( getline( img_tst, buf ) )    
        {    
            memset(strTestImg,0x00,sizeof(strTestImg));
            strncpy(strTestImg,buf.c_str(),buf.size());
            img_tst_path.push_back( strTestImg );    
        }    
    }    
    img_tst.close();    

    char line[512];    
    ofstream predict_txt("./predict.txt" );    
    for( string::size_type j = 0; j != img_tst_path.size(); j++ )    
    {    
        cout<<"processing "<<img_tst_path[j].c_str()<<endl; 
        cv::Mat test = imread(img_tst_path[j].c_str(), 1);//读入图像     
        if(test.empty()) {
            cout<<"image empty"<<endl;
            continue;
        }
        resize(test, trainImg, cv::Size(ImgWidht,ImgHeight), 0, 0, INTER_CUBIC);//要搞成同样的大小才可以检测到   
        std::vector<float> descriptors; 
        hog.compute(trainImg, descriptors, cv::Size(10,18)); 
        Mat SVMtrainMat =  Mat::zeros(1,descriptors.size(),CV_32FC1);   

        n=0;    
        for(vector<float>::iterator iter=descriptors.begin(); iter!=descriptors.end(); iter++)    
        {    
            SVMtrainMat.at<float>(0,n) = *iter;    
            n++;    
        }    

        int ret = svm->predict(SVMtrainMat);
        std::sprintf( line, "%s %d\r\n", img_tst_path[j].c_str(), ret );   
        printf("%s %d\r\n", img_tst_path[j].c_str(), ret); 
        predict_txt<<line;  
    }    
    predict_txt.close();    
    /*
    cv::Mat testImg = imread("/home/bivl/svm/noglass_4457.jpg", 1);//读入图像     
    if(testImg.empty()) {
        cout<<"image empty"<<endl;
        return 0;
    }
    vector<float> descriptor;
    hog.compute(testImg,descriptor,Size(21, 5));//计算HOG描述子，检测窗口移动步长(8,8)
    Mat testFeatureMat = Mat::zeros(1,descriptor.size(),CV_32FC1);//测试样本的特征向量矩阵
    //将计算好的HOG描述子复制到testFeatureMat矩阵中
    for(int i=0; i<descriptor.size(); i++)
        testFeatureMat.at<float>(0,i) = descriptor[i];

    //用训练好的SVM分类器对测试图片的特征向量进行分类
    int result = svm->predict(testFeatureMat);//返回类标
    cout<<"分类结果："<<result<<endl;
    */
    return 0;    
} 
//g++ hog_svm.cpp -o hog_svm `pkg-config --cflags --libs opencv`

