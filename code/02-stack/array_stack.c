#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int size;
    int* data;
} Stack;

// 初始化一个最多可以存放size个整数的栈
Stack* initStack(int size) {
    Stack* pStack = malloc(sizeof(Stack));
    pStack->data = malloc(sizeof(int) * size);
    pStack->top = 0; // top代表下一个入栈的位置，所以top-1才表示当前的栈顶
    pStack->size = size;
    return pStack;
}

// 当这个栈满的时候应该返回0，表示push失败
int push(int elem, Stack* ps) {
    if (ps->top == ps->size) {
        // 当size为5的时候，top从0到4是有效的，所以top为5的时候是无效的
        printf("栈满了，不能push\n");
        return 0;
    }
    
    ps->data[ps->top] = elem;
    ps->top++;
    return 1;
}

// pop需要返回成功还是失败，又需要返回一个数值
int pop(Stack* ps, int* result) {
    if (ps->top == 0) {
        // 空栈
        printf("空栈，不能pop\n");
        return 0;
    }
    /*
    *result = ps->data[ps->top-1];
    ps->top--;
     */
    *result = ps->data[--(ps->top)];
    return 1;
}

int peek(Stack* ps, int * result) {
    if (ps->top == 0) {
        // 空栈
        printf("空栈，不能peek\n");
        return 0;
    }

    *result = ps->data[ps->top-1];
    return 1;
}


int rpn(char* a) {
    //自己写
    // 此处应该自己想，运用stack
    return 100;
}


int main(void) {
    char a[] = "5 1 2 + 4 * + 3 -";
    int r = rpn(a);
    
    return 0;
}

