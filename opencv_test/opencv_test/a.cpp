

#include <cstdlib>
#include <cstdio>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 5;
int kernel_size = 3;
char *window_name = "Edge Map";

char *src_path = "C:\\Users\\dell\\Desktop\\0.jpg";


void CannyThreshold(int,void *)
{
	// 高斯滤波
	blur(src_gray, detected_edges, Size(3, 3));
	
	// 梯度计算	   // 非极大值抑制		 // 滞后阈值
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
	
	
	dst = Scalar::all(0); // 填充背景为黑色

	
	src.copyTo(dst, detected_edges);
	imshow(window_name, dst);
}



void test_canny() {
	src = imread("C:\\Users\\dell\\Desktop\\0.jpg");

	dst.create(src.size(), src.type());

	cvtColor(src, src_gray, CV_BGR2GRAY);

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	createTrackbar("Min Threshold", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

	CannyThreshold(0, 0);

	waitKey(0);

	return;

}


void test_sobel()
{
	Mat src, src_gray;
	Mat grad;

	char *window_name = "Sobel Dome";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	int c;
	char *src_path = "C:\\Users\\dell\\Desktop\\0.jpg";

	src = imread(src_path);

	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	cvtColor(src, src_gray, CV_RGB2GRAY);

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);

	Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 1, abs_grad_y, 1, 0, grad);

	imshow(window_name, grad);

	waitKey(0);

	return;

}


void test_laplace()
{
	Mat src, src_gray;
	Mat grad;

	char *window_name = "Laplace Dome";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	int c;
	char *src_path = "C:\\Users\\dell\\Desktop\\0.jpg";

	src = imread(src_path);

	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	cvtColor(src, src_gray, CV_RGB2GRAY);

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	Mat abs_dst;

	Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	

	imshow(window_name, abs_dst);

	waitKey(0);

	return;
}


void test_hough_transform()
{
	const char * path = "C:\\Users\\dell\\Desktop\\5.jpg";
	Mat src =  imread(path, 0);

	Mat dst, cdst;
	Canny(src, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);

 #if 0	


	vector<Vec2f> lines;
	HoughLines(dst, lines, 1, CV_PI / 180, 50, 0, 0);

	for (size_t i=0;i<lines.size();i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);

		double x0 = a*rho, y0 = b*rho;

		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));

		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));

		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
	}

#else

	vector<Vec4i> lines;
	HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 2);
	for (size_t i=0;i<lines.size();i++)
	{
		Vec4i l = lines[i];
		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}
 #endif
	imshow("source", src);
	imshow("detected", cdst);

	waitKey();
}



Mat map_x, map_y;

char *remap_window = "Remap demo";
int ind = 0;

void update_map(void)
{
	ind %= 4;
	for (int j = 0; j < src.rows; j++)
	{
		for (int i = 0; i < src.cols; i++)
		{
			switch (ind)
			{
			case 0:
				if (i > src.cols*0.25 && i < src.cols*0.75 && j > src.rows*0.25 && j < src.rows*0.75)
				{
					map_x.at<float>(j, i) = 2 * (i - src.cols*0.25) + 0.5;
					map_y.at<float>(j, i) = 2 * (j - src.rows*0.25) + 0.5;
				}
				else
				{
					map_x.at<float>(j, i) = 0;
					map_y.at<float>(j, i) = 0;
				}
				break;
			case 1:
				map_x.at<float>(j, i) = i;
				map_y.at<float>(j, i) = src.rows - j;
				break;
			case 2:
				map_x.at<float>(j, i) = src.cols - i;
				map_y.at<float>(j, i) = j;
				break;
			case 3:
				map_x.at<float>(j, i) = src.cols - i;
				map_y.at<float>(j, i) = src.rows - j;
				break;
			} // end of switch
		}
	}
	ind++;
}

void test_remap()
{
	

	

	const char *path = "C:\\Users\\dell\\Desktop\\0.jpg";
	src = imread(path);

	dst.create(src.size(), src.type());

	map_x.create(src.size(), CV_32FC1);

	map_y.create(src.size(), CV_32FC1);

	namedWindow(remap_window, CV_WINDOW_AUTOSIZE);

	while (true)
	{
		int c = waitKey(1000);
		if (char(c)==27)
		{
			break;
		}
		update_map();
		remap(src, dst, map_x, map_y, CV_INTER_AREA, BORDER_CONSTANT, Scalar(0, 0, 0));

		imshow(remap_window, dst);
	}
	return;
}


char *sourec_window = "Source Image";
char *warp_window = "Warp Image";
char *warp_rotate_window = "Warp + Rotate";


void test_affine_transformation()
{
	Point2f srcTri[3];
	Point2f dstTri[3];

	Mat rot_mat(2, 3, CV_32FC1);
	Mat warp_mat(2, 3, CV_32FC1);
	Mat src, warp_dst, warp_rotate_dst;



	src = imread(src_path);
	warp_dst = Mat::zeros(src.rows, src.cols, src.type());

	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols-1, 0);
	srcTri[2] = Point2f(0, src.rows-1);


	dstTri[0] = Point2f(src.cols*0.0, src.rows*0.33);
	dstTri[1] = Point2f(src.cols*0.85, src.rows*0.25);
	dstTri[2] = Point2f(src.cols*0.15, src.rows*0.7);

	warp_mat = getAffineTransform(srcTri, dstTri);

	warpAffine(src, warp_dst, warp_mat, warp_dst.size());



















}

int main()
{

	test_affine_transformation() //仿射变换;
//	test_remap();	   //重映射
//	test_hough_transform();
	//test_laplace();
//	test_sobel();
//	test_canny();
}