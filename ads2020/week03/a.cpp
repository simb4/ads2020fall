#include <iostream>

using namespace std;


int a[100], n;

bool bin_search(int *a, int n, int x) {
	// [0, n-1]
	int l = 0, r = n - 1;
	while (l < r) { // l != r
		int mid = (l + r) / 2;
		if (a[mid] == x)
			return true;
		if (a[mid] < x) { // [    |mid|  x ] 
			l = mid + 1;
		} else { // x <= a[mid]:  [ x  |mid|    ] 
			r = mid - 1;
		}
	}
	return a[l] == x;
}
int left_bin_search(int *a, int n, int x) {
	/*
		Find the leftmost occurence of x,
		if there is one.
	*/
	// [0, n-1]
	int l = 0, r = n - 1;
	while (l < r) { // l != r
		int mid = (l + r) / 2;
		if (a[mid] < x) { // [    |mid|  x ] 
			l = mid + 1;
		} else { // x <= a[mid]:  [   x-1|mid|x|x|x+1    ] 
			r = mid;
		}
	}
	if (a[l] == x)
		return l;
	return -1;
}
int right_bin_search(int *a, int n, int x) {
	/*
		Find the rightmost occurence of x,
		if there is one.
		Be aware of inf loop, for ex:
		state of [l, r] = [2, 3]
		mid = 2
		a[mid] == x
		l = 2
		again state of [l, r] = [2,3]
		=> inf loop
	*/
	// [0, n-1]
	int l = 0, r = n - 1;
	while (l < r) { // l != r
		int mid = (l + r + 1) / 2;
		if (a[mid] <= x) { // [    |mid|  x ] 
			l = mid;
		} else { //  x <= a[mid] :  [   x |a[mid]| x x   ] 
			r = mid - 1;
		}
	}
	if (a[l] == x)
		return l;
	return -1;
}


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		cout << (bin_search(a, n, x) ? "Yes\n" : "No\n");
		cout << left_bin_search(a, n, x) << " ";
		cout << right_bin_search(a, n, x) << "\n\n";
	}

	return 0;
}

