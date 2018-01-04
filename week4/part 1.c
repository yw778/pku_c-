#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex & operator=(char * s) {
    	char * tmp = new char[strlen(s)];
    	strcpy(tmp, s);
    	char * p = strtok(tmp, "+");
    	this->r = atof(p);
    	p = strtok(NULL, "i");
    	this->i = atof(p);
    	return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}