/* 
Project Mercury
All rights reserved. 
Ambar Choudhury
*/
//PMVideoClipper.h
//Basic Clipping Functionality for video.
#include <string> 

#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "cv.hpp"

namespace pm {

 class PMVideoClipper {
 private:
  std::string videoFile; 
  cv::VideoCapture videoCapture; 
 public:
  PMVideoClipper(const std::string& fileName);
  void setVideoFile(std::string& newVideoFile); 
  int saveVideoAtInterval(float start, float end, std::string& outputFile); 
 };

}