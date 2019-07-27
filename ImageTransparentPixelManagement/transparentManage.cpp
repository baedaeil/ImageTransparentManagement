#include "message.h"
#include "imageManage.h"

void main() {
	std::string location;
	ImageManage manage;
	Message message_;
	Mat temp;
	int conv_text_index = 0;

	while (true) {
		system("cls");
		message_.message_Credit();

		while (true) {
			cout << "Input image file location : ";
			getline(cin, location);

			while (location.find("\"") != string::npos)
				location.replace(location.find("\""), 1, "\0");

			while (location.find("\\") != string::npos) {
				conv_text_index = location.find("\\");
				location.replace(conv_text_index, 1, "/");
			}
			/*
			for (int count = 0; count < location.length(); count++) {
				if (location[count] == '\\') {
					location[count] = '/';
					conv_text_index = count;
				}
			}
			*/

			ImageManage temp(location, conv_text_index);
			manage = temp;

			if (manage.getOriginalImg().empty())
				cout << "can't find image file..." << endl << endl;

			else if (manage.getOriginalImg().channels() != 4)
				cout << "The image does not support transparent images." << endl << endl;

			else break;
		}


		message_.message_HowToUse();

		while (true) {
			imshow(PROG_NAME, manage.getResizeImg());
			imshow(CONTROLLER_NAME, manage.getTransController());
			createTrackbar("TP", CONTROLLER_NAME, manage.getTransparent(), 255);

			int key = waitKey(100);

			if (key == 'R' || key == 'r') {
				manage.returnImage(); manage.convertImage();
				cout << "Resize complete!" << endl;
			}

			else if (key == 'S' || key == 's') {
				manage.saveResizeImage();
				cout << "Save complete!" << endl;
			}

			else if (key == 27) {
				destroyWindow(PROG_NAME);
				destroyWindow(CONTROLLER_NAME);
				break;
			}
		}
	}
}
