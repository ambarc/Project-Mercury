#include <iostream>
#include <fstream>

#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "cv.hpp"

namespace pm {

 class PMVideoLowLevelManager {
 private:
 public:
  PMVideoLowLevelManager();
  void cutAndMash(std::ifstream& dataFile, std::string& outputFile);
 };

}