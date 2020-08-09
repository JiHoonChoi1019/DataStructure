#include "MyIntVector.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>


using namespace std;

MyIntVector::MyIntVector(size_t init_capacity)
{ //������
	data = new int[init_capacity];
	_capacity = init_capacity;
	_size = 0;
}


MyIntVector::~MyIntVector()
{ //�Ҹ���
	delete[] data;
}

MyIntVector::MyIntVector(const MyIntVector & v)
{ //���� ������
	data = new int[v._capacity];
	_capacity = v._capacity;
	_size = v._size;
	copy(v.data, v.data + _size, data);
}

MyIntVector& MyIntVector::operator=(const MyIntVector & v)
{ //���� ����
	int *new_data;
	if (this == &v)
		return *this;
	if (_capacity != v._capacity)
	{
		new_data = new int[v._capacity];
		delete[] data;
		data = new_data;
		_capacity = v._capacity;
	}
	_size = v._size;
	copy(v.data, v.data + _size, data);
	return *this;
}

void MyIntVector::operator+=(const MyIntVector & addend)
{//precondition : ��ü�� �־��ش�.
 //postconditon : ���� �ִ� ��ü1�� ��ü2�� �߰����ش�.
	if (_size + addend._size > _capacity)
		reserve(_size + addend._size);
	copy(addend.data, addend.data + addend._size, data + _size);
	_size += addend._size;

}

int & MyIntVector::operator[](int i)
{//precondition : ���ڿ� ������ �־��ش�.
 //postcondition : ������ �ε��� i�� ���� []������ ���� ���ڷ� �ٲ��ش�.
	return data[i];
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

MyIntVector MyIntVector::operator+(const MyIntVector & num)
{//precondition : �ٸ� ��ü�� �־��ش�.
 //postcondition : ��ü���� ���� �ε����� ���� �����ش�.
	MyIntVector n(_capacity);

	for (int m = 0; m < _size; m++) {
		n.data[m] = data[m] + num.data[m];
		n._size++;
	}
	
	return n;
}

MyIntVector MyIntVector::operator-(const MyIntVector & num)
{ //precondition : �ٸ� ��ü�� �־��ش�.
 //postcondition : ��ü���� ���� �ε����� ���� ���ش�.
	
	MyIntVector n(_capacity);
	
	for (int m = 0; m < _size; m++) {
		n.data[m] = data[m] - num.data[m];
		n._size++;
	}

	return n;
}

MyIntVector MyIntVector::operator*(const MyIntVector & num)
{//precondition : �ٸ� ��ü�� �־��ش�.
 //postcondition : ��ü���� ���� �ε����� ���� ������ ���� �� ���Ѵ�.
	MyIntVector n(_capacity);
	
	for (int m = 0; m < _size; m++) {
		n.data[m] = data[m] * num.data[m];
		n._size++;
	}
	int sum = 0;
	for (int k = 0; k < _size; k++) {
		sum += n.data[k];
		n.data[0] = sum;
	}

	return n;
}

bool MyIntVector::operator==(const MyIntVector & v)
{//precondition : �ٸ� ��ü�� �־��ش�.
 //postcondition : ��ü ���� ���� ũ�� ������ ���� �� ��,������ �����Ѵ�.
	MyIntVector n(_size); //_÷�� _size�߾���

	if (_size == v._size)
		return true;
	else 
		return false;
}

MyIntVector MyIntVector::operator-()
{//precondition : ���� ��ü�� �־��ش�.
 //postcondition : �ε����� �� ������ ��ȣ �ݴ� ó�����ش�.

	MyIntVector n(_capacity);
	int m;
	for (m = 0; m < _size; m++) {
		n.data[m] = - data[m];
		n._size++;
	}
	return n;
}


MyIntVector MyIntVector::operator()(int const & num)
{//precondition : �ٲ��� ���� ���� ���Ѵ�.
 //postcondition : �ε����� �� ������ ���� ���� ������ �ٲ��ش�.
	MyIntVector n(_capacity);
	for (int m = 0; m < _size; m++) {
		n.data[m] = num;
		n._size++;
	}
	return n;
}

void MyIntVector::pop_back()
{//precondition : ���� ��ü�� �־��ش�.
 //postcondition : �� ������ ���� �������ش�.
	_size--;
}

void MyIntVector::push_back(int x)
{//precondition : ���� ��ü�� ������ �־��ش�.
 //postcondition : �� ������ ���� �־��� ������ �߰����ش�.
	int *temp = new int[_capacity];
	for (int i = 0; i < _size; i++)
		temp[i] = data[i];
	delete[] data;
	_capacity *= 2;
	data = new int[_capacity];
	for (int i = 0; i < _size; i++)
		data[i] = temp[i];
	delete[]temp;
	data[_size++] = x;

}

size_t MyIntVector::capacity() const
{//precondition : ���� ��ü�� �޴´�.
 //postcondition : ��ü�� �� �뷮�� �����Ѵ�.
	return size_t(_capacity);
}

size_t MyIntVector::size() const
{//precondition : ���� ��ü�� �޴´�.
 //postcondition : ��ü�� ���� �뷮�� �����Ѵ�.
	return size_t(_size);
}

void MyIntVector::reserve(size_t new_capacity)
{//precondition : ����� ���ο� ũ�⸦ �޴´�.
 //postcondition : �� ���� ��� ũ�� ������ְ�, ���ο� ũ�⸦ ����� �ش�.
	int *larger_array;
	if (new_capacity == _capacity)
		return;
	if (new_capacity < _size)
		new_capacity = _size;

	larger_array = new int[new_capacity];
	copy(data, data + _size, larger_array);
	delete[] data;
	data = larger_array;
	_capacity = new_capacity;
	
}

bool MyIntVector::isEmpty() const
{//precondition : ���� ��ü�� �޴´�.
 //postcondition : ��ü�� ����ִ� �� ���θ� Ȯ���Ѵ�.
	return !_size;
}

void MyIntVector::clear()
{//precondition : ���� ��ü�� �޴´�.
 //postcondition : ��ü�� ������ ����ش�.
	delete[] data;
	_capacity = 1;
	_size = 0;
	data = new int[1];
}

