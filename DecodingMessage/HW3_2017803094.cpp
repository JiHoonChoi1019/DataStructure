//2017803094_������

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int length = 0; //������ �ִ� ����
	int num = 0; //���� ū ���� ã�� ���� ����
	string pwd; //������ ��ȣ

	cin >> length;
	cin >> pwd;
	string *arr = new string;
	unordered_map<string, int> pwdmap;
	
	for (int i = 0; i < pwd.size() - length + 1; i++) {
		*arr = pwd.substr(i, length); //i���� length����ŭ ���´�.

		pwdmap.insert(pair<string, int>(*arr, 0)); 

		auto its = pwdmap.find(*arr);
		if (its != pwdmap.end()) {
			++its->second;
		}
		if (its->second > num)
			num = its->second;

	}

	for (auto pw_itr = pwdmap.begin(); pw_itr != pwdmap.end(); ++pw_itr) {
		if (pw_itr->second == num)
			cout << pw_itr->first << endl;
	}

	delete[] arr;

	return 0;

}
