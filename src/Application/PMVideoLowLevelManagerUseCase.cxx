#include <string>
#include <iostream>
#include <fstream>

#include "PMVideo.h"

using namespace std;
using namespace cv;
using namespace pm;

void main(int argc, char** argv) {
 if (argc != 3) {
  cout << "Usage: VideoLowLevelManagerUseCase <dataFileName> <outputFileName> " 
   << endl;
  return;
 }
 PMVideoLowLevelManager lowLevel = PMVideoLowLevelManager();
 ifstream dataFile(argv[1]);
 string outputFile(argv[2]);
 lowLevel.cutAndMash(dataFile, outputFile);
 return;
}
