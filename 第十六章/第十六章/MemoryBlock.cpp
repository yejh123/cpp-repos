#include <iostream>  

class MemoryBlock
{
public:

	// ����������ʼ����Դ��  
	explicit MemoryBlock(size_t length)				//���ι�����ʹ��explicit��������ת��
		: _length(length)
		, _data(new int[length])
	{
	}

	// ���������ͷ���Դ��  
	~MemoryBlock()
	{
		if (_data != nullptr)
		{
			delete[] _data;
		}
	}

	// ������������ʵ�ֿ������壺����that��  
	MemoryBlock(const MemoryBlock& that)
		// ����that������ӵ�е���Դ  
		: _length(that._length)
		, _data(new int[that._length])
	{
		std::copy(that._data, that._data + _length, _data);
	}

	// ������ֵ�������ʵ�ֿ������壺�ͷ�this �� ����that��  
	MemoryBlock& operator=(const MemoryBlock& that)
	{
		if (this != &that)
		{
			// �ͷ��������Դ  
			delete[] _data;

			// ����that������ӵ�е���Դ  
			_length = that._length;
			_data = new int[_length];
			std::copy(that._data, that._data + _length, _data);
		}
		return *this;
	}

	// �ƶ���������ʵ���ƶ����壺�ƶ�that��  
	MemoryBlock(MemoryBlock&& that)
		// ���������Դָ��ָ��that������ӵ�е���Դ  
		: _length(that._length)
		, _data(that._data)
	{
		// ��that����ԭ��ָ�����Դ��ָ����Ϊ��ֵ  
		that._data = nullptr;
		that._length = 0;
	}

	// �ƶ���ֵ�������ʵ���ƶ����壺�ͷ�this �� �ƶ�that��  
	MemoryBlock& operator=(MemoryBlock&& that)
	{
		if (this != &that)
		{
			// �ͷ��������Դ  
			delete[] _data;

			// ���������Դָ��ָ��that������ӵ�е���Դ  
			_data = that._data;
			_length = that._length;

			// ��that����ԭ��ָ�����Դ��ָ����Ϊ��ֵ  
			that._data = nullptr;
			that._length = 0;
		}
		return *this;
	}
private:
	size_t _length; // ��Դ�ĳ���  
	int* _data; // ָ����Դ��ָ�룬������Դ����  
};

MemoryBlock f() { return MemoryBlock(50); }

int main()
{
	MemoryBlock a = f();            // �����ƶ����������ƶ�����  
	MemoryBlock b = a;              // ���ÿ�������������������  
	MemoryBlock c = std::move(a);   // �����ƶ����������ƶ�����  
	a = f();                        // �����ƶ���ֵ��������ƶ�����  
	b = a;                          // ���ÿ�����ֵ���������������  
	c = std::move(a);               // �����ƶ���ֵ��������ƶ�����  
}