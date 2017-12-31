/*
简单的学生信息处理程序实现
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
注意： 总时间限制: 1000ms 内存限制: 65536kB
描述
在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）
输入
姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。
其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。
各部分内容之间均用单个英文逗号","隔开，无多余空格。
输出
一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。
各部分内容之间均用单个英文逗号","隔开，无多余空格。
样例输入
Tom,18,7817,80,80,90,70
样例输出
Tom,18,7817,80
*/
#include <iostream>
#include <string>
using namespace std;
class Student{
private:
	string name;
	string id;
	int age;
	int grade1;
	int grade2;
	int grade3;
	int grade4;
public:
	void init();
	void print();
};

void Student::init(){
	char comma;
	getline(cin, name, ',');
	cin >> age >> comma;
	getline(cin, id, ',');
	cin >> grade1 >> comma >> grade2 >> comma >> grade3 >> comma >> grade4;
}
void Student::print(){
	int average = (grade1 + grade2 + grade3 + grade4) / 4;
	cout << name << ',' << age << ',' << id << ',' << average;
}

int main() {
	Student s1;
	s1.init();
	s1.print();
	return 0;
}