#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '0') {
			a[i] = '1';
			cout << stoi(a, nullptr, 2);
			return 0;
		}
	}

	a[a.size() - 1] = '0';
	cout << stoi(a, nullptr, 2);
	return 0;
}