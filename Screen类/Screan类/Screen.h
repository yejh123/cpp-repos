#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Screen {
	friend struct Window_mge;
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default;
	Screen(unsigned h, unsigned w) :height(h), width(w),contents(w*h,' ') {}
	Screen(unsigned h, unsigned w,char c):height(h), width(w), contents(w*h,c) {}
	Screen &move(unsigned r, unsigned l) {
		cursor = r * width;
		return *this;
	}
	Screen &set(char c) { 
		contents[cursor] = c; 
		return *this;
	}
	Screen &set(unsigned r, unsigned l, char c) {
		contents[r*width + l] = c;
		return *this;
	}
	void display(ostream &os) {
		os << this->contents;
		//return os;
	}
};
struct Window_mge {
private:
	vector<Screen>  Screens{ Screen(24,80,'X') };
public:
	Screen & clear(unsigned);
	Screen & set(unsigned, unsigned, unsigned, char);
	void print(unsigned u) {
		auto beg = Screens[u].contents.begin();
		for (; beg != Screens[u].contents.end(); ++beg)
			cout << *beg;
		cout << endl;
	}

};
Screen &Window_mge::clear(unsigned i){
	Screen &s = Screens[i];
	s.contents = ( s.height * s.width,' ' );
	return s;
}
Screen &Window_mge::set(unsigned i, unsigned r, unsigned l,char c) {
	Screen &s = Screens[i];
	s.set(r, l, c);

	return s;
}