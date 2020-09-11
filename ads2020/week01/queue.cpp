#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int q[100];
int start, tail;
// queue is in indexes [start, tail) , start <= tail

// [3,5) = {3,4}  size = 2

void push_back(int x) {
	q[tail] = x;
	tail++;
}

void pop_front() {
	/* verify, that queue is not empty */
	start++;
}

int front() {
	/* verify, that queue is not empty */
	return q[start];
}

int back() {
	/* verify, that queue is not empty */
	return q[tail-1];
}

int size() {
	return tail - start;
}

bool empty() {
	return start == tail;
}

int main() {

	push_back(2);
	push_back(3);
	push_back(5);
	// 2 3 5
	cout << front() << "\n";
	cout << back() << "\n";
	pop_front();
	// 3 5
	cout << front() << "\n";
	cout << size() << "\n";


	return 0;
}

