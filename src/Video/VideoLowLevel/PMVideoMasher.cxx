#include <iostream>
#include <vector>
#include <string>

#include "PMVideo.h"

using namespace std;
using namespace cv;

namespace pm {
 
 PMVideoMasher::PMVideoMasher(vector<string> newInputFiles) {
  inputFiles = newInputFiles;
 }

 void PMVideoMasher::mashFiles(string& outputFile) {
  // TODO(aravind, ambarc): Make this a #define statement in a broader header.
  double fps = 23.16;
  bool debug = true;
  int width = INT_MAX;
  int height = INT_MAX;
  // Iterate through files.
  VideoCapture capture;
  for (int i = 0; i < inputFiles.size(); i++) {
   capture = VideoCapture(inputFiles[i]);
   double curFps = capture.get(CV_CAP_PROP_FPS);
   fps = (fps < curFps) ? fps : curFps;
   width = (width < capture.get(CV_CAP_PROP_FRAME_WIDTH)) ? width : capture.get(CV_CAP_PROP_FRAME_WIDTH);
   height = (height < capture.get(CV_CAP_PROP_FRAME_HEIGHT)) ? height : capture.get(CV_CAP_PROP_FRAME_HEIGHT);
  }
  if (debug) {
   cout << "Resultant fps is ... " << fps << " Width " << width << " Height " << height << endl;
  }
  Size size = Size(width, height);
  VideoWriter writer = 
   VideoWriter(outputFile, CV_FOURCC('P', 'I', 'M', '1'), fps, size, true);
  
  Mat outputFrame;
  // Frame by frame.
  for (int i = 0; i < inputFiles.size(); i++) {
   capture = VideoCapture(inputFiles[i]);
   if (debug) {
    cout << inputFiles[i] << endl;
   }
   int curFrameCount = capture.get(CV_CAP_PROP_FRAME_COUNT);
   for (int i = 0; i < curFrameCount; i++) {
    capture >> outputFrame;
    writer << outputFrame;
   }
  }
 }

 void PMVideoMasher::addInputFiles(vector<string> extraInputFiles) {
  inputFiles.insert(inputFiles.end(), extraInputFiles.begin(), extraInputFiles.end());
  /*
  if (inputFiles.size() == 0) {
   inputFiles = extraInputFiles;
  } else {
   inputFiles.insert(inputFiles.end(), extraInputFiles.begin(), extraInputFiles.end());
  }
  */
 }

 void PMVideoMasher::changeInputFiles(vector<string> newInputFiles) {
  inputFiles = newInputFiles;
 }
}