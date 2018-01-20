#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

const string num("0123456789");
string str[21];
int findN(const string & cmd);
string findS(const string & cmd);

string Copy() {
	string tmp;
	int N, X, L;
	cin >> tmp;
	N = findN(tmp);
	cin >> tmp;
	X = findN(tmp);
	cin >> tmp;
	L = findN(tmp);
	return str[N].substr(X, L);
}

string Add() {
	string tmp;
	string s1, s2;
	cin >> tmp;
	s1 = findS(tmp);
	cin >> tmp;
	s2 = findS(tmp);
	if (s1.find_first_not_of(num) != string::npos || s2.find_first_not_of(num) != string::npos)
		return s1 + s2;
	long i1 = atoi(s1.c_str());
	long i2 = atoi(s2.c_str());
	if (i1 >= 1 && i1 <= 99999 && i2 >= 1 && i2 <= 99999) {
		stringstream ss;
		ss << i1 + i2;
		return ss.str();
	}
	return s1 + s2;
}

int Find() {
	string tmp, s1;
	int N;
	cin >> tmp;
	s1 = findS(tmp);
	cin >> tmp;
	N = findN(tmp);
	if (str[N].find(s1) == string::npos) {
		return s1.length();
	}
	return str[N].find(s1);
}

int rFind() {
	string tmp, s1;
	int N;
	cin >> tmp;
	s1 = findS(tmp);
	cin >> tmp;
	N = findN(tmp);
	if (str[N].rfind(s1) == string::npos) {
		return s1.length();
	}
	return str[N].rfind(s1);
}

void Insert() {
	string tmp, s1;
	int N, X;
	cin >> tmp;
	s1 = findS(tmp);
	cin >> tmp;
	N = findN(tmp);
	cin >> tmp;
	X = findN(tmp);
	str[N].insert(X, s1);

}

void Reset() {
	string tmp, s1;
	int N;
	cin >> tmp;
	s1 = findS(tmp);
	cin >> tmp;
	N = findN(tmp);	
	str[N] = s1;
}

void Print() {
	string tmp;
	int N;
	cin >> tmp;
	N = findN(tmp);
	cout << str[N] << endl;
}

void Printall(int n) {
	for (int i = 1; i <= n; ++i) {
		cout << str[i] << endl;
	}
}

int findN(const string &cmd) {
	if (cmd == "find") {
		return Find();
	} else if (cmd == "rfind") {
		return rFind();
	} else {
		return atoi(cmd.c_str());
	}
}

string findS(const string &cmd) {
	if(cmd=="copy") {
		return Copy();
	} else if(cmd=="add") {
		return Add();
	} else {
		return cmd;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> str[i];
	}
	while(cin >> str[0]) {
		if (str[0] == "over") {
			break;
		}
		switch(str[0][0]) {
			case 'i':{Insert(); break;}
			case 'r':{Reset(); break;}
			case 'p': {
				if (str[0] == "print") {
					Print();
				} else {
					Printall(n);
				}
				break;
			} 
		}
	}
	return 0;
}



