#include <stack>
#include <string>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

// 异常类定义
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "错误：栈元素不足";
    }
};

class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "错误：除零错误";
    }
};

class InvalidInputException : public exception {
public:
    const char* what() const noexcept override {
        return "错误：无效输入";
    }
};

// RPN计算器核心类
class RPNCalculator {
private:
    stack<double> dataStack;
    
    void checkStackSize(int required) const {
        if (dataStack.size() < required) {
            throw StackUnderflowException();
        }
    }

public:
    // 栈操作
    void push(double value) {
        dataStack.push(value);
    }
    
    double pop() {
        checkStackSize(1);
        double val = dataStack.top();
        dataStack.pop();
        return val;
    }
    
    void clear() {
        while (!dataStack.empty()) dataStack.pop();
    }
    
    // 计算核心
    void calculate(const string& op) {
        double a, b;
        
        if (op == "+") {
            checkStackSize(2);
            a = pop(); b = pop();
            push(b + a);
        } else if (op == "-") {
            checkStackSize(2);
            a = pop(); b = pop();
            push(b - a);
        } else if (op == "*") {
            checkStackSize(2);
            a = pop(); b = pop();
            push(b * a);
        } else if (op == "/") {
            checkStackSize(2);
            a = pop(); b = pop();
            if (fabs(a) < 1e-9) throw DivisionByZeroException();
            push(b / a);
        } else {
            throw InvalidInputException();
        }
    }
    
    // 处理输入
    void processInput(const string& input) {
        istringstream iss(input);
        string token;
        
        while (iss >> token) {
            // 处理特殊命令
            if (token == "clear") {
                clear();
                cout << "栈已清空" << endl;
                continue;
            } else if (token == "show") {
                stack<double> temp = dataStack;
                cout << "栈内容: ";
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                cout << endl;
                continue;
            }
            
            // 解析数字
            istringstream numIss(token);
            double num;
            if (numIss >> num) {
                push(num);
            } else {
                calculate(token); // 解析运算符
            }
        }
        
        // 显示结果
        if (!dataStack.empty()) {
            cout << "结果: " << dataStack.top() << endl;
        }
    }
};

// 主函数
int main() {
    RPNCalculator calc;
    string input;
    
    cout << "RPN计算器 (输入q退出, clear清空, show显示栈)" << endl;
    
    while (true) {
        cout << "> ";
        getline(cin, input);
        
        if (input == "q" || input == "Q") break;
        if (input.empty()) continue;
        
        try {
            calc.processInput(input);
        } catch (const exception& e) {
            cout << e.what() << endl;
            calc.clear();
        }
    }
    
    return 0;
}
