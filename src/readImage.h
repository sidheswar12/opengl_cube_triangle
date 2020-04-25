#include <bits/stdc++.h>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv/cv.h"
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include "opencv2/opencv.hpp"

using namespace std;

IplImage* readImages(string filename)
{               
        IplImage *pImg;
        pImg = cvLoadImage(filename.c_str(), -1); 
        return pImg;
}

void saveImage(IplImage *img, string filename)
{        
        cvSaveImage(filename.c_str(), img, 0);
}