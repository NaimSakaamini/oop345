#include <iostream>
#include "CString.h"
#include "process.h"


void process(char* str, std::ostream & os)
{
	w1::CString string(str);
	os << string << std::endl;
}
