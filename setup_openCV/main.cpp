#include<stdio.h>
#include "CLU.h"
#include<iostream>
#include"s1.h"
#include<opencv2/opencv.hpp>
#include <windows.h>

using namespace std;
using namespace cv;

void gotoxy(int x, int y) // 将光标移到指定位置
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	std::string s = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:.\"^`'  ";
	//std::cout << s.length();
	//return 0;
	//vector<double>a{ 100, 100, 100 };
	//double r = 120;
	vector<double>a{ 30, 30, 50 };
	double r = 45;
	block myblock = block(a, r);
	vector<double>vl{ 1,1,1 };
	myblock.setLight(vl);

	int size = 64;

	// 创建一个空白画布
	Mat canvas(size, size, CV_8UC3, Scalar(255, 255, 255));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int length = 0; length < 128; length++)
			{
				vector<double>lightvec{ double(i),double(j),length * 0.1 };
				if (myblock.isInside(lightvec))
				{
					double Brightness = -inMul(NormalizeVec(vl), NormalizeVec(myblock.NormalVec(lightvec)));
					if (Brightness<=0.0)
					{
						double c = 0.0;
						canvas.at<Vec3b>(i, j)[0] = c; // blue channel
						canvas.at<Vec3b>(i, j)[1] = c; // green channel
						canvas.at<Vec3b>(i, j)[2] = c; // red channel
						//gotoxy(j*2, i);
						//std::cout << "  ";
					}
					else 
					{
						double c = 255 * pow(Brightness, 0.6);
						canvas.at<Vec3b>(i, j)[0] = c;
						canvas.at<Vec3b>(i, j)[1] = c;
						canvas.at<Vec3b>(i, j)[2] = c;
						//gotoxy(j*2, i);
						//std::cout << s[int(c * 70 / 255)]<<" ";
					}
				}
				else
				{
					canvas.at<Vec3b>(i, j)[0] = 210;
					canvas.at<Vec3b>(i, j)[1] = 220;
					canvas.at<Vec3b>(i, j)[2] = 230;
					//gotoxy(j*2, i);
					//std::cout << "- ";
				}
			}
		}
		//std::cout << "\n";
		imshow("rend", canvas);
		if (waitKey(1) == 1)
		{
			break;
		}
	}
	Mat dst;
	int ksize = 4; // 设置卷积核大小为3x3
	blur(canvas, dst, Size(ksize, ksize));


	imshow("Canvas", dst);
	waitKey(0);
	destroyAllWindows();
	//std::cout << myblock.isInside(tmppos);
}