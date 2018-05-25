#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(){

  Mat src_image = imread("puzzle.jpg");
  namedWindow("aaa");
  imshow("aaa",src_image);

  Mat temp_image = imread("aka.png");
  namedWindow("bbb");
  imshow("bbb",temp_image);

  Mat result;
  matchTemplate(src_image, temp_image, result, TM_CCORR_NORMED);
  namedWindow("iii");
  imshow("iii", result);

  Point maxPt;
  minMaxLoc(result, 0, 0, 0, &maxPt);

  rectangle(src_image, maxPt, Point(maxPt.x + temp_image.cols,maxPt.y + temp_image.rows), Scalar(0, 255, 255), 2, 8, 0);
  namedWindow("iii");
  imshow("iii", src_image);

  waitKey(0);
  destroyAllWindows();
  return 0;
  
  
  }
