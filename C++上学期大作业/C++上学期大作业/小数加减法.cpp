/*
  +
  1.5162
  -5.95

  1.5162 + (-5.95) = [1 + (-5)]  +  [0.5162 + (-0.95)]
                         -4                -0.4338
*/
#include <iostream>
#include <string>
#include <algorithm>
#include "任意数加减.h"
using namespace std;
string getInteger(string s)
{
	int point = s.find('.');
	string integer = s.assign(s, 0, point);
	return integer;
}
string getDecimal(string s)
{
	int point = s.find('.');
	string decimal = s.substr(point + 1);
	if (s[0] == '-')
		decimal.insert(0, 1, '-');
	return decimal;
}
void standard(string & decimal, int length)
{
	if (decimal[0] == '-')
	    decimal.append(length - decimal.size() + 1, '0');
	else
		decimal.append(length - decimal.size(), '0');
}
string pointOperation(string s1, string s2, char sign)
{
	string leftInteger = getInteger(s1);
	string leftDecimal = getDecimal(s1);
	string rightInteger = getInteger(s2);
	string rightDecimal = getDecimal(s2);
	//小数标准化
	int leftDecimalLength = leftDecimal.size();
	if (leftDecimal[0] == '-')
		leftDecimalLength--;
	int rightDecimalLength = rightDecimal.size();
	if (rightDecimal[0] == '-')
		rightDecimalLength--;

	int deff = leftDecimalLength - rightDecimalLength;
	if (deff < 0)
		standard(leftDecimal, rightDecimalLength);
	else if (deff > 0)
		standard(rightDecimal, leftDecimalLength);

	//整数部分加减法
	string integer = myPlusAndSubtraction(leftInteger, rightInteger, sign);
	//小数部分加减法
	string decimal = myPlusAndSubtraction(leftDecimal, rightDecimal, sign);
	decimal = eraseComma(decimal);
	cout << "leftInteger=" << leftInteger << ", rightInteger=" << rightInteger <<  ", integer=" << integer << "\nleftDecimal=" << leftDecimal << ", rightDecimal=" << rightDecimal << ", decimal=" << decimal << endl;

	bool carry = 0;
	if ((leftDecimal[0] == '-' && rightDecimal[0] == '-') || (leftDecimal[0] != '-' && rightDecimal[0] != '-'))
	{
		if(decimal.size() > max(leftDecimalLength, rightDecimalLength))
			carry = 1;
	}
	
	//连接整数和小数
	string result = integer;
	if (integer[0] != '-' && decimal[0] != '-')
	{
		if (carry == 1)
		{
			result = myPlusAndSubtraction(integer, "1", '+');
		}
		result += "." + decimal;
	}
	return result;
}

int main()
{
	string s1 = "1.5162";
	string s2 = "5.95";
	string integer = getInteger(s1);
	cout << "integer = " << integer << endl;
	cout<< pointOperation(s1, s2, '+');
}
