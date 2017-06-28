/* Play a video */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <highgui.h>

int main(int argc, char **argv) {
  int fd;
  if (argc != 2) {
    printf("Usage: %s <filename>\n", *argv);
    exit(1);
  }

  if ((fd = open(argv[1], O_RDONLY, 0)) == -1) {
    printf("File %s doesn't exist\n", argv[1]);
    exit(1);
  } else 
    close(fd);

  cvNamedWindow("w", CV_WINDOW_AUTOSIZE);
  CvCapture *capture = cvCreateFileCapture(argv[1]);
  IplImage *frame;
  while (1) {
    frame = cvQueryFrame(capture);
    if (!frame)
      break;
    cvShowImage("w", frame);
    char c = cvWaitKey(33);
    if (c == 27)
      break;
  }
  cvReleaseCapture(&capture);
  cvDestroyWindow("w");

  return 0;
}
