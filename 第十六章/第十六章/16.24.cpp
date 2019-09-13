#include "Blob.h"
int main()
{
	vector<string> vs{ "dsaho","hoq","vobq" };
	Blob<string> bs(vs.begin(), vs.end());
	for (auto b = bs.cbegin(); b != bs.cend(); ++b) {
		cout << *b << " ";
	}
}