#pragma once
#ifndef MESSAGE_FOLDER_H
#define MESSAGE_FOLDER_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Folder;
struct Message {
	friend struct Folder;
private:
	string contents;
	set<Folder *> folders;
//工具函数
	void add_to_Folders(const Message &);
	void remove_from_Folders();
public:
//构造函数
	Message(const string &s = "") :contents(s) {}
//拷贝构造函数
	Message(const Message &m);
//拷贝赋值运算符
	Message & operator= (const Message &m);
//析构函数
	~Message();
//接口函数
	void save(Folder &f);
	void remove(Folder &f);
};



struct Folder {
	friend struct Message;
private:
	set<Message *> messages;
};


void Message::save(Folder &f) {
	folders.insert(&f);
	f.messages.insert(this);
}
void Message::remove(Folder &f) {
	folders.erase(&f);
	f.messages.erase(this);
}
void Message::add_to_Folders(const Message &m) {
	for (auto a = m.folders.begin(); a != m.folders.end(); ++a) {
		(*a)->messages.insert(this);
	}
}
void Message::remove_from_Folders() {
	for (auto a = folders.begin(); a != folders.end(); ++a) {
		(*a)->messages.erase(this);
	}
}
Message::Message(const Message &m) {
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
}
Message & Message::operator= (const Message &m) {
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}
Message::~Message() {
	remove_from_Folders();
}
#endif // !MESSAGE_FLODER_H
