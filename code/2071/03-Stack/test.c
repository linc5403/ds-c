/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : test
 * @created     : Friday Aug 14, 2020 13:53:10 CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedStack.h"

// 判断s是否运算符
int isOpertor(char* s) {
    if (strlen(s) > 1) {
        return 0;
    }
    // 长度都为1
    switch (s[0]) {
        case '*': case '/': case '+': case '-':
            return 1;
        default:
            return 0;
    }
}

int evalRPN(char ** tokens, int tokensSize){
    Stack* ps = initStack();
    // 数字-> 入栈
    // 符号-> 弹出1个作为右边的操作数, 再弹出一个作为左边的操作数
    for (int i = 0; i < tokensSize; i++) {
        // 判断tokens[i]是数字还是符号
        if (isOpertor(tokens[i])) {
            // 符号
            int r = pop(ps);
            int l = pop(ps);
            int val;
            switch (tokens[i][0]) {
                case '+':
                    val = r + l; break;
                case '-':
                    val = l - r; break;
                case '*':
                    val = l * r; break;
                case '/':
                    val = l / r; break;
                default:
                    printf("出错啦\n");
                    return -100;
            }
            push(ps, val);
        } else {
            // 数字
            push(ps, atoi(tokens[i]));
        }
    }
    return pop(ps);
}


int main() {
    //char* a[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    char* a[] = {"4", "13", "5", "/", "+"};
    int val = evalRPN(a, sizeof(a) / sizeof(a[0]));
    printf("%d\n", val);
}

