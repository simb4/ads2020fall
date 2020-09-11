#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;


int a[100];



int main() {


	string s;
	int x;
	while(true) {
		cin >> s;
		if (s == "exit")
			break;

		if (s == "push") {
			cin >> x;
			push(x);
		
		} else if (s == "size") {
			cout << size() << "\n";
		
		} else if (s == "pop") {
			int v = pop();
			cout << v << "\n";
		
		} else if (s == "back") {
			cout << top() << "\n";

		} else if (s == "clear") {
			clear();
			cout << "ok\n";

		}
	}



	return 0;
}

