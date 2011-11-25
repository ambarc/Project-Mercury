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
  cout << " Argument " << i << " is... "<< argv[i] << endl;
 }

 if (argc != 5) {
  cout << "Usage:VideoClipperUseCase <fileName> <startSecs> <endSecs> <outputFile>" << endl;
  return;
 }

 int start = atoi(argv[2]);
 int end = atoi(argv[3]);

 PMVideoClipper *clipper = new PMVideoClipper(argv[1]);
 string outputFile = argv[4];
 int result = clipper->saveVideoAtInterval(start, end, outputFile);
 return;
}
