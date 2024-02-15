#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int test;
    printf(" Enter \n 1. For recognize comments and how many letters are in comments. \n 2. For recognize the types of comments. \n 3. For find the number of line where the comments are written. \n 4. Recognize string under rule a*b+c* \n 5. Constructing of LL(1) parsing");

    scanf("%d", &test);

    if (test == 1)
    {

        char com[100];
        int i = 0, a = 0, len = 0, g = 0;
        printf("\n Enter ~ to exit the program");
        printf("\n Enter comment: ");

        scanf("%[^~]", com);

        for (i = 0; i <= 100; i++)
        {

            if (com[i] == '/')
            {
                if (com[i + 1] == '/')
                {

                    printf("\n\n\n");

                    for (i = i + 2; com[i] != '\0'; i++)
                    {
                        if (com[i] == '\n')
                        {

                            break;
                        }
                        len++;
                        printf("%c", com[i]);
                    }
                    g = 1;
                    printf(" is a comment\n");
                    printf("Number of letters : %d\n\n\n", len);
                    len = 0;
                }

                else if (com[i + 1] == '*')
                {
                    for (i = i + 2; i <= 100; i++)
                    {

                        if (com[i] == '*' && com[i + 1] == '/')
                        {

                            g = 1;
                            printf(" is a comment\n");

                            printf("Number of letters : %d", len);
                            a = 1;
                            len = 0;
                            break;
                        }
                        else
                            printf("%c", com[i]);

                        len++;
                        continue;
                    }
                    if (a == 0)
                        g = 0;
                }
            }
        }
        if (g == 0)
        {
            printf("\nThere is no comment");
        }
    }
    /*------------------------------------------------------------*/
    else if (test == 2)
    {

        char com[100];
        int i = 0, a = 0, g = 0;
        printf("\n Enter ~ to exit the program");
        printf("\n Enter comment:");

        scanf("%[^~]", com);

        for (i = 0; i <= 100; i++)
        {

            if (com[i] == '/')
            {
                if (com[i + 1] == '/')
                {

                    printf("\n\n\n");

                    for (i = i + 2; com[i] != '\0'; i++)
                    {
                        if (com[i] == '\n')
                        {

                            break;
                        }
                        printf("%c", com[i]);
                    }

                    g = 1;
                    printf(" is Single line comment\n\n\n");
                }

                else if (com[i + 1] == '*')
                {
                    for (i = i + 2; i <= 100; i++)
                    {

                        if (com[i] == '*' && com[i + 1] == '/')
                        {

                            g = 1;
                            printf(" is Multi-line comment\n");
                            a = 1;
                            break;
                        }
                        else
                            printf("%c", com[i]);

                        continue;
                    }
                    if (a == 0)
                        g = 0;
                }
            }
        }
        if (g == 0)
        {
            printf("\nThere is no comment");
        }
    }
    /*------------------------------------------------------------*/
    else if (test == 3)
    {

        char com[100];
        int i = 0, a = 0, len = 0, g = 0, line = 0;
        printf("\n Enter ~ to exit the program");
        printf("\n Enter comment:");

        scanf("%[^~]", com);

        for (i = 0; i <= 100; i++)
        {

            if (com[i] == '/')
            {
                if (com[i + 1] == '/')
                {

                    printf("\n\n\n");

                    for (i = i + 2; com[i] != '\0'; i++)
                    {
                        if (com[i] == '\n')
                        {
                            line++;
                            break;
                        }
                        len++;
                        printf("%c", com[i]);
                    }

                    g = 1;
                    printf(" is Single line comment\n");
                    printf("Number of letters : %d\n\n\n", len);
                    len = 0;
                    line++;
                }

                else if (com[i + 1] == '*')
                {
                    for (i = i + 2; i <= 100; i++)
                    {
                        if (com[i] == '\n')
                        {
                            line++;
                        }

                        if (com[i] == '*' && com[i + 1] == '/')
                        {

                            g = 1;
                            printf(" is Multi-line comment\n");

                            printf("Number of letters : %d", len);
                            a = 1;
                            len = 0;
                            break;
                        }
                        else
                            printf("%c", com[i]);

                        len++;
                        continue;
                    }
                    if (a == 0)
                        g = 0;
                }
            }
        }
        if (g == 0)
        {
            printf("\nThere is no comment");
        }

        printf("\n\n\nNumber of line is : %d", line);
    }
    /*------------------------------------------------------------*/
    else if (test == 4)
    {
        char s[30], c;
        int state = 0, i = 0;

        printf("Enter a string\n");
        fgets(s, 30, stdin);

        printf("data is %s", s);
        while (s[i] != '\0')
        {

            switch (state)
            {
            case 0:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                else
                    state = 4;
                break;

            case 1:
                c = s[i++];
                if (c == 'a')
                {
                    state = 1;
                }
                else if (c == 'b')
                    state = 2;
                else
                    state = 4;
                break;

            case 2:
                c = s[i++];
                if (c == 'b')
                {
                    state = 2;
                }
                else if (c == 'a')
                    state = 4;
                else if (c == 'c')
                    state = 3;
                else
                    state = 3;
                break;

            case 3:
                c = s[i++];
                printf("data = %c and state = %d\n", c, state);
                break;
            }
        }
        if (state == 1 || state == 2 || state == 3)
        {
            printf("%s is accepted", s);
        }
        else
        {
            printf("%s is not accepted ", s);
        }
        return 0;
    }
    /*------------------------------------------------------------*/
    else if (test == 5)
    {
        char s[20], stack[20];
        char m[5][6][3] = {"tb", " ", " ", "tb", " ", " ", " ", "+tb", " ", " ", "n", "n", "fc", " ", "", "fc", " ", " ", " ", "n", "*fc", " a ", "n", "n", "i", " ", " ", "(e)", " ", " "};
        int size[5][6] = {2, 0, 0, 2, 0, 0, 0, 3, 0, 0, 1, 1, 2, 0, 0, 2, 0, 0, 0, 1, 3, 0, 1, 1, 1, 0, 0, 3, 0, 0};
        int i, j, k, n, str1, str2;

        printf("\n Enter the input string: ");
        scanf("%s", s);
        strcat(s, "$");
        n = strlen(s);

        stack[0] = '$';
        stack[1] = 'e';

        i = 1;
        j = 0;

        printf("\nStack Input\n");
        printf("__________________\n");

        while ((stack[i] != '$') && (s[j] != '$'))
        {
            if (stack[i] == s[j])
            {
                i--;
                j++;
            }
            switch (stack[i])
            {
            case 'e':
                str1 = 0;
                break;
            case 'b':
                str1 = 1;
                break;
            case 't':
                str1 = 2;
                break;
            case 'c':
                str1 = 3;
                break;
            case 'f':
                str1 = 4;
                break;
            }
            switch (s[j])
            {
            case 'i':
                str2 = 0;
                break;
            case '+':
                str2 = 1;
                break;
            case '*':
                str2 = 2;
                break;
            case '(':
                str2 = 3;
                break;
            case ')':
                str2 = 4;
                break;
            case '$':
                str2 = 5;
                break;
            }
            if (m[str1][str2][0] == '\0')
            {
                printf("\nERROR");
                exit(0);
            }
            else if (m[str1][str2][0] == 'n')
                i--;
            else if (m[str1][str2][0] == 'i')
                stack[i] = 'i';
            else
            {
                for (k = size[str1][str2] - 1; k >= 0; k--)
                {
                    stack[i] = m[str1][str2][k];
                    i++;
                }
                i--;
            }
            for (k = 0; k <= i; k++)
                printf(" %c", stack[k]);
            printf(" ");
            for (k = j; k <= n; k++)
                printf("%c", s[k]);
            printf(" \n ");
        }
        printf("\n SUCCESS");
        getch();
    }
    /*------------------------------------------------------------*/
    else
    {
        printf("Error value, Try again later");
    }
}
