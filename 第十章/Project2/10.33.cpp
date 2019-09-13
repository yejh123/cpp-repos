#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

void f(const string &input, const string &output1, const string &output2)
{
	ifstream in(input);
	ofstream out1(output1,ofstream::app),out2(output2,ofstream::app);

	istream_iterator<int> iti(in),eof;
	ostream_iterator<int> osi1(out1," "), osi2(out2,"\n");
	while (iti != eof) {
		if (*iti % 2)              //ÆæÊý
			*osi1++ = *iti;
		else *osi2++ = *iti;       //Å¼Êý
		++iti;
	}
	
}
int main (){
	f("data","output1","output2");
}