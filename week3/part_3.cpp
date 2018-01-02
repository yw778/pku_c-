/*
输入
无
输出
5,5
5,5
所缺代码具有如下形式:
Big ________________{ }
Big ________________{ }
*/
#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big  {
public:
    int v; Base b;
// 在此处补充你的代码
    Big (int n) : v(n), b(n){}  
    //注意base有ddefault的复制构造函数
    Big (const Big & big): v(big.v), b(big.b){};
};
int main()  {
    Big a1(5);    Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}