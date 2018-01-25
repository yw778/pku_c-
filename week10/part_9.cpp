#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
struct A {
        string name;
        int age;
        A(int _age):age(_age) {name = "A";}
        virtual ~A() {}
};
struct B : public A {
        B(int _age):A(_age){name = "B";}
};
void Print(A* t) {
        cout << t->name << " " << t->age << endl;
}

// template <typename T>
struct Comp {
        bool operator()(const A* a, const A* b) {
                return a->age < b->age;
        }
};

int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}