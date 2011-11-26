/* 
Project Mercury
All rights reserved. 
Ambar Choudhury
*/

#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "cv.hpp"

namespace pm {

 class PMVideoMasher {
 private:
  std::vector<std::string> inputFiles;
 public:
  PMVideoMasher(std::vector<std::string> newInputFiles);
  void changeInputFiles(std::vector<std::string> newInputFiles);
  void addInputFiles(std::vector<std::string> extraInputFiles);
  // TODO(ambarc,aravind): Maybe add rendering/format options later.
  void mashFiles(std::string& outputName);
 };

}