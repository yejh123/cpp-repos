/*
63.57 63.58 63.55 63.56 63.56 63.65 63.54 63.57 63.57 63.55 0 0.01 0.05
*/
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

double getReverage(vector<double> data)
{
	double total = 0;
	for (double d : data)
	{
		total += d;
	}
	return total / data.size();
}
double getStandardDeviation(vector<double> data)
{
	double reverage = getReverage(data);
	double n = 0;
	for (double d : data)
	{
		n += pow(d - reverage, 2);
	}
	return sqrt(n / (data.size() - 1));
}
map<pair<int, double>, double> initialize()
{
	map<pair<int, double>, double> g;
	double d[] = { 1.45, 1.67, 1.82, 1.94, 2.03, 2.11, 2.18, 2.23, 2.28, 1.49, 1.75, 1.94, 2.10, 2.22, 2.32, 2.41, 2.48, 2.55 };
	int index = 0;
	for (int i = 4; i <= 12; ++i)
	{
		pair<int, double> p(i, 0.05);
		g[p] = d[index++];
	}
	for (int i = 4; i <= 12; ++i)
	{
		pair<int, double> p(i, 0.01);
		g[p] = d[index++];
	}
	return g;
}
bool check(vector<double>& data, map<pair<int, double>, double> g, double percent)
{
	bool bl = 1;
	double reverage = getReverage(data);
	double s = getStandardDeviation(data);
	pair<int, double> p(data.size(), percent);
	double d = g[p];
	for (auto it = data.begin(); it < data.end();)
	{
		if (abs(*it - reverage) / s > d)
		{
			cout << "Ҫ�޳�������:" << *it << ", g" << it - data.begin() + 1 << "=" << abs(*it - reverage) / s << endl;
			it = data.erase(it);
			bl = 0;
		}
		else
			++it;
	}
	return bl;
}
void begin(vector<double>& data, double percent, double mistake)
{
	map<pair<int, double>, double> g = initialize();
	double reverage = getReverage(data);
	double standardDeviation = getStandardDeviation(data);
	cout << "�޳�ǰ  reverage=" << reverage << ", s=" << standardDeviation << endl;
	bool bl = check(data, g, percent);
	int count = 1;
	while(!bl)
	{
		bl = check(data, g, percent);
		reverage = getReverage(data);
		standardDeviation = getStandardDeviation(data);
		cout << "�޳���"<<count<<"��  reverage=" << reverage << ", s=" << standardDeviation << endl;
		++count;
	} 
	double uA = standardDeviation / sqrt(data.size());
	double uB = mistake / sqrt(3);
	double u = sqrt(uA * uA + uB * uB);
	cout << "A���׼��ȷ����Ϊ:"<<uA<<"\nB���׼��ȷ����Ϊ:"<<uB<<"\n���������ʾΪ:" << reverage << " +- " << u << endl;
}
int main()
{
	vector<double> data;
	cout << "����������(��0������:" ;
	double d;
	double percent;
	double mistake;
	while (cin >> d)
	{
		if (d == 0)
			break;
		data.push_back(d);
	}
	cout << "����������ˮƽ:" ;
	cin >> percent;
	cout << "�������������:";
	cin >> mistake;
	begin(data, percent, mistake);
}