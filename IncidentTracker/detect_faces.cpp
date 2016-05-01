#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// Function Headers
void detectAndPrint(Mat frame);
void InsideOut(Mat frame);
// Global variables
string face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;

// Function main
int main(int argc,char *argv[])
{
    if (argc < 2)
    {
        std::cout<<"Error: Invalid Arguments\n";
        return (-1);
    }
    // Load the cascade
    if (!face_cascade.load(face_cascade_name))
    {
        std::cout<<"Error loading the Cascade file\n";
        return (-1);
    }
    // Read the image file
    Mat frame;
    VideoCapture cap(argv[1]);
    if ( cap.isOpened() )
    {
        cap>>frame;
    }
//    Mat frame = imread(img,CV_LOAD_IMAGE_COLOR);
//    int a = atoi(argv[2]);
    if (!frame.empty()){
  //      if (a == 1)
    //    {
            detectAndPrint(frame);
      //  }
     //   else if (a==2)
       // {
   //         InsideOut(frame);
     //   }
    }
    else{
        std::cout<<" --(!) No captured frame -- Break!";
    }
    return 0;
}

void detectAndPrint(Mat frame)
{
    std::vector<Rect> faces;
    face_cascade.detectMultiScale(frame, faces, 1.1, 3, 0 , Size(30, 30));
    std::cout<<faces.size() << endl;
}

void InsideOut(Mat frame)
{ 
    Mat gray, edge, draw;
    cvtColor(frame, gray, CV_BGR2GRAY);
    Canny( gray, edge, 50, 150, 3); 
    int count=0;
    for(int i = 0; i < edge.rows; i++)
        for(int j = 0; j < edge.cols; j++)
        {
            if (edge.at<double>(i,j)==0)
            {
                count++;                
            }
        }
    std::cout << (float(edge.total() - count) / float(edge.total())) <<endl;
}


