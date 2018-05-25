#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int _tmain(int argc, _TCHAR* argv[]){

  Mat src_image = imread("sign.png");
  namedWindow("aaa");
  imshow("aaa",src_image);

  Mat temp_image = imread("stop.png");
  namedWindow("bbb");
  imshow("bbb",temp_image);

  Mat reult;
  
  
  }
