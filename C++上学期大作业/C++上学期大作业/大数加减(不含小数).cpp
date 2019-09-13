/*
2
+
1,111,111,111,111,111,111,111,111,111,111,111,111
222,222,222,222,222,222,222,222,222,222,222,222
+
-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
 
#include<iostream>
#include<string>
using namespace std;
string plusHelper(string s1, string s2, int n1, int n2);
string myPlusAndSubtraction(string s1, string s2, char sign);
string subtractionHelper(string s1, string s2, int n1 , int n2);
bool allZero(string s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != '0')
			return false;
	}
	return true;
}
string eraseComma(string s)
{
	int index;
	while (index = s.find(','), index > 0)
	{
			s.erase(index, 1);
	}
	return s;
}
string addComma(string s)
{
	int count = 0;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		++count;
		if (i != 0 && s[i-1] != ',' && count == 3)
		{
			count = 0;
			s.insert(i, 1, ',');
			
		}
	}
	return s;
}
string myPlusAndSubtraction(string s1, string s2, char sign)
{
	string left = eraseComma(s1);
	string right = eraseComma(s2);
	string result, finalResult;
	int leftSize = left.size();
	int rightSize = right.size();
	if (sign == '+')
	{
		if (left[0] == '-' && right[0] == '-')
		{
			left.erase(0,1);
			right.erase(0,1);
			--leftSize;
			--rightSize;
			if (leftSize >= rightSize)
			{
				result = plusHelper(left, right, leftSize, rightSize);
			}
			else
			{
				result = plusHelper(right, left, rightSize, leftSize);
			}
			result.insert(0, 1, '-');
		}
		else if (left[0] == '-')
		{
			left.erase(0,1);
			--leftSize;
			if (leftSize > rightSize)
			{
				result = subtractionHelper(left, right, leftSize, rightSize);
				result.insert(0, 1, '-');
			}
			else
			{
				result = subtractionHelper(right, left, rightSize, leftSize);
			}
		}
		else if (right[0] == '-')
		{
			right.erase(0,1);
			--rightSize;
			if (leftSize >= rightSize)
			{
				result = subtractionHelper(left, right, leftSize, rightSize);
			}
			else
			{
				result = subtractionHelper(right, left, rightSize, leftSize);
				result.insert(0, 1, '-');
			}
		}
		else
		{
			if (leftSize >= rightSize)
			{
				result = plusHelper(left, right, leftSize, rightSize);
			}
			else
			{
				result = plusHelper(right, left, rightSize, leftSize);
			}
		}
	}
	if (sign == '-')
	{
		if (left[0] == '-' && right[0] == '-')
		{
			left.erase(0,1);
			right.erase(0,1);
			--leftSize;
			--rightSize;
			if (leftSize > rightSize)
			{
				result = subtractionHelper(left, right, leftSize, rightSize);
				result.insert(0, 1, '-');
			}
			else
			{
				result = subtractionHelper(right, left, rightSize, leftSize);
			}
		}
		else if (left[0] == '-')
		{
			left.erase(0,1);
			--leftSize;
			if (leftSize >= rightSize)
			{
				result = plusHelper(left, right, leftSize, rightSize);
			}
			else
			{
				result = plusHelper(right, left, rightSize, leftSize);
			}
			result.insert(0, 1, '-');
		}
		else if (right[0] == '-')
		{
			right.erase(0,1);
			--rightSize;
			if (leftSize >= rightSize)
			{
				result = plusHelper(left, right, leftSize, rightSize);
			}
			else
			{
				result = plusHelper(right, left, rightSize, leftSize);
			}
		}
		else
		{
			if (leftSize >= rightSize)
			{
				result = subtractionHelper(left, right, leftSize, rightSize);
			}
			else
			{
				result = subtractionHelper(right, left, rightSize, leftSize);
				result.insert(0, 1, '-');
			}
		}
	}
	finalResult = addComma(result);
	return finalResult;
}
string plusHelper(string s1, string s2, int n1,int n2)
{
	string result;
	bool carry = 0;
	--n1, --n2;
	while(n1>= 0)
	{
		char c;
		
		if (n2 >= 0)
		{
			c = s1[n1--] + s2[n2--] + carry - 48;
		}
		else
		{
			c = s1[n1--] + carry;
		}
		if (c >= 58)
		{
			c -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result.insert(0, 1, c);
		
	}
	if (carry)
		{
			result.insert(0, 1, '1');
		}
	return result;
}
string subtractionHelper(string s1, string s2, int n1, int n2)       //默认是大数减小数
{
	string result;
	bool carry = 0;          //carry表示是否退位
	--n1, --n2;
	while (n1 >= 0)
	{
		char c;

		if (n2 >= 0)
		{
			c = s1[n1--] - s2[n2--] - carry + 48;
		}
		else
		{
			c = s1[n1--] - carry;
		}
		if (c < 48)
		{
			c += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result.insert(0, 1, c);
	}
	if (carry == 1)
	{
		int i;
		for (i = 0; i < result.size() - 1; ++i)
		{
			result[i] = 105 - result[i] ;
		}
		result[i] = 106 - result[i];
		result.insert(0, 1, '-');
	}
	if (allZero(result))
	{
		return "0";
	}
	return result;
	
}
/*
int main()
{
	int n;
	char sign;
	string s1, s2;
	while (cin>>sign)
	{
		cin >> s1 >> s2;
		string result = myPlusAndSubtraction(s1, s2, sign);

		cout << result << endl;
	}
}
*/