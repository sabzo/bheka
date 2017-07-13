#include <stdio.h>
#include <cv.h>
#include "highgui.h"
#include "cxcore.h"

int main(int argc, char **argv) {
  int key = 0;
  int i = 0;
  CvCapture *capture = 0; //The camera
  
  capture = cvCaptureFromCAM(0); //Open the camera
  if (!capture ){
     printf("Could not connect to camera\n" ); return 1;
  }

  cvQueryFrame(capture);
  double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
  int frame_height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
  int frame_width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
  
  cvNamedWindow("win", CV_WINDOW_AUTOSIZE);
  cvMoveWindow("win", 100, 100);

  CvVideoWriter *writer = cvCreateVideoWriter("out.avi", CV_FOURCC('D', 'I', 'V', 'X'), fps, cvSize(frame_width, frame_height), 1);
  if (!writer) {
    printf("CvVideoWriter failed\n");
    exit(1);
  }

  IplImage *img = 0;
  int nframes = 1000;
  
  for (i = 0; i < nframes; i++) {
    if (!cvGrabFrame(capture)) {
      printf("Unable to grab frame!\n");
      exit(0);
    }
    img = cvRetrieveFrame(capture, 0);
    cvWriteFrame(writer, img);
    cvShowImage("win", img);
    key = cvWaitKey(20);
  }
 
  cvReleaseVideoWriter(&writer);
  return 0;
}
