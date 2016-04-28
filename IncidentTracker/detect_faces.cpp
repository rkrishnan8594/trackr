#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// Function Headers
void detectAndDisplay(Mat frame);

// Global variables
// Copy this file from opencv/data/haarscascades to target folder
string face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";
int filenumber; // Number of file to be saved
string filename;

// Function main
int main(int argc, char *argv[])
{
    // Load the cascade
    if (!face_cascade.load(face_cascade_name)) {
        printf("--(!)Error loading\n");
        return (-1);
    }

    // Read the image file
    Mat frame = imread(argv[1]);

    // Apply the classifier to the frame
    if (!frame.empty()){
        detectAndDisplay(frame);
    } else{
        printf(" --(!) No captured frame -- Break!");
    }

    int c = waitKey(10);

    return 0;
}

// Function detectAndDisplay
void detectAndDisplay(Mat frame)
{
    std::vector<Rect> faces;
    Mat frame_gray;
    Mat crop;
    Mat res;
    Mat gray;
    string text;
    stringstream sstm;

    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    // Set Region of Interest
    std::cout<<faces.size() << endl;

}
