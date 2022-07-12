#include "Test.h"
#include <fstream>

CTest::CTest()
{
	m_Num = 0;
}

CTest::~CTest()
{

}

void CTest::readFile(const std::string& vFileName)
{
	std::ifstream InFile(vFileName.c_str());

	if (InFile.is_open())
	{
		std::string LenStr;
		while (getline(InFile, LenStr))
		{
			unsigned int Found = 0;
			int Pos = 0;
			std::vector<std::string> TempVec;
			for (unsigned int i = 0; i < LenStr.length() / 2; ++i)
			{
				Found = LenStr.find(' ', Pos);
				std::string TempData = LenStr.substr(Pos, Found - Pos);
				TempVec.push_back(TempData);
				Pos = Found + 1;
			}
			m_Vec.push_back(TempVec);
			count++;
		}

	}
}

unsigned int CTest::getNum()
{
	return count;
}