#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;

Mat RotateImage(Mat image, double degree_angle)
{
	// �������� ������, ��������� �� ����� � ��������� �������� �������
	Mat new_image = cv::Mat::zeros(Size(image.cols, image.rows), CV_8UC3);

	// ������� ���� � ��������
	double angle = degree_angle * CV_PI / 180;

	// ������� ������ ����, ������������ �������� ����� ���������� �������
	double xc = 0.5 * (image.cols - 1);
	double yc = 0.5 * (image.rows - 1);

	int xn, yn;
	for (int x = 0; x < new_image.cols; x++)
	{
		for (int y = 0; y < new_image.rows; y++)
		{
			// �������� �������������� ���������� ������� �������
			xn = xc + (x - xc) * cos(angle) - (y - yc) * sin(angle);
			yn = yc + (x - xc) * sin(angle) + (y - yc) * cos(angle);

			if (xn >= 0 && xn <= image.cols - 1 && yn >= 0 && yn <= new_image.rows - 1)
			{
				new_image.at<Vec3b>(y, x) = image.at<Vec3b>(yn, xn);
			}
		}
	}
	return new_image;
}

int main() 
{
	// ������ �����������
	Mat image = imread("B:/PRGNG/STC/Rotate_Image/images/WhataTwist.png");
	
	/*
	// ������� ����������� ������� ������� �� ���������
	Point2f center(new_image.cols / 2, new_image.rows / 2);
	double angle = 90;
	double scale = 1;
	Mat matrix = getRotationMatrix2D(center, angle, scale);
	std::cout << matrix << std::endl;
	Mat destMat;
	std::cout << destMat << std::endl;
	warpAffine(new_image, destMat, matrix, new_image.size());
	*/
	
	// ������� ���� � ��������
	double degree_angle;
	std::cin >> degree_angle;
	Mat OutputImage = RotateImage(image, degree_angle);

	// ����������� ������������� ����������� � �����������
	imshow("Original", image);
	imshow("Result", OutputImage);
	waitKey(0);

	return 0;
};
