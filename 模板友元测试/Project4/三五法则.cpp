#include <iostream>
#include <string>
using namespace std;
class person
{
public:
	std::string *name;
	int age;

	person(const char* the_name, int the_age)
	{
		name = new std::string(the_name);
		age = the_age;
	}

	~person()
	{
		delete name;
	}
};
person f(person p) {
	person ret = p;
	return ret;
}
int main(void)
{
	person a("me", 20);
	f(a);
	//std::cout << *a.name << std::endl;

	return 0;
}

