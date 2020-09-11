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

bool crossed[1000];

void eratosphen_example() {
	int n;
	cin >> n;
	crossed[1] = true;
	for (int i = 2; i <= n; i++) {
		if (!crossed[i]) { // not crossed
			// i is prime
			for (int j = 2 * i; j <= n; j += i)
				crossed[j] = true;
		}
	}
	cout << "Primes:\n";
	for (int i = 1; i <= n; i++)
		if (!crossed[i])
			cout << i << "\n";


}

int binpow(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n == 1) return a;
	// a^n = (a^{n/2})^2 * a^{n%2}
	int ahalf = binpow(a, n/2, mod);
	long long sqr = ahalf * ahalf % mod;
	if (n % 2 == 0) return sqr % mod;
	return sqr * a % mod;
	// WARN: mod can be of order 10^9
}

void binpow_example() {	
	int a, b, mod;
	cin >> a >> b >> mod;
	cout << binpow(a, b, mod) << "\n";
}

int main() {

	eratosphen_example();
	// binpow_example();



	return 0;
}

