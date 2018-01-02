/*
输入
无

输出
0
5

所缺代码具有如下形式:
A(_________________ ){ val = n; }
    ________________ GetObj() {
        return _________________;
    }
*/
#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A (int n = 0) {
    	this->val = n;
    }
    int & GetObj(){
        return val;
    }
};
int main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
    return 0;
}