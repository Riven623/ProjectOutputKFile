#include "Test.h"
#include <iostream>

int main()
{
	CTest* Test = new CTest;
	Test->readFile("F:\\Cfile\\Project2\\test.txt");
	std::vector<std::vector<std::string>> Vec;
	Vec = Test->getData();
	//��ʾ�ڼ��еڼ�������
	std::cout << Vec[2][1] << std::endl;//������еڵڶ�������
	//��ʾ���ݵĸ���
	std::cout << Test->getNum() << std::endl;
	system("pause");


	//double strDou(string str) {	//string ת�� double
	//	char* ch = new char[0];
	//	double d;
	//	for (int i = 0; i != str.length(); i++)
	//		ch[i] = str[i];
	//	d = atof(ch);
	//	return d;
	//}

	return 0;
}
