#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType{
private:
	int num;
public:
	CType(int n = 0) {
		this->num = n;
	}
	int setvalue(int n) {
		this->num = n;
	}
	int operator++(int n) {
		int tmp;
		tmp = this->num;
		this->num = tmp * tmp;
		return tmp;
	}
	friend ostream& operator<<(ostream& out, const CType& c);
};
ostream& operator<<(ostream& out, const CType& c) {
		out << c.num;
		return out;
};
int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}