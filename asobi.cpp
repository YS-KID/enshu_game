#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <utility>

#define A
#define B
#define C

using namespace cv;

int main(){

  Mat src_image = imread("puzzle.jpg");

  Mat bin_image;
  cvtColor(src_image, bin_image, CV_BGR2GRAY);

  Mat temp_image = imread("aka.png");
  namedWindow("bbb");
  imshow("bbb",temp_image);

  Mat result;
  matchTemplate(src_image, temp_image, result, TM_CCORR_NORMED);
  
  vector<Point> detected_point;
  float threshold = 0.96f;
  for (int y = 0; y < result.rows; y++){
    for (int x = 0; x < result.cols; x++){
      if( result.at<float>(y, x) > threshold){
        detected_point.push_back(Point(x, y));
      }
    }
  }


  auto Cit = detected_point.begin();
  for (auto it = detected_point.begin(); it != detected_point.end(); it++){
    auto aa = it->x - Cit->x;
    auto bb = it->y - Cit->y;
    if(aa != 1 && bb != 1){
    rectangle(src_image, *it, Point(it->x + temp_image.cols,it->y + temp_image.rows), Scalar(0, 255, 255), 2, 8, 0);
    std::cout << it->x << " " << it->y << "  "  << std::endl;
    std::cout << Cit->x << " " << Cit->y << "  "  << std::endl;
    std::cout << std::endl;
    }
    Cit = it;
  }
  namedWindow("iii");
  imshow("iii", src_image);

  waitKey(0);
//  destroyAllWindows();
  return 0;
  
  
  }
