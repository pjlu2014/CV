#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void readImages(vector<Mat> &images)
{
    int numImage = 16;
    static const char* filenames[] =
            {
                    "../a0.jpg", "../a1.jpg", "../a2.jpg", "../a3.jpg",
                    "../a4.jpg", "../a5.jpg", "../a6.jpg", "../a7.jpg",
                    "../a8.jpg", "../a9.jpg", "../a10.jpg", "../a11.jpg",
                    "../a12.jpg", "../a13.jpg", "../a14.jpg", "../a15.jpg"
            };
    for(int i=0; i<numImage;i++)
    {
        Mat im = imread(filenames[i]);
        if(!im.data)
        {
            printf("no image");
            printf("%d",i);

        }
        images.push_back(im);
    }
}

int main(int argc, char** argv)
{
    cout << "OpenCV Version" << CV_VERSION <<endl;
    cout << "Major version : " << CV_MAJOR_VERSION << endl;
    cout << "Minor version : " << CV_MINOR_VERSION << endl;
    cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;

    vector<Mat> images = {};

    readImages(images);
    //Align images
//    Ptr<AlignMTB> alignMTB = createAlignMTB();
//    alignMTB->process(images,images);

    //Merge images
    Mat exposurefusion;
    Ptr<MergeMertens> mergeMertens = createMergeMertens();
    mergeMertens->process(images,exposurefusion);

    imwrite("exposure.jpg",exposurefusion*255);

    return 0;

}
