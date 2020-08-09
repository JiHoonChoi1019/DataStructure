#include "MyIntVector.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>


using namespace std;

MyIntVector::MyIntVector(size_t init_capacity)
{ //생성자
	data = new int[init_capacity];
	_capacity = init_capacity;
	_size = 0;
}


MyIntVector::~MyIntVector()
{ //소멸자
	delete[] data;
}

MyIntVector::MyIntVector(const MyIntVector & v)
{ //복사 생성자
	data = new int[v._capacity];
	_capacity = v._capacity;
	_size = v._size;
	copy(v.data, v.data + _size, data);
}

MyIntVector& MyIntVector::operator=(const MyIntVector & v)
{ //깊은 복사
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
{//precondition : 객체를 넣어준다.
 //postconditon : 원래 있던 객체1에 객체2를 추가해준다.
	if (_size + addend._size > _capacity)
		reserve(_size + addend._size);
	copy(addend.data, addend.data + addend._size, data + _size);
	_size += addend._size;

}

int & MyIntVector::operator[](int i)
{//precondition : 인자에 정수를 넣어준다.
 //postcondition : 정해진 인덱스 i의 값을 []연산자 안의 숫자로 바꿔준다.
	return data[i];
	// TODO: 여기에 반환 구문을 삽입합니다.
}

MyIntVector MyIntVector::operator+(const MyIntVector & num)
{//precondition : 다른 객체를 넣어준다.
 //postcondition : 객체끼리 같은 인덱스의 값을 더해준다.
	MyIntVector n(_capacity);

	for (int m = 0; m < _size; m++) {
		n.data[m] = data[m] + num.data[m];
		n._size++;
	}
	
	return n;
}

MyIntVector MyIntVector::operator-(const MyIntVector & num)
{ //precondition : 다른 객체를 넣어준다.
 //postcondition : 객체끼리 같은 인덱스의 값을 빼준다.
	
	MyIntVector n(_capacity);
	
	for (int m = 0; m < _size; m++) {
		n.data[m] = data[m] - num.data[m];
		n._size++;
	}

	return n;
}

MyIntVector MyIntVector::operator*(const MyIntVector & num)
{//precondition : 다른 객체를 넣어준다.
 //postcondition : 객체끼리 같은 인덱스의 값을 곱해준 다음 다 더한다.
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
{//precondition : 다른 객체를 넣어준다.
 //postcondition : 객체 안의 사용된 크기 같은지 여부 즉 참,거짓을 리턴한다.
	MyIntVector n(_size); //_첨에 _size했었음

	if (_size == v._size)
		return true;
	else 
		return false;
}

MyIntVector MyIntVector::operator-()
{//precondition : 원래 객체를 넣어준다.
 //postcondition : 인덱스의 각 값들을 부호 반대 처리해준다.

	MyIntVector n(_capacity);
	int m;
	for (m = 0; m < _size; m++) {
		n.data[m] = - data[m];
		n._size++;
	}
	return n;
}


MyIntVector MyIntVector::operator()(int const & num)
{//precondition : 바꿔줄 정수 값을 정한다.
 //postcondition : 인덱스의 각 값들을 받은 인자 값으로 바꿔준다.
	MyIntVector n(_capacity);
	for (int m = 0; m < _size; m++) {
		n.data[m] = num;
		n._size++;
	}
	return n;
}

void MyIntVector::pop_back()
{//precondition : 원래 객체를 넣어준다.
 //postcondition : 맨 마지막 부터 삭제해준다.
	_size--;
}

void MyIntVector::push_back(int x)
{//precondition : 원래 객체에 정수를 넣어준다.
 //postcondition : 맨 마지막 부터 넣어준 정수를 추가해준다.
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
{//precondition : 원래 객체를 받는다.
 //postcondition : 객체의 총 용량을 리턴한다.
	return size_t(_capacity);
}

size_t MyIntVector::size() const
{//precondition : 원래 객체를 받는다.
 //postcondition : 객체의 사용된 용량을 리턴한다.
	return size_t(_size);
}

void MyIntVector::reserve(size_t new_capacity)
{//precondition : 사용할 새로운 크기를 받는다.
 //postcondition : 더 작은 경우 크게 만들어주고, 새로운 크기를 만들어 준다.
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
{//precondition : 원래 객체를 받는다.
 //postcondition : 객체가 비어있는 지 여부를 확인한다.
	return !_size;
}

void MyIntVector::clear()
{//precondition : 원래 객체를 받는다.
 //postcondition : 객체의 내용을 비워준다.
	delete[] data;
	_capacity = 1;
	_size = 0;
	data = new int[1];
}

