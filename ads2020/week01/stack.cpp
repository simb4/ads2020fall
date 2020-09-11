#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

char st[100];
int h; // stack is in [0, h)

void push(int x) {
	st[h] = x;
	h++;
}

void pop() {
	h--;
}

int top() {
	return st[h-1];
}

bool empty() {
	return h == 0;
}

bool isOpening(char c) {
	return c == '(' || c == '{' || c == '[';
}

char paired(char c) {
	if (c == ')') return '(';
	if (c == ']') return '[';
	return '{';
}

void stack_example() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (isOpening(s[i])) {
			push(s[i]);
		} else { // s[i] is closing
			if (top() == paired(s[i])) {
				pop();
			} else {
				cout << "No\n";
				return;
			}
		}
	}
	if (empty())
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {


	stack_example();



	return 0;
}


