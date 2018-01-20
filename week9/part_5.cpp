#include <iostream>
#include <map>
using namespace std;
int main() {
	typedef map<int, int> mmid;
	mmid member;
	int n;
	member[1000000000] = 1;
	cin >> n;
	while(n--) {
		int id;
		int score;
		cin >> id >> score;
		mmid::const_iterator big = member.upper_bound(score);
		mmid::const_iterator small = big;
		cout << id << " ";
		if (small == member.begin()) {
			cout << big->second << endl;
		} else {
			small--;
			int diff1 = big->first - score;
			int diff2 = score - small->first;
			if (diff1 < diff2) {
				cout << big->second << endl;
			} else {
				cout << small->second << endl;
			}
		}
		member[score] = id;
	}

	return 0;
}