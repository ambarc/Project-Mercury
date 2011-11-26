#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdlib.h>

#include "PMVideo.h"

// List of video files as root.
// Intervals from the file.

using namespace std;
using namespace cv;

namespace pm {
 PMVideoLowLevelManager::PMVideoLowLevelManager() {}

 // Assuming good quality input file.
 // TODO(ambarc): Add checks against corrupted, bad format files.
 // TODO(ambarc): Make the temp file system more robust. Global variable for it?
 void PMVideoLowLevelManager::cutAndMash(ifstream& dataFile, string& outputFile) {
  bool debug = true;
  // Skip first line; has format.
  string nextLine;
  int tempFileCounter = 0;
  vector<string> mashFiles;
  getline(dataFile, nextLine);

  while (dataFile.good()) {
   getline(dataFile, nextLine);
   if (debug) {
    cout << nextLine << endl;
   }
      
   // Delimitation using STL elegance.
   vector<string> tokens;
   istringstream iss(nextLine);
   copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<vector<string> >(tokens));

   string fileName;
   fileName = tokens[0];
   if (debug) {
    cout << "Current filename is ... " << tokens[0] << endl;
   }

   PMVideoClipper clipper = PMVideoClipper(fileName);
   // Going through the intervals for that file.
   for (int i = 1; i < tokens.size(); i = i + 2) {
    float intervalStart, intervalEnd;

    // Get interval.
    intervalStart = atof(tokens[i].c_str());
    intervalEnd = atof(tokens[i + 1].c_str());
    if (debug) {
     cout << "Currrent start interval is... " << intervalStart 
      << ". End interval is... " << intervalEnd << endl;
    }
    // Create temp file for interval.
    string tempOutputFile = "";
    string intString;
    stringstream intStream;
    intStream << tempFileCounter++;
    tempOutputFile = tempOutputFile + "temp" + intStream.str() + ".mpg";
    mashFiles.push_back(tempOutputFile);
    if (debug) {
     cout << "Current temp output file is ... " << tempOutputFile << endl;
    }
    clipper.saveVideoAtInterval(intervalStart, intervalEnd, tempOutputFile);
   }
  }
  PMVideoMasher masher = PMVideoMasher(mashFiles);
  masher.mashFiles(outputFile);
  dataFile.close();
 }

}
