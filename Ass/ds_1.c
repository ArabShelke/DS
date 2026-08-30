#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

/* 1. String Reverse */
void stringReverse()
{
    char str[MAX];
    int i;

    top = -1;

    printf("\nEnter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    printf("Reversed String: ");

    while (top != -1)
    {
        printf("%c", pop());
    }

    printf("\n");
}

/* 2. Balancing Parenthesis */
void balancingParenthesis()
{
    char exp[MAX];
    int i;
    int balanced = 1;

    top = -1;

    printf("\nEnter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == -1)
            {
                balanced = 0;
                break;
            }

            pop();
        }
    }

    if (top != -1)
    {
        balanced = 0;
    }

    if (balanced)
        printf("Parentheses are Balanced.\n");
    else
        printf("Parentheses are Not Balanced.\n");
}

/* 3. Palindrome Checking */
void palindromeCheck()
{
    char str[MAX];
    int i;
    int palindrome = 1;

    top = -1;

    printf("\nEnter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != pop())
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("The string is a Palindrome.\n");
    else
        printf("The string is Not a Palindrome.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n========== STACK APPLICATIONS ==========\n");
        printf("1. String Reverse\n");
        printf("2. Balancing Parenthesis\n");
        printf("3. Palindrome Checking\n");
        printf("4. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                stringReverse();
                break;

            case 2:
                balancingParenthesis();
                break;

            case 3:
                palindromeCheck();
                break;

            case 4:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
