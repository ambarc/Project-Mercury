#include <iostream>

#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "cv.hpp"

#include "PMVideo.h"

using namespace std;
using namespace cv;
using namespace pm;

void main(int argc, char **argv) {
 // MasherUseCase <list of file names to be mashed>
 // MasherUseCase <File containing list>
 if (argc < 3) {
  cout << "Usage VideoMasherUseCase <file1> <file2> <more> <outputFile> " << endl;
  return;
 }
 vector<string> inputFiles;
 for (int i = 1; i < argc - 1; i++) {
  string curVideoFile = argv[i];
  inputFiles.push_back(curVideoFile);
 }
 // Input is ready.
 string outputFile = argv[argc - 1];
 PMVideoMasher masher = PMVideoMasher(inputFiles);

 cout << "Outputting to " << outputFile << endl;
 masher.mashFiles(outputFile);
}
