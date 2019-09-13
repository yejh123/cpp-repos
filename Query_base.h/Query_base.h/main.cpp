
#include "textquery.h"

int main(int argc, char *argv[])
{
	std::ifstream is("file.txt");
	TextQuery t1(is);
	std::string word;
	Query q = Query("fiery") | Query("wind");
	std::cout << q << std::endl;
	std::cout << q.eval(t1) << std::endl;

	return 0;
}
