#include "Test.h"
#include <iostream>

int main()
{
	CTest* Test = new CTest;
	Test->readFile("F:\\Cfile\\Project2\\test.txt");
	std::vector<std::vector<std::string>> Vec;
	Vec = Test->getData();
	//显示第几行第几列数据
	std::cout << Vec[2][1] << std::endl;//如第三行第第二个数据
	//显示数据的个数
	std::cout << Test->getNum() << std::endl;
	system("pause");


	//double strDou(string str) {	//string 转换 double
	//	char* ch = new char[0];
	//	double d;
	//	for (int i = 0; i != str.length(); i++)
	//		ch[i] = str[i];
	//	d = atof(ch);
	//	return d;
	//}

	return 0;
}
