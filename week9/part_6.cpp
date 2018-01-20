#include <iostream>
#include <cmath>
#include <set>
using namespace std;

bool is_prime(int val) {
	for (int i = 2; i <= sqrt((float)val); ++i) {
		if (val % i == 0)
			return false;
	}
	return true;
}

int get_factor(int val) {
	int sum = 0;
	int k = 0;
	for (int i = 2; i <= sqrt((float)val); ++i) {
		k = val / i;
		if (i != k && is_prime(k))
			sum += 1;
		if (is_prime(i))
			sum += 1;
	}
	return sum;
}

struct Mycompare {
	bool operator()(const int&a, const int&b) {
		int sumA = 0, sumB = 0;
		sumA = get_factor(a);
		sumB = get_factor(b);
		// 注意在c++中comparator return true false 而不是 0 1
		if (sumA == sumB) {
			if (a < b) {
				return true;
			} else {
				return false;
			}
		} else if (sumA > sumB) {
			return false;
		} else {
			return true;
		}
	}
};

int main() {
	set<int, Mycompare> queue;
	int n;
	cin >> n;
	while(n--) {
		int num;
		for (int i = 0; i < 10; ++i) {
			cin >> num;
			queue.insert(num);
		}
		int min = *(queue.begin());
		int max = *(queue.rbegin()); // be careful of rbegin()!
		queue.erase(min);
		queue.erase(max);
		cout << max << " " << min << endl; 
	}
	return 0;
}