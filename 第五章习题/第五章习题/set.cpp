#include "set.h"
void setPut(setType S)
{
	unsigned x;
	cin >> x;
	while (x)
	{
		putX(S, x);
		cin >> x;
	}
}
void setDisplay(setType S)
{
	if (Null(S))
		cout << "集合是空集" << endl;
	else
	{
		cout << "{";
		for (unsigned i = 0; i != N; ++i)
		{
			unsigned mask = 1;
			for (unsigned c = 1; c <= 32; ++c)
			{
				if (mask & S[i])
				{
					cout << i * 32 + c << ",";
				}
				mask <<= 1;
			}
		}
		cout << "\b}\n";
	}
	
}
void putX(setType S, unsigned x)
{
	unsigned mask = 1;
	mask <<= (x - 1) % 32;
	S[(x - 1) / 32] |= mask;

}
void Com(setType C, const setType A, const setType B)         //求并集
{
	for (unsigned i = 0; i != N; ++i)
	{
		C[i] = A[i] | B[i];
	}
}
void setInt(setType C, const setType A, const setType B)         //求交集
{
	for (unsigned i = 0; i != N; ++i)
	{
		C[i] = A[i] & B[i];
	}
}
void setDiff(setType C, const setType A, const setType B)            //求差集
{
	for (unsigned i = 0; i != N; ++i)
	{
		C[i] = A[i] & (~B[i]);
	}
}
bool Inc(const setType A, const setType B)              //判A包含于B
{
	bool bl = 1;
	for (unsigned i = 0; i != N; ++i)
	{
		if (!(A[i] | B[i] == B[i]))
			bl = 0;
	}
	if (bl)
		return 1;                               // cout << "前者包含于后者" << endl;
	else
		return 0;                                 // cout << "前者不包含于后者" << endl;
}
bool In(const setType S, unsigned x)                    //判x属于S；
{
	unsigned mask = 1;
	mask <<= (x - 1) % 32;
	if (mask & S[(x - 1) / 32])
	{
		return 1;
	}
	else return 0;
}
bool Null(const setType S)                         //判空集
{
	for (int i = 0; i != N; ++i)
	{
		if (S[i])
			return 0;                        //不是空集
	}
	return 1;                                //是空集
}

