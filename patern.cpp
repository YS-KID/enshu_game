#include <stdlib.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"
 
int main( int argc, char **argv )
{
    cvNamedWindow( "Sample03in", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Sample03out", CV_WINDOW_AUTOSIZE );
 
    CvCapture *capture;
    if ( argc == 1 ) {
        capture = cvCreateCameraCapture(0);
    } else {
         capture = cvCreateFileCapture( argv[1] );
    }
    IplImage *frame = NULL;
    IplImage *frameGray = NULL;
    IplImage *frameCanny = NULL;
    while ( 1 ) {
        frame = cvQueryFrame( capture );
        if ( !frame ) break;
 
        if ( frameGray == NULL ) {
            frameGray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
            frameCanny = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
        }
        cvCvtColor(frame, frameGray, CV_BGR2GRAY);
        cvCanny( frameGray, frameCanny, 10, 100, 3 );
 
        cvShowImage( "Sample03in", frame );
        cvShowImage( "Sample03out", frameCanny );
 
        char ch = cvWaitKey(33);
        if ( ch == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Sample03in" );
    cvDestroyWindow( "Sample03out" );
    return 0;
}
