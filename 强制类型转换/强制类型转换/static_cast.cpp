/* �����ʹ�÷��� */
float f_pi = 3.141592f;
int   i_pi = static_cast<int>(f_pi); /// i_pi ��ֵΪ 3

/* class ��������ת�� */
class Base {
	// something
};
class Sub :public Base {
	// something
};
int main() {
	//  ���� Sub -> Base
	//����ͨ������ȫ
	Sub sub;
	Base *base_ptr = static_cast<Base*>(&sub);

	//  ���� Base -> Sub
	//����ͨ��������ȫ
	Base base;
	Sub *sub_ptr = static_cast<Sub*>(&base);
}