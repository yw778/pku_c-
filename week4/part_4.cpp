/*
	描述
给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入
第一行：正整数a，长度不超过100

第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个

第三行：正整数b，长度不超过100

保证输入不含多余的空格或其它字符

输出
一行：表达式“a o b”的值。

补充说明：

1. 减法结果有可能为负数

2. 除法结果向下取整

3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符

*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class BigInt {
	string num;
	char sign;
public:
	BigInt(string n = "0");
	BigInt operator+(const BigInt &bi);
	BigInt operator-(const BigInt &bi);
	BigInt operator*(const BigInt &bi);
	BigInt operator/(const BigInt &bi);
	friend ostream& operator<<(ostream & o, const BigInt& bi);
};
BigInt::BigInt(string n) {
	if (n[0] == '-') {
		sign = '-';
		num = n.substr(1, n.length() - 1);
	} else {
		sign = '+';
		num = n;
	}
	
}
BigInt BigInt::operator+(const BigInt &bi) {
	string operand1 = num;
	string operand2 = bi.num;

	int maxlen = operand1.length() > operand2.length()? operand1.length() : operand2.length();
	while(operand1.length() < operand2.length()) {
		operand1.insert(0, "0");
	}
	while(operand2.length() < operand1.length()) {
		operand2.insert(0, "0");
	}

	char * result = new char[maxlen + 1];
	//注意用指针初始化的时候要多初始化以为 最后一位为 "\0"
	result[maxlen] = '\0';
	int carry = 0;
	for (int i = maxlen - 1; i >= 0; i--) {
		int add1 = operand1[i] - '0';
		int add2 = operand2[i] - '0';
		int add = (add1 + add2 + carry) % 10;
		carry = (add1 + add2 + carry) / 10;
		result[i] = '0' + add;
	}
	BigInt tmp(result);
	if (carry) {
		tmp.num = "1" + tmp.num;
	}
	tmp.sign = sign;
	return tmp;
}
// -  先判断 a, b 大小  求|a - b| 以及 sign
BigInt BigInt::operator-(const BigInt &bi) {
	string operand1 = num;
	string operand2 = bi.num;
	BigInt tmp;
	if (operand1 == operand2) {
		tmp.num = "0";
		tmp.sign = '+';
		return tmp;
	}

	int maxlen = 0;
	char tmpsign = '+';
	if (operand1.length() < operand2.length() || (operand2.length() == operand1.length() && operand1 < operand2)) {
		tmpsign = '-';
		swap(operand1, operand2);
	}
	maxlen = operand1.length();
	while(operand2.length() < operand1.length()) {
		operand2.insert(0, "0");
	}

	char * result = new char[maxlen + 1];
	result[maxlen] = '\0';
	int borrow = 0;
	// 注意 borrow的用法和carry 很像 
	for (int i = maxlen - 1; i >= 0; i--) {
		int minus1 = operand1[i] - '0';
		int minus2 = operand2[i] - '0';
		int minus = minus1 - minus2 - borrow;
		if (minus < 0) {
			minus += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		result[i] = '0' + minus;
	}
	tmp.num = result;
	while(tmp.num[0] == '0') {
		tmp.num.erase(0, 1);
	}
	tmp.sign = tmpsign;
	return tmp;
}

// 此function用到重载过后的 +
BigInt BigInt::operator*(const BigInt &bi) {
	string operand1 = num;
	string operand2 = bi.num;
	BigInt tmp;
	BigInt result;
	result.sign = '+';

	for (int i = 0; i < operand2.length(); ++i) {
		tmp.num = "0";
		for (int j = 0; j < operand2[i] - '0'; ++j) {
			tmp = tmp + *this;
		}
		tmp.num.resize(tmp.num.length() + (operand2.length() - 1 - i), '0');
		result = result + tmp;
	}
	return result;
}

// 此function用到重载过后的-
BigInt BigInt::operator/(const BigInt &bi)
{
	string operand1 = num;
	string operand2 = bi.num;
	BigInt quotient;
	quotient.sign = '+';
	if (operand1.length() < operand2.length())
	{
		quotient.num = "0";
		return quotient;
	}

	int m = operand1.length() - operand2.length();
	operand2.resize(operand1.length(), '0');
	BigInt dividend(operand1);
	BigInt divisor(operand2);
	for (int i = 0; i <= m; i++)
	{
		int tmp = 0;
		while ((dividend - divisor).sign != '-')
		{
			tmp++;
			dividend = dividend - divisor;
		}
		// string + char = concatenate
		quotient.num += ('0' + tmp);
		divisor.num.resize(divisor.num.length() - 1);
	}
	while (quotient.num[0] == '0')
	{
		quotient.num.erase(quotient.num.begin());
	}
	return quotient;
}


ostream & operator<<(ostream & o, const BigInt & bi) {
	if (bi.sign == '-') {
		o << bi.sign;
	}
	o << bi.num;
	return o;
}

int main() {
	string s1, s2;
	char op;
	cin >> s1 >> op >> s2;
	BigInt a(s1);
	BigInt b(s2);
	BigInt result;
	// cout << a;
	// cout << b;
	switch(op) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
	}
	cout << result << endl;
	return 0;
}



