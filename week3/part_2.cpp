/*
请补足Sample类的成员函数。不能增加成员变量。
输入
无
输出
10
*/
#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
    //复制构造函数
    Sample(const Sample & sample) {
    	v = 10;
    }
// 在此处补充你的代码
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}