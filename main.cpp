#include <iostream>
#include <string>
#include <vector>
#include "FtVector.hpp"

int main()
{
	FtVector<int> bg;

	bg.push_back(1);
	bg.push_back(7);
	//bg.pop_back();
	bg.push_back(8);
	std::cout << bg[0] << " " << bg[1] << " " << bg[2] << '\n';
	return 0;
}