#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

char st[100];
int h; // stack is in [0, h)
// 1 2 2 2 3, h = 5
void push(char x) {
	st[h] = x; // st[h++] = x;
	h++;
}

void pop() {
	h--;
}

char top() {
	if (h == 0) {
		cerr << "Stack error\n";
		exit(0);
	}
	return st[h-1];
}

bool empty() {
	return h == 0;
}

bool isOpening(char ch) {
	return ch == '{' || ch == '[' || ch == '(';
}

char paired(char r) {
	if (r == ')') return '(';
	if (r == ']') return '[';
	return '{';
}

void stack_example() {
	string s;
	cin >> s;
	int n = s.length();

	for (int i = 0; i < n; i++) {
		if (isOpening(s[i])) {
			push(s[i]);
		} else { // s[i] is closing bracket
			if (!empty() && top() == paired(s[i]))
				pop();
			else {
				cout << "No\n";
				return;
			}
		}
	}
	if (!empty())
		cout << "No\n";
	else
		cout << "Yes\n";
}

int main() {


	stack_example();



	return 0;
}

