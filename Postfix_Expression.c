#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define max 30
#define postfixsize 30

void evaluatepostfix(char postfix[]);
void push(int item);
int pop();

int top = -1;

int main()
{
    int i;
    char postfix[postfixsize], st[30];

    printf("Enter postfix expression and press right parenthesis to end expression: ");

    for (i = 0; i <= postfixsize - 1; i++)
    {
        scanf("%c", &postfix[i]);
        if (postfix[i] == ')')
            break;
    }

    evaluatepostfix(postfix);
    return 0;
}

void evaluatepostfix(char postfix[])
{
    int i, value, op1, op2;
    char ch;
    char st[30]; // Declare st with appropriate data type

    for (i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            op1 = pop();
            op2 = pop();

            switch (ch)
            {
            case '*':
                value = op2 * op1;
                break;
            case '/':
                value = op2 / op1;
                break;
            case '+':
                value = op2 + op1;
                break;
            case '-':
                value = op2 - op1;
                break;
            }

            push(value);
        }
    }

    printf("Result of postfix expression evaluation is %d\n", pop());
}

void push(int item)
{ char st[30];
    if (top >= max - 1)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        top++;
        st[top] = item;
    }
}

int pop()
{
    int item;
    char st[30];

    if (top < 0)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        item = st[top];
        top--;
        return item;
    }
    }
