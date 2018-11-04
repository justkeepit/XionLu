

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

char *src_path = "C:\\Users\\dell\\Desktop\\1.jpg";


Mat map_x, map_y;

char *remap_window = "Remap demo";
int ind = 0;



char *source_window = "Source Image";
char *warp_window = "Warp Image";
char *warp_rotate_window = "Warp + Rotate";




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


//dstTri[0] = Point2f(src.cols*0.0, src.rows*0.5);
//dstTri[2] = Point2f(src.cols*0.5, src.rows-1);
//dstTri[1] = Point2f(0, src.rows*0.5);

	dstTri[0] = Point2f(src.cols*0.0, src.rows*0.5);
	dstTri[1] = Point2f(src.cols*0.5, 0);
	dstTri[2] = Point2f(src.cols*0.5, src.rows-1);

	warp_mat = getAffineTransform(srcTri, dstTri);

	warpAffine(src, warp_dst, warp_mat, warp_dst.size());


	Point center = Point(warp_dst.cols / 2, warp_dst.rows / 2);

	double angle = -90.0;
	double scale = 0.6;

	rot_mat = getRotationMatrix2D(center, angle, scale);

	warpAffine(warp_dst, warp_rotate_dst, rot_mat, warp_dst.size());


	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src);

	namedWindow(warp_window, CV_WINDOW_AUTOSIZE);
	imshow(warp_window, warp_dst);

	namedWindow(warp_rotate_window, CV_WINDOW_AUTOSIZE);
	imshow(warp_rotate_window, warp_rotate_dst);

	/// 等待用户按任意按键退出程序
	waitKey(0);

}





void test_equalizeHist()
{
	Mat src, dst;
	char *source_window = "source image";
	char *equalized_window = "Equalized image";

	src = imread(src_path);

	cvtColor(src, src, CV_BGR2GRAY);

	equalizeHist(src, dst);

	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);

	imshow(source_window, src);
	imshow(equalized_window, dst);


	waitKey(0);

	return;
}

void test_draw_hist()
{
	Mat src, dst;
	src = imread(src_path);

	vector<Mat> rgb_planes;
	split(src, rgb_planes);

	int histSize = 255;

	float range[] = { 0,255 };
	const float * histRange = { range };

	bool uniform = true;
	bool accumulate = false;

	Mat r_hist, g_hist, b_hist;

	calcHist(&rgb_planes[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&rgb_planes[2], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);


	int hist_w = 400;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));

	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());


	for (int i=1;i<histSize;i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);

		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);


		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);

	}

	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);

	waitKey(0);

	return;
}


void test_compareHist()
{
	Mat src_base, hsv_base;
	Mat src_test1, hsv_test1;
	Mat src_test2, hsv_test2;
	Mat src_test3, hsv_test3;

	Mat hsv_half_down;

	const char *base_1_wan_path = "C:\\Users\\dell\\Desktop\\fdfd\\000.png";
	const char *test_1_wan_path = "C:\\Users\\dell\\Desktop\\fdfd\\01.png";
	const char *test_2_wan_path = "C:\\Users\\dell\\Desktop\\fdfd\\03.png";
	const char *test_2_tiao_path = "C:\\Users\\dell\\Desktop\\fdfd\\12.png";



	src_base = imread(base_1_wan_path);
	src_test1 = imread(test_1_wan_path);
	src_test2 = imread(test_2_wan_path);
	src_test3 = imread(test_2_tiao_path);

	cvtColor(src_base, hsv_base, CV_BGR2HSV);
	cvtColor(src_test1, hsv_test1, CV_BGR2HSV);
	cvtColor(src_test2, hsv_test2, CV_BGR2HSV);
	cvtColor(src_test3, hsv_test3, CV_BGR2HSV);



	hsv_half_down = hsv_base(Range(hsv_base.rows / 2, hsv_base.rows - 1), Range(0, hsv_base.cols - 1));

	int h_bins = 50; int s_bins = 60;
	int histSize[] = { h_bins,s_bins };

	float h_ranges[] = { 0,256 };
	float s_ranges[] = { 0,180 };

	const float* ranges[] = { h_ranges, s_ranges };

	// 使用第0和第1通道
	int channels[] = { 0, 1 };

	/// 直方图
	MatND hist_base;
	MatND hist_half_down;
	MatND hist_test1;
	MatND hist_test2;
	MatND hist_test3;

	/// 计算HSV图像的直方图
	calcHist(&hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
	normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsv_half_down, 1, channels, Mat(), hist_half_down, 2, histSize, ranges, true, false);
	normalize(hist_half_down, hist_half_down, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
	normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsv_test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false);
	normalize(hist_test2, hist_test2, 0, 1, NORM_MINMAX, -1, Mat());


	calcHist(&hsv_test3, 1, channels, Mat(), hist_test3, 2, histSize, ranges, true, false);
	normalize(hist_test3, hist_test3, 0, 1, NORM_MINMAX, -1, Mat());

	///应用不同的直方图对比方法
	for (int i = 0; i < 6; i++)
	{
		int compare_method = i;
		double base_base = compareHist(hist_base, hist_base, compare_method);
		double base_half = compareHist(hist_base, hist_half_down, compare_method);
		double base_test1 = compareHist(hist_base, hist_test1, compare_method);
		double base_test2 = compareHist(hist_base, hist_test2, compare_method);
		double base_test3 = compareHist(hist_base, hist_test3, compare_method);

		printf(" Method [%d] Perfect, Base-Half, Base-Test(1), Base-Test(2) : %f, %f, %f, %f ,%f\n", i, base_base, base_half, base_test1, base_test2, base_test3);
	}

	printf("Done \n");

	return;
}

Mat img, templ, result;

char * templ_src_path = "";

char *image_window = "Source Image";
char *result_window = "Result windows";

int match_method;

int max_Trackbar = 5;




void MathchingMethod(int, void *)
{
	Mat img_display;
	img.copyTo(img_display);

	int result_cols = img.cols - templ.cols + 1;
	int result_rows = img.rows - templ.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);

	matchTemplate(img, templ, result, match_method);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());


	double minVal; double maxVal; 
	Point minLoc; Point maxLoc;
	Point matchLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	/// 对于方法 SQDIFF 和 SQDIFF_NORMED, 越小的数值代表更高的匹配结果. 而对于其他方法, 数值越大匹配越好
	if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
	{
		matchLoc = minLoc;
	}
	else
	{
		matchLoc = maxLoc;
	}

	/// 让我看看您的最终结果
	rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(0,0,255), 2, 8, 0);
	rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(0,255,0), 2, 8, 0);

	imshow(image_window, img_display);
	imshow(result_window, result);

	return;
}

void test_matchTemplate()
{
	templ_src_path = "C:\\Users\\dell\\Desktop\\card_res\\res\\cards25d\\gexing_biaozhun\\hand_0\\29.png";
	src_path = "C:\\Users\\dell\\Desktop\\card_res\\gexing_biaozhun_25d_debug.png";
	img = imread(src_path);
	templ = imread(templ_src_path);

	namedWindow(image_window, WINDOW_NORMAL);
	namedWindow(result_window, WINDOW_NORMAL);


	char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
	createTrackbar(trackbar_label, image_window, &match_method, max_Trackbar, MathchingMethod);

	MathchingMethod(0, 0);

	waitKey(0);
	return;

	
}

char *src_find_path = "C:\\Users\\dell\\Desktop\\1.jpg";
Mat find_src, find_gray_dst;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);



void threshold_callback1(int,void *)
{
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	Canny(find_gray_dst, canny_output, 40, thresh * 2, 3);

	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);

	for (int i=0;i<contours.size();i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);


}

void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// 用Canny算子检测边缘
	Canny(find_gray_dst, canny_output, thresh, thresh * 2, 3);
	/// 寻找轮廓
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// 绘出轮廓
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	/// 在窗体中显示结果
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
}

void test_findContours_drawContours()
{
	find_src = imread(src_find_path);
	cvtColor(find_src, find_gray_dst, CV_BGR2GRAY);
	blur(find_gray_dst, find_gray_dst, Size(3, 3));

	char *source_window = "Soucre";
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window,find_src);


	createTrackbar("canny thresh:", "Source", &thresh, max_thresh, thresh_callback);

	thresh_callback(0,0);

	waitKey(0);

	return;

}

int main()
{
	
	test_findContours_drawContours();
//	test_matchTemplate();
//	test_compareHist();
//	test_draw_hist();
//	test_equalizeHist();
//	test_affine_transformation(); //仿射变换;
//	test_remap();	   //重映射
//	test_hough_transform();
	//test_laplace();
//	test_sobel();
//	test_canny();
}