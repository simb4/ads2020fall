#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void gcd_example() {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << "\n";
}

char marked[1000];
void eratosphen_example() {
	int n;
	cin >> n;
	marked[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!marked[i]) { // true -> !true = false
			// then i is prime
			for (int j = i + i; j <= n; j += i)
				marked[j] = 1;
		}
	}

	cout << "Primes: ";
	for (int i = 1; i <= n; i++)
		if (!marked[i])
			cout << i << ' ';
	cout << "\n";
}

int binpow(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n == 1) return a;

	int a2 = binpow(a, n / 2, mod);
	long long sqra = (long long)a2 * a2 % mod;
	if (n % 2 == 0) return sqra;
	return sqra * a % mod;
}

void binpow_example() {
	int a, b, mod;
	cin >> a >> b >> mod;
	cout << binpow(a, b, mod) << "\n";
}

int main() {


	binpow_example();



	return 0;
}

