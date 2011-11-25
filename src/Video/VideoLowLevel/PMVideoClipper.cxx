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
   // In millisecs for OpenCV.
   //videoCapture.set(CV_CAP_PROP_POS_MSEC, start * 1000);

   // TODO(ambarc): Right now all I can do is go frame by frame --- determine fps and then get seconds per frame?? 
   // TODO(ambarc): Fix this -- but right now I'm just going to grab the next 1000 frames and output the clip.
   
   Mat frame = Mat::Mat();
   if (!videoCapture.isOpened()) {
    cerr << "Problem with videoCapture! Not opened!! " << endl;
    return -1;
   } else {
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

   //frame = Mat::Mat(videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT), videoCapture.get(CV_CAP_PROP_FRAME_WIDTH));
   int counter = 0;
   double framePosition = start;
   namedWindow("TestWindow", CV_WINDOW_NORMAL);
   videoCapture.set(CV_CAP_PROP_POS_MSEC, framePosition);
   while(true) {
    //bool returnFrame = videoCapture.read(frame);
    if (true) {
     videoCapture >> frame;
     counter++;
     cout << counter << " Relative position: " << videoCapture.get(CV_CAP_PROP_POS_AVI_RATIO) << " Frame index ... " 
     << videoCapture.get(CV_CAP_PROP_POS_FRAMES) << endl;
     imshow(videoFile, frame);
     waitKey(5);
     //cout << frame << endl;
    }
   }
   return 1;
  }
}