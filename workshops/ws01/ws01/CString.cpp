
#define _CRT_SECURE_NO_WARNINGS

#include "CString.h"
#include "CString.h"
#include <iostream>

int stored = w1::CString::MAX;
namespace w1 
{
    CString::CString(char* str)
    {
		if (str == nullptr)
		{
			string[0] = '\0';
		}
		else
		{
			strncpy(string, str, MAX);
			// string[MAX] = '\0';
		}
	}

	void CString::display(std::ostream& os)
	{
		os << string;
	}


	//helper function
	std::ostream& operator<<(std::ostream& os, CString& str) 
	{
		static int counter = 0;
        os << counter++ << ": ";
        str.display(os);
		return os;

	}

}
