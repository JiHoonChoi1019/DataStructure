#include <algorithm>
#include <cstdlib>
#include <iostream>


#include "MyIntVector.h"

using namespace std;

int main() {
	MyIntVector v1;
	v1.reserve(10);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	int i;
	cout << "vector1을 생성했습니다." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " <<v1[i];
	cout << endl;
	cout << "v1의 capacity = " << v1.capacity() << endl;
	cout << "v1의 size = " << v1.size() << endl;
	cout << "--------------------------" << endl;

	MyIntVector v2;
	v2.reserve(15);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	cout << "vector2를 생성했습니다." << endl;
	for (i = 0; i < v2.size(); i++)
		cout << " vec2[" << i << "] = " <<v2[i];
	cout << endl;
	cout << "v2의 capacity = " << v2.capacity() << endl;
	cout << "v2의 size = " << v2.size() << endl;
	cout << "--------------------------" << endl;

	MyIntVector v3;
	v3.reserve(20);
	cout << "연산자 오버로딩을 위한 vector3을 생성했습니다." << endl;
	v3 = v1.operator+(v2);
	cout << "+ 연산자 오버로딩 했습니다." << endl;
	for (i = 0; i < v3.size(); i++)
		cout << " vec3[" << i << "] = " << v3[i];
	cout << endl;
	cout << endl;

	v3 = v1.operator-(v2);
	cout << "이항 - 연산자 오버로딩 했습니다." << endl;
	for (i = 0; i < v3.size(); i++)
		cout << " vec3[" << i << "] = " << v3[i];
	cout << endl;
	cout << endl;

	v3 = v1.operator*(v2);
	cout << "* 연산자 오버로딩 했습니다." << endl;
	cout << "vector1과 vector2의 내적은 " << v3[0] << "입니다." << endl;
	cout << endl;

	v3 = v1.operator-();
	cout << "단항 - 연산자 오버로딩 했습니다. vector1의 값을 바꿉니다." << endl;
	for (i = 0; i < v3.size(); i++)
		cout << " vec3[" << i << "] = " << v3[i];
	cout << endl;
	cout << "--------------------------" << endl;

	cout << "[] 연산자 오버로딩 했습니다." << endl;
	v1[1] = 10;
	cout << "v1의 1번 index의 값을 10으로 바꿨습니다." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "v1의 capacity = " << v1.capacity() << endl;
	cout << "v1의 size = " << v1.size() << endl;
	cout << "--------------------------" << endl;

	cout << "== 연산자 오버로딩 했습니다." << endl;
	cout << "vector1과 vector2의 사용된 크기 비교입니다. " << v1.operator==(v2) << endl;
	cout << "--------------------------" << endl;

	MyIntVector v4;
	v4.reserve(20);
	cout << "() 연산자 오버로딩 했습니다." << endl;
	cout << "값을 저장하기 위해 vector4 선언했습니다." << endl;
	v4 = v1.operator()(9);
	for (i = 0; i < v4.size(); i++)
		cout << " vec1[" << i << "] = " << v4[i];
	cout << endl;
	cout << "--------------------------" << endl;

	cout << "+= 연산자 오버로딩 했습니다." << endl;
	cout << "vector1과 vector2를 합칩니다." << endl;
	v1.operator+=(v2);
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "v1의 capacity = " << v1.capacity() << endl;
	cout << "v1의 size = " << v1.size() << endl;
	cout << "--------------------------" << endl;


	v1.pop_back();
	cout << "vector1을 pop_back 했습니다." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "v1의 capacity = " << v1.capacity() << endl;
	cout << "v1의 size = " << v1.size() << endl;
	cout << "--------------------------" << endl;
	
	cout << "isEmpty 함수 확인입니다." << endl;
	cout << "vector1은 차 있습니다. " << endl;
	cout << v1.isEmpty() << endl;
	cout << "--------------------------" << endl;

	v1.clear();
	cout << "vector1에 clear 함수 사용했습니다." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "윗줄이 비어있다면 성공적으로 된 것입니다." << endl;
	cout << "v1의 capacity = " << v1.capacity() << endl;
	cout << "v1의 size = " << v1.size() << endl;
	cout << "--------------------------" << endl;

	cout << "isEmpty 함수 확인입니다." << endl;
	cout << "clear 함수로 인해 vector1은 비어 있습니다. " << endl;
	cout << v1.isEmpty() << endl;
	cout << "--------------------------" << endl;

	getchar();

	
}