#include <iostream>

using namespace std;


int a[100], n;

bool bin_search(int *a, int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2; // floor
		if (a[mid] == x)
			return true;
		// [oooooo a[mid] ooxo]
		if (x < a[mid])
			r = mid - 1;
		else // a[mid] < x
			l = mid + 1;
	}
	return false;
}

int left_bin_search(int *a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2; // floor
		if (x <= a[mid])
			r = mid;
		else // a[mid] < x
			l = mid + 1;
	}
	if (a[l] == x)
		return l;
	return -1;
}

// 1 2 3 4 5 6
int right_bin_search(int *a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2; // ceil
		if (a[mid] <= x)
			l = mid;
		else // x < a[mid] 
			r = mid - 1;
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
		cout << right_bin_search(a, n, x);
		cout << "\n\n";
	}

	return 0;
}

