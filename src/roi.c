/* Perform an operaton on a Region of Interest 
 * Targets a region of interst adjusts colors 
 * Usage: ./roi <img> <x-pos> <y-pos> <width> <height> <color> 
 * ex: ./roi ../samples/car.jpg 200 100 100 200 300
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

    cvSetImageROI(img, cvRect(x,y,width,height));
    cvAddS(img, cvScalar(add, 0, 0, 0), img, NULL);
    cvResetImageROI(img);
    cvNamedWindow("r1", 1);
    cvShowImage("r1", img);
    cvWaitKey(0);
  }
  else { 
    printf("Usage: ./roi <image>\n");
    exit(1);
  }

  return 0;
}
