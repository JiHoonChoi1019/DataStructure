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
	cout << "vector1�� �����߽��ϴ�." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " <<v1[i];
	cout << endl;
	cout << "v1�� capacity = " << v1.capacity() << endl;
	cout << "v1�� size = " << v1.size() << endl;
	cout << "--------------------------" << endl;

	MyIntVector v2;
	v2.reserve(15);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	cout << "vector2�� �����߽��ϴ�." << endl;
	for (i = 0; i < v2.size(); i++)
		cout << " vec2[" << i << "] = " <<v2[i];
	cout << endl;
	cout << "v2�� capacity = " << v2.capacity() << endl;
	cout << "v2�� size = " << v2.size() << endl;
	cout << "--------------------------" << endl;

	MyIntVector v3;
	v3.reserve(20);
	cout << "������ �����ε��� ���� vector3�� �����߽��ϴ�." << endl;
	v3 = v1.operator+(v2);
	cout << "+ ������ �����ε� �߽��ϴ�." << endl;
	for (i = 0; i < v3.size(); i++)
		cout << " vec3[" << i << "] = " << v3[i];
	cout << endl;
	cout << endl;

	v3 = v1.operator-(v2);
	cout << "���� - ������ �����ε� �߽��ϴ�." << endl;
	for (i = 0; i < v3.size(); i++)
		cout << " vec3[" << i << "] = " << v3[i];
	cout << endl;
	cout << endl;

	v3 = v1.operator*(v2);
	cout << "* ������ �����ε� �߽��ϴ�." << endl;
	cout << "vector1�� vector2�� ������ " << v3[0] << "�Դϴ�." << endl;
	cout << endl;

	v3 = v1.operator-();
	cout << "���� - ������ �����ε� �߽��ϴ�. vector1�� ���� �ٲߴϴ�." << endl;
	for (i = 0; i < v3.size(); i++)
		cout << " vec3[" << i << "] = " << v3[i];
	cout << endl;
	cout << "--------------------------" << endl;

	cout << "[] ������ �����ε� �߽��ϴ�." << endl;
	v1[1] = 10;
	cout << "v1�� 1�� index�� ���� 10���� �ٲ���ϴ�." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "v1�� capacity = " << v1.capacity() << endl;
	cout << "v1�� size = " << v1.size() << endl;
	cout << "--------------------------" << endl;

	cout << "== ������ �����ε� �߽��ϴ�." << endl;
	cout << "vector1�� vector2�� ���� ũ�� ���Դϴ�. " << v1.operator==(v2) << endl;
	cout << "--------------------------" << endl;

	MyIntVector v4;
	v4.reserve(20);
	cout << "() ������ �����ε� �߽��ϴ�." << endl;
	cout << "���� �����ϱ� ���� vector4 �����߽��ϴ�." << endl;
	v4 = v1.operator()(9);
	for (i = 0; i < v4.size(); i++)
		cout << " vec1[" << i << "] = " << v4[i];
	cout << endl;
	cout << "--------------------------" << endl;

	cout << "+= ������ �����ε� �߽��ϴ�." << endl;
	cout << "vector1�� vector2�� ��Ĩ�ϴ�." << endl;
	v1.operator+=(v2);
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "v1�� capacity = " << v1.capacity() << endl;
	cout << "v1�� size = " << v1.size() << endl;
	cout << "--------------------------" << endl;


	v1.pop_back();
	cout << "vector1�� pop_back �߽��ϴ�." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "v1�� capacity = " << v1.capacity() << endl;
	cout << "v1�� size = " << v1.size() << endl;
	cout << "--------------------------" << endl;
	
	cout << "isEmpty �Լ� Ȯ���Դϴ�." << endl;
	cout << "vector1�� �� �ֽ��ϴ�. " << endl;
	cout << v1.isEmpty() << endl;
	cout << "--------------------------" << endl;

	v1.clear();
	cout << "vector1�� clear �Լ� ����߽��ϴ�." << endl;
	for (i = 0; i < v1.size(); i++)
		cout << " vec1[" << i << "] = " << v1[i];
	cout << endl;
	cout << "������ ����ִٸ� ���������� �� ���Դϴ�." << endl;
	cout << "v1�� capacity = " << v1.capacity() << endl;
	cout << "v1�� size = " << v1.size() << endl;
	cout << "--------------------------" << endl;

	cout << "isEmpty �Լ� Ȯ���Դϴ�." << endl;
	cout << "clear �Լ��� ���� vector1�� ��� �ֽ��ϴ�. " << endl;
	cout << v1.isEmpty() << endl;
	cout << "--------------------------" << endl;

	getchar();

	
}