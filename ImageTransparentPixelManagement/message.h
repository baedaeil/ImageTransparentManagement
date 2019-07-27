#pragma once
#include <iostream>
#include <string>

class Message {
private:
	std::string credit_name = ".";
	std::string blogURL = ".";
	std::string version = "1.0.2";

public:
	void message_Credit() {
		std::cout << "Image transparent pixel manage Program" << std::endl;
		std::cout << " Program version " << version << std::endl;
		std::cout << " * credit by _" << credit_name << std::endl;
		std::cout << " * blogs : " << blogURL << std::endl << std::endl;
	}

	void message_HowToUse() {
		std::cout << std::endl;
		std::cout << "<How to use>" << std::endl;
		std::cout << "press 'R' Key : transparent convert" << std::endl;
		std::cout << "press 'S' Key : save convert image" << std::endl;
		std::cout << "press 'ESC' Key : return program" << std::endl << std::endl;
	}
};
