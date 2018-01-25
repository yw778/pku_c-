#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
// 在此处补充你的代码
struct MyString{
    string str;
    MyString() {}
    MyString(const char* _char):str(_char){}
    MyString(const string& s1):str(s1){}
    MyString(const MyString& s1):str(s1.str) {}
    char& operator[](int i) {
        return str[i];
    }
    string operator()(int i, int j) {
        return str.substr(i, j);
    }
    MyString& operator=(const MyString& s) {
        this->str = s.str;
        return *this;
    }
    MyString& operator=(const char* s) {
        this->str = s;
        return *this;
    }
    MyString operator+=(const char* s2) {
        this->str += s2;
        return *this;
    }
    bool operator<(const MyString& s) {
        return this->str < s.str;
    }
    bool operator==(const MyString& s) {
        return this->str == s.str;
    }
    bool operator>(const MyString& s) {
        return this->str > s.str;
    }

};
MyString operator+(const MyString& s1, const char* s2) {
        return MyString(s1.str + s2);
    }
MyString operator+(const MyString& s1, const MyString& s2) {
        return MyString(s1.str + s2.str);
    }
ostream& operator<<(ostream& out, const MyString& tmp) {
        out << tmp.str;
        return out;
} 
MyString operator+(const char * s1, MyString s2) {
    return s1 + s2.str;
}
int CompareString( const void * e1, const void * e2)
{
        MyString * s1 = (MyString * ) e1;
        MyString * s2 = (MyString * ) e2;
        if( * s1 < *s2 )
                 return -1;
        else if( *s1 == *s2)
                 return 0;
        else if( *s1 > *s2 )
                 return 1;
}
int main()
{
        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
        MyString SArray[4] = {"big","me","about","take"};
        cout << "1. " << s1 << s2 << s3<< s4<< endl;
        s4 = s3;
        s3 = s1 + s3;
        cout << "2. " << s1 << endl;
        cout << "3. " << s2 << endl;
        cout << "4. " << s3 << endl;
        cout << "5. " << s4 << endl;
        cout << "6. " << s1[2] << endl;
        s2 = s1;
        s1 = "ijkl-";
        s1[2] = 'A' ;
        cout << "7. " << s2 << endl;
        cout << "8. " << s1 << endl;
        s1 += "mnop";
        cout << "9. " << s1 << endl;
        s4 = "qrst-" + s2;
        cout << "10. " << s4 << endl;
        s1 = s2 + s4 + " uvw " + "xyz";
        cout << "11. " << s1 << endl;
        qsort(SArray,4,sizeof(MyString),CompareString);
        for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
        //s1的从下标0开始长度为4的子串
        cout << s1(0,4) << endl;
        //s1的从下标5开始长度为10的子串
        cout << s1(5,10) << endl;
        return 0;
}