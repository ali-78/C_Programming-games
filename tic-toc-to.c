#include <stdio.h>
#include <math.h>
//#include<time.h>
int main(void)
{
    int w, h;
    for (w = 0; w < 15; w++)
    {
        for (h = 0; h < 36; h++)
        {
            if (w == 0)
            {
                printf("_");
            }
            else if ((h == 0) || (h == 12) || (h == 24) || (h == 35))
            {
                printf("|");
            }
            else if ((w == 5) || (w == 10))
            {
                printf("_");
            }
            else if (w == 14)
            {
                printf("_");
            }
            else
            {
                printf(" ");
            }
        }
        if (w < 14)
        {
            printf("\n");
        }
    }
    printf("\n\n");

    char m[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    char m1;
    int i, j, count = 0;
    m[i][j];
    printf("please enter x or o:\n");
    scanf("%c", &m1);

    while (1)
    {

        if (count == 9)
        {
            printf("no one won");
            break;
        }

        printf("bazi ba = %c\n", m1);
        printf("please enter first i:\n");
        scanf("%d", &i);
        printf("please enter first j:\n");
        scanf("%d", &j);

        if ((i < 0) || (i > 2) || (j < 0) || (j > 2))
        {
            printf("wrong asigning\n");
            continue;
        }

        if ((m[i][j] == 'o') || (m[i][j] == 'x'))
        {
            printf("This position is fill please try again\n");
            continue;
        }

        else
        {
            count++;
        }

        m[i][j] = m1;

        int w, h;
        for (w = 0; w < 15; w++)
        {
            for (h = 0; h < 36; h++)
            {
                if (w == 0)
                {
                    printf("_");
                }
                else if ((h == 0) || (h == 12) || (h == 24) || (h == 35))
                {
                    printf("|");
                }
                else if ((w == 5) || (w == 10))
                {
                    printf("_");
                }
                else if (w == 14)
                {
                    printf("_");
                }
                else if ((h == 6) && (w == 3))
                {
                    printf("%c", m[0][0]);
                }
                else if ((h == 18) && (w == 3))
                {
                    printf("%c", m[0][1]);
                }
                else if ((h == 30) && (w == 3))
                {
                    printf("%c", m[0][2]);
                }
                else if ((h == 6) && (w == 8))
                {
                    printf("%c", m[1][0]);
                }
                else if ((h == 18) && (w == 8))
                {
                    printf("%c", m[1][1]);
                }
                else if ((h == 30) && (w == 8))
                {
                    printf("%c", m[1][2]);
                }
                else if ((h == 6) && (w == 12))
                {
                    printf("%c", m[2][0]);
                }
                else if ((h == 18) && (w == 12))
                {
                    printf("%c", m[2][1]);
                }
                else if ((h == 30) && (w == 12))
                {
                    printf("%c", m[2][2]);
                }
                else
                {
                    printf(" ");
                }
            }
            if (w < 14)
            {
                printf("\n");
            }
        }
        printf("\n\n");

        if (((m[0][0] == m[1][1]) && (m[1][1] == m[2][2]) &&
             (m[0][0] == m1)) ||
            ((m[0][2] == m[1][1]) &&
             (m[1][1] == m[2][0]) && (m[0][2] == m1)) ||
            ((m[0][0] == m[0][1]) &&
             (m[0][1] == m[0][2]) && (m[0][2] == m1)) ||
            ((m[0][0] == m[1][0]) &&
             (m[1][0] == m[2][0]) && (m[2][0] == m1)) ||
            ((m[0][2] == m[1][2]) &&
             (m[1][2] == m[2][2]) && (m[2][2] == m1)) ||
            ((m[2][0] == m[2][1]) &&
             (m[2][1] == m[2][2]) && (m[2][2] == m1)) ||
            ((m[1][0] == m[1][1]) &&
             (m[1][1] == m[1][2]) && (m[1][2] == m1)) ||
            ((m[0][1] == m[1][1]) &&
             (m[1][1] == m[2][1]) && (m[2][1] == m1)))
        {

            if (m1 == 'o')
            {
                printf("o win");
                break;
            }
            else if (m1 == 'x')
            {
                printf("x win");
                break;
            }
        }
        if (m1 == 'x')
        {
            m1 = 'o';
        }
        else
        {
            m1 = 'x';
        }
    }
    return 0;
}
