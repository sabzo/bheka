#include <stdio.h>
#include <highgui.h>

int main(int argc, char **argv) {
  cvNamedWindow("w1", CV_WINDOW_AUTOSIZE);
  IplImage *img = 0;

  if (argc != 2) {
    printf("Usage: %s <img-name>\n", *argv);
    exit(1);
  }

  if ((img = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR)) == NULL) {
    printf("Image %s not found\n", argv[1]);
    exit(1);
  }

  cvShowImage("w1", img);

  while (1) {
    if (cvWaitKey(100) == 27)
      break;
  }

  cvDestroyWindow("w1");
  cvReleaseImage(&img);
  
  return 0;
}

