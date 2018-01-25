#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
// 在此处补充你的代码
    Number operator=(int n) {
    	this->num = n;
    	return this->num;
    }
    Number operator*(int n) {
    	return this->num * n;
    }
    // 必须重载为一元的
    operator int() {
    	return this->num;
    }
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}