#include <iostream>
#include <string>

#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "cv.hpp"

#include "PMVideo.h"

using namespace std;
using namespace cv;
using namespace pm;

void main(int argc, char **argv) {
 cout << "Number of arguments is " << argc << endl;
 for (int i = 0; i < argc; i++) {
  cout << argv[i] << endl;
 }

 if (argc != 4) {
  cout << "Argument " << i << "is... " << "Usage:PMVideoClipperUseCase <fileName> <startSecs> <endSecs> " << endl;
  return;
 }

 int start = atoi(argv[2]);
 int end = atoi(argv[3]);

 PMVideoClipper *clipper = new PMVideoClipper(argv[1]);
 string outputFile = "tempOutput.avi";
 int result = clipper->saveVideoAtInterval(start, end, outputFile);
 return;
}
