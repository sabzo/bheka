/*
 * Targets a region of interst and creates a Circle blend 
 * Usage: ./blend <img> <x-pos> <y-pos> <width> <height> <color> 
 * ex: ./blend ../samples/car.jpg 200 100 100 200 300
*/
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char **argv) {
  IplImage *img = NULL;
  IplImage *imgc = NULL; 

  if (argc ==7 && (img = cvLoadImage(argv[1], 1)) && (imgc = cvCloneImage(img))) {
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    int width = atoi(argv[4]);
    int height = atoi(argv[5]);
    int add = atoi(argv[6]);
    // Define transparency
    double alpha = 0.6;
    double beta = 1 - alpha;

    // Create circle over region of interest
    cvSetImageROI(img, cvRect(x,y,width,height));
    CvPoint mid = cvPoint(width/2, height/2);
    cvCircle(img, mid, width/2, cvScalar(100, 0, 0, 0), -1, 8, 0);
    cvResetImageROI(img);
    
    // Blends image which has the transform already applied
    cvAddWeighted(img, alpha, imgc, beta, 0.0, img);

    cvNamedWindow("r1", 1);
    cvShowImage("r1", img);
    cvWaitKey(0);
  }
  else { 
    printf("Usage: ./blend <image> <x-pos> <y-pos> <width> <height> <color>\n");
    exit(1);
  }

  return 0;
}
