#pragma once //instead of #ifndef
#include <iostream>
namespace w1
{
	class CString
	{
    
	public:
        static const int MAX = 3;
		CString(char* str);
		void display(std::ostream& os);
        
    private:
        char string[MAX+1];
	};

	std::ostream& operator<< (std::ostream& os, CString& str);
}
