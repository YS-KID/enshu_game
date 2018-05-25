#include <iostream>
#include
#include
int main(int argc, char *argv[]){
    cv::Mat img1=cv::imread(argv[1]);
    cv::Mat img2=cv::imread(argv[2]);
    std::cout << cv::norm(img1-img2) << std::endl;
}
