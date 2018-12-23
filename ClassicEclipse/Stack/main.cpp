#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "LStack.h"

using namespace std;


// 判断是否为运算符，是则返回true，否则返回false
bool judgeOperator (string x) {
	if (x == "+" || x == "-")
		return true;
	if (x == "*" || x == "/")
		return true;
	if (x == "(" || x == ")")
		return true;
	return false;
}

/*
 *	判断前者相对于后者是否为优先运算符
 *  Top_Operation为当前栈顶顶运算符，Infix_Operation为当前读入的运算符
 *  若栈顶运算符优先，返回true，接下来弹出栈顶运算符；反之，则返回false，接下来压入当前读到的运算符
 */
bool IsPriority (string Top_Operation, string Input_Operation) {
	if (Top_Operation == "+" || Top_Operation == "-")
		if (Input_Operation == "+" || Input_Operation == "-")
			return true;
	if (Top_Operation == "*" || Top_Operation == "/")
		if (Input_Operation != "(")
			return true;
	if (Input_Operation == ")")
		return true;
	return false;
}

// 判断是否为多位数，即在中缀表达式中相邻两个字符是否均为数字
// 若是多位数则返回true， 若不是多位数则返回false
bool judge_LongNum(string &Push_Exp, string& Cash_Exp) {
	if (judgeOperator(Push_Exp) || judgeOperator(Cash_Exp))
		return false;
	return true;
}

void Exp_push(string& str, LStack<string>& Ls_PostfixExp, LStack<string>& Ls_operator) {
	if (!judgeOperator(str))
            // 若为数字则直接压入后缀表达式栈中
            Ls_PostfixExp.push(str);
    else {
    // 若为操作符
    	if (Ls_operator.length() == 0)
    	// 若操作符的栈为空，则直接将操作符压入栈中
    		Ls_operator.push(str);

    	else if (IsPriority(Ls_operator.topValue(), str)) {
    	// 若操作符栈的优先级高于输入字符串
    		if (str == ")") {
    		// 若输入字符串的运算符为")"，则不断弹出运算符栈中的运算符直到弹出"("
    			while ((Ls_operator.length() != 0) && (Ls_operator.topValue() != "("))
                    Ls_PostfixExp.push(Ls_operator.pop());
    			if ((Ls_operator.length() != 0) && (Ls_operator.topValue() == "("))
    			    Ls_operator.pop();
    		} else {
    		// 若输入字符串的运算符不为“）”，则一直弹出优先级高的操作符直到低于输入字符串
    			while ((Ls_operator.length() != 0) && IsPriority(Ls_operator.topValue(), str))
                    Ls_PostfixExp.push(Ls_operator.pop());
    			Ls_operator.push(str);
    		}
    	} else
    	// 操作符栈的优先级低于输入字符串
    		Ls_operator.push(str);
    }
}

// 将后缀表达式压入栈中
void Input_Expression(LStack<string>& Ls_PostfixExp) {

	string str_Exp;
	getline(cin,str_Exp);
	// 先输出中缀表达式
	cout << str_Exp << endl;
	int times(str_Exp.length());

	istringstream iss_Exp(str_Exp);
	string s;
	char c_Exp;
	// 建立一个缓存字符串用于判断连续两个字符是否为多位数
    string str_cash;
	stringstream stream;

	// 用于存放操作符的栈
	LStack<string> Ls_operator;

    iss_Exp >> c_Exp;
    stream << c_Exp;
    str_Exp = stream.str();
    stream.str("");
    times--;

    while(times) {
        iss_Exp >> c_Exp;
		stream << c_Exp;
		str_cash = stream.str();
        stream.str("");
        times--;

        if (judge_LongNum(str_Exp, str_cash)) {
            str_Exp = str_Exp + str_cash;
            str_cash.clear();
        }
        else {
            Exp_push(str_Exp, Ls_PostfixExp, Ls_operator);
            str_Exp = str_cash;
            str_cash.clear();
        }
	}

    Exp_push(str_Exp, Ls_PostfixExp, Ls_operator);

	while (Ls_operator.length() != 0)
    // 将操作符缓存区剩下的
    	Ls_PostfixExp.push(Ls_operator.pop());
}

// 输出后缀表达式
void Output_Expression(LStack<string>& Ls_PostfixExp) {
	LStack<string> Ls_cash;

	while (Ls_PostfixExp.length())
		Ls_cash.push(Ls_PostfixExp.pop());
	
	while (Ls_cash.length()-1) {
		Ls_PostfixExp.push(Ls_cash.pop());
        cout << Ls_PostfixExp.topValue() << " ";
	}
    Ls_PostfixExp.push(Ls_cash.pop());
    cout << Ls_PostfixExp.topValue();
}

// 计算后缀表达式的值
void Exp_calculate(LStack<string>& Ls_PostfixExp) {
    // 用于将后缀表达式栈中的数据以流的方式格式化输出
    stringstream ss;
    // 用于读取每次弹出的栈
    string str_NumOpe;
    // 缓存区，用于将原后缀表达式栈逆序
    LStack<string> Ls_cash;

    // 用于处理遇到运算符事弹出两数的计算
    int i_Num;
    LStack<int> Ls_Num;

    string s;

    cout << endl;
    // 先将后缀表达式栈逆序
    while (Ls_PostfixExp.length())
        Ls_cash.push(Ls_PostfixExp.pop());

    while (Ls_cash.length()) {
        // 读取缓存区中弹出的元素
        str_NumOpe = Ls_cash.pop();

        // 若是操作数，则直接存入栈中
        if (!judgeOperator(str_NumOpe)) {
            ss << str_NumOpe;
            ss >> i_Num;
            Ls_Num.push(i_Num);
            ss.clear();
            ss.str("");
        }

        // 若是操作运算符，则弹出两个数进行运算
        else {
            i_Num = Ls_Num.pop();

            // 判断操作运算符类型进行运算
            if (str_NumOpe == "+") {
                i_Num = Ls_Num.pop() + i_Num;
                Ls_Num.push(i_Num);
            } else if (str_NumOpe == "-") {
                i_Num = Ls_Num.pop() - i_Num;
                Ls_Num.push(i_Num);
            } else if (str_NumOpe == "*") {
                i_Num = Ls_Num.pop() * i_Num;
                Ls_Num.push(i_Num);
            } else {
                i_Num = Ls_Num.pop() / i_Num;
                Ls_Num.push(i_Num);
            }
        }
    }
    cout << Ls_Num.pop();
}

int main() {
    LStack<string> Ls_PostfixExp; // 用于存储后缀表达式

    Input_Expression(Ls_PostfixExp);

    Output_Expression(Ls_PostfixExp);

    Exp_calculate(Ls_PostfixExp);

    return EXIT_SUCCESS;
}

