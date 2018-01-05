// #include <iostream>
// #include <cstring>
// using namespace std;
// 在此处补充你的代码
class Array2 {
    int *ptr;
    int m;
    int n;
public:
    Array2() {
        this->m = 0;
        this->n = 0;
        ptr = NULL;
    };
    Array2(int m_val, int n_val) {
        this->m = m_val;
        this->n = n_val;
        ptr = new int[m_val * n_val];
    }
    ~Array2() {
        //注意这个析构函数必须写的 因为系统不会自动处理 ptr
        if (ptr) {
            delete[] ptr;
        }
    }
    Array2 & operator=(const Array2 & a) {
        if (a.ptr == this->ptr) return *this;
        //注意这一句
        if (ptr) {
            delete[] ptr;
        }
        this->m = a.m;
        this->n = a.n;
        ptr = new int[m*n];
        memcpy(this->ptr, a.ptr, m*n*sizeof(int));
        return *this;
    } 
    // 这里重载的是第一个[], 第二个自动调用int*的定义
    int * operator[] (int i) {
        return ptr + i * n; 
    }
    int operator() (int i, int j) {
        return ptr[i * n + j];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}