#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double number;
	cin >> number;
	cout << fixed << setprecision(5) << number << endl;
	// cout.unsetf(ios::fixed);
	// cout.setf(ios::scientific);
	// cout.precision(7);
	cout<< scientific << setprecision(5) << number << endl;
	return 0;
}