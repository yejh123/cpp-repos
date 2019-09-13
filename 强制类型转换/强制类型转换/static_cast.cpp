/* 常规的使用方法 */
float f_pi = 3.141592f;
int   i_pi = static_cast<int>(f_pi); /// i_pi 的值为 3

/* class 的上下行转换 */
class Base {
	// something
};
class Sub :public Base {
	// something
};
int main() {
	//  上行 Sub -> Base
	//编译通过，安全
	Sub sub;
	Base *base_ptr = static_cast<Base*>(&sub);

	//  下行 Base -> Sub
	//编译通过，不安全
	Base base;
	Sub *sub_ptr = static_cast<Sub*>(&base);
}