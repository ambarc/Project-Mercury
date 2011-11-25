/* 
Project Mercury
All rights reserved. 
Ambar Choudhury
*/
//PMVideoClipper.h
//Basic Clipping Functionality for video.
#include <string> 

namespace pm {

 class PMVideoClipper {
 private:
  std::string videoFile; 
  VideoCapture videoCapture; 
 public:
  PMVideoClipper(const std::string& fileName);
  void setVideoFile(std::string& newVideoFile); 
  int saveVideoAtInterval(float start, float end, std::string& outputFile); 
 };

}