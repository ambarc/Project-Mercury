#include <iostream>
#include <string>

#include <PMVideo.h>

using namespace std; 
using namespace cv;

namespace pm {
  PMVideoClipper::PMVideoClipper(const string& fileName) {
   videoFile = fileName; 
   videoCapture = VideoCapture(fileName); 
  }
  void PMVideoClipper::setVideoFile(string& newVideoFile) {
   videoFile = newVideoFile; 
   videoCapture = VideoCapture(newVideoFile); 
  }
  //Start and end in seconds. 
  int PMVideoClipper::saveVideoAtInterval(float start, float end, string& outputFile) {
   bool debug = true;
   // TODO(ambarc): Right now all I can do is go frame by frame --- determine fps and then get seconds per frame?? 
   // TODO(ambarc): Fix this -- but right now I'm just going to grab the next 1000 frames and output the clip.
   if (start > end) {
    return -1;
   }
   Mat frame = Mat::Mat();
   if (!videoCapture.isOpened()) {
    cerr << "Problem with videoCapture! Not opened!! " << endl;
    return -1;
   } else {
    if (debug) {
     cout << "Video Capture working! " << endl;
     cout << "Width is " << videoCapture.get(CV_CAP_PROP_FRAME_WIDTH) << endl;
     cout << "Height is " << videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;
     cout << "Frame rate " << videoCapture.get(CV_CAP_PROP_FPS) << endl;
     cout << "Codec info " << videoCapture.get(CV_CAP_PROP_FOURCC) << endl;
     cout << "Frame count " << videoCapture.get(CV_CAP_PROP_FRAME_COUNT) << endl;
     cout << "Matrix format from video " << videoCapture.get(CV_CAP_PROP_FORMAT) << endl;
     cout << "Relative position " << videoCapture.get(CV_CAP_PROP_POS_AVI_RATIO) << endl;
     cout << "Video capture mode " << videoCapture.get(CV_CAP_PROP_MODE) << endl;
     cout << "Matrix Depth " << frame.depth() << endl;
     cout << "Matrix Type " << frame.type() << endl;
    }
   }

   double framePosition = end * 1000;   
   videoCapture.set(CV_CAP_PROP_POS_MSEC, framePosition);
   int endFrameIndex = videoCapture.get(CV_CAP_PROP_POS_FRAMES);
   
   double framePosition = start * 1000;
   videoCapture.set(CV_CAP_PROP_POS_MSEC, framePosition);
   int startFrameIndex = videoCapture.get(CV_CAP_PROP_POS_FRAMES);
   
   for(int i = startFrameIndex; i < endFrameIndex; i++) {
    videoCapture >> frame;
    if (debug) {
     cout << "Relative position: " << videoCapture.get(CV_CAP_PROP_POS_AVI_RATIO)
      << " Frame index ... " << videoCapture.get(CV_CAP_PROP_POS_FRAMES) << endl;
     imshow(videoFile, frame);
     waitKey(25);
    }
   }
   return 1;
  }
}