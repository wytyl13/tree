#include "../inc/stack.h"

void initStack(SqStackP stack) 
{
    stack->top = -1;
}

bool emptyStack(SqStackP stack) 
{
    return (stack->top == -1);
}

bool fullStack(SqStackP stack) 
{
    return (stack->top == MAXSIZE - 1);
}

bool push(SqStackP stack, ElementType element) 
{
    if (fullStack(stack))
    {
        return false; // stack is full
    }
    stack->data[++stack->top] = element;
    return true;
}

bool pop(SqStackP stack, ElementTypeP elementP) 
{
    if (emptyStack(stack))
    {
        return false; // stack is empty
    }
    *elementP = stack->data[stack->top--];
    return true;
}

ElementType getTop(SqStackP stack) 
{
    if (emptyStack(stack))
    {
        sysError("getTop error\n");
    }
    return stack->data[stack->top];
}

void initStackTree(SqStackTreeP stackTree) 
{
    stackTree->top = -1;
}

bool emptyStackTree(SqStackTreeP stackTree) 
{
    return (stackTree->top == -1);
}

bool fullStackTree(SqStackTreeP stackTree) 
{
    return (stackTree->top == MAXSIZE - 1);
}

// notice, this pointer array stored void *pointer.
// if you want to assignment it, you should cast first.
bool pushTree(SqStackTreeP stackTree, void *pointer) 
{
    // ElementTypeP elementP = (ElementTypeP)pointer;
    if (fullStackTree(stackTree))
    {
        return false;
    }
    stackTree->data[++stackTree->top] = pointer;
    return true;
}

bool popTree(SqStackTreeP stackTree, void *pointer) 
{
    if (emptyStackTree(stackTree))
    {
        return false; // stack is empty
    }
    pointer = stackTree->data[stackTree->top--];
    return true;
}

void *getTopTree(SqStackTreeP stackTree) 
{
    if (emptyStackTree(stackTree))
    {
        sysError("getTopTree error\n");
    }
    return stackTree->data[stackTree->top];
}
