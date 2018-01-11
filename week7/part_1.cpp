#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D {
public:
    template <class T1>
    class Array2 {
        T1 *ptr;
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
        T1 * operator[] (int i) {
            return ptr + i * n; 
        }
        T1 operator() (int i, int j) {
            return ptr[i * n + j];
        }
    };
private:
    Array2<T> *ptrz;
public:
    CArray3D():ptrz(NULL){}
    CArray3D(int z, int x, int y) {
        ptrz = new Array2<T>[z];
        for (int i = 0; i < z; ++i) {
            // 这里晚上的答案采用 set 函数 不清楚为什么不直接调用构造函数
            ptrz[i] = Array2<T>(x, y);
        }
    }
    Array2<T>& operator[](int i){return ptrz[i];}
    ~CArray3D(){if(ptrz) delete [] ptrz;}
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}