#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int rsp;
} Stack;

int push(Stack* stack, int value) {
    int *t = stack->stack;

    stack->stack = malloc(stack->rsp);

    for (size_t i = 0; i < stack->rsp; i++) {
        stack->stack[i] = t[i];
    }

    stack->stack[stack->rsp] = value;
    stack->rsp = stack->rsp + 1;
}

int pop(Stack* stack) {
    // 파라미터로 stack 의 포인터위치 받음

    if (stack->rsp == 0) {
        return 0;
    }

    stack->rsp = stack->rsp - 1;
    int value = stack->stack[stack->rsp];
    stack->stack[stack->rsp] = 0;

    return value;
}

int main() {
    Stack *stack;
    stack->rsp = 0;

    push(stack, 5);
    push(stack, 4);

    printf("%d\n", stack->stack[1]); // 4
    
    printf("%d\n", pop(stack)); // 4

    printf("%d\n", stack->stack[0]); // 5
}