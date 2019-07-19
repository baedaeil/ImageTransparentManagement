#pragma once
#include "basic.h"

class ImageManage {

private:
	int textIndex;
	int setTransparent;
	std::string location;
	Mat original_img;
	Mat resize_img;
	Mat transController;


public:
	ImageManage() {};
	ImageManage(std::string location, int textIndex) {
		
		this->textIndex = textIndex;
		this->location = location;

		original_img = imread(location,IMREAD_UNCHANGED);

		resize_img = original_img.clone();
		setTransparent = 255;

		transController = Mat(Size(600, 150), CV_8UC3, Scalar(0, 0, 0));
		putText(transController, "R Key : Transparent convert", Point(20, 40), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 255));
		putText(transController, "S Key : Save convert image", Point(20, 80), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 255));
		putText(transController, "ESC Key : Return program", Point(20, 120), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 255));
	}

	Mat getOriginalImg() { return original_img; }
	Mat getResizeImg() { return resize_img; }
	Mat getTransController() { return transController; }
	int *getTransparent() { return &setTransparent; }
	void returnImage() { resize_img = original_img.clone(); }
	void convertImage() {
		for (int col = 0; col < resize_img.cols; col++) {
			for (int row = 0; row < resize_img.rows; row++) {
				if (resize_img.at<Vec4b>(row, col)[3] >= setTransparent)
					resize_img.at<Vec4b>(row, col)[3] = 255;

				else resize_img.at<Vec4b>(row, col) = Scalar::all(0);
			}
		}
	}

	void saveResizeImage() {
		std::string temp = location;
		temp.insert(textIndex + 1, "convert_");
		imwrite(temp, resize_img);
	}
};
