#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
map<int, list<int> > L;

void newL(int id) {
	list<int> l;
	L[id] = l;
}

void Add(int id, int num) {
	L[id].push_back(num);
}

void Merge(int id1, int id2) {
	L[id1].merge(L[id2]);
}

void Unique(int id) {
	L[id].sort();
	L[id].unique();
}

void Out(int id) {
	list<int> tmp = L[id];
	tmp.sort();
	list<int>::iterator it;
	for (it = tmp.begin(); it != tmp.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	int n;
	int id1, id2;
	cin >> n;
	while(n--) {
		string s;
		int id1, id2;
		cin >> s;
		switch(s[0]) {
			case 'n': {cin >> id1; newL(id1); break;}
			case 'a': {cin >> id1 >> id2; Add(id1, id2); break;}
			case 'm': {cin >> id1 >> id2; Merge(id1, id2); break;}
			case 'u': {cin >> id1; Unique(id1); break;}
			case 'o': {cin >> id1; Out(id1);break;}
		}
	}
}