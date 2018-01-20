/*
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：

add x 把x加入集合

del x 把集合中所有与x相等的元素删除

ask x 对集合中元素x的情况询问

对每种操作，我们要求进行如下输出。

add 输出操作后集合中x的个数

del 输出操作前集合中x的个数

ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main() {
    multiset<int> s;
    set<int> his;
    int n;
    cin >> n;
    while(n--) {
    	string str;
    	cin >> str;
    	int num;
    	switch(str[1]) {
    		case 'd':{
    			cin >> num; 
    			s.insert(num); 
    			his.insert(num); 
    			cout << s.count(num)<<endl;
    			break;
    		}
    		case 'e':{
    			cin >> num; 
    			cout << s.count(num)<<endl; 
    			s.erase(num); 
    			break;
    		}
    		case 's':{
    			cin >> num;
    			if (his.find(num) != his.end()) {
    				cout << 1 << " ";
    			} else {
    				cout << 0 << " ";
    			}
    			cout << s.count(num) << endl;
    			break;
    		}
    	}

    }
    return 0;
}