#pragma once
#ifndef PLUSANDSUBTRACTION

#include <iostream>
#include <string>
using namespace std;

string plusHelper(string s1, string s2, int n1, int n2);
string myPlusAndSubtraction(string s1, string s2, char sign);
string subtractionHelper(string s1, string s2, int n1, int n2);
string eraseComma(string s);
string addComma(string s);
bool allZero(string s);

string getInteger(string s);
string getDecimal(string s);
void standard(string & decimal, int length);
string pointOperation(string s1, string s2, char sign);
#endif // !PLUSANDSUBTRACTION