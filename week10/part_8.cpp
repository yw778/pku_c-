#include <iostream>
using namespace std;
int main() {
	int t, n, i, j, tmp;
	cin >> t;
	while(t--){
		cin >> n >> i >> j;
		tmp = 0;
		tmp |= (((n >> i) & 1) << i);
		tmp |= ((~(n >> j) & 1) << j);
		for (int m = i + 1; m < j; ++m) {
			tmp |= (1 << m);
		}
		cout << hex << tmp <<endl;
	}
	return 0;
}
