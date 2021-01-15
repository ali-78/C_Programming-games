#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define gray "\x1b[100m"
#define black "\x1b[30m"
#define red "\x1b[41m"
#define tx_red "\x1b[31m"
#define lightRed "\x1b[101m"
#define green "\x1b[42m"
#define tx_green "\x1b[32m"
#define lightGreen "\x1b[102m"
#define yellow "\x1b[43m"
#define lightYellow "\x1b[103m"
#define blue "\x1b[44m"
#define tx_blue "\x1b[34m"
#define lightBlue "\x1b[104m"
#define magenta "\x1b[45m"
#define lightMagenta "\x1b[105m"
#define cryn "\x1b[46m"
#define lightCryn "\x1b[106m"
#define reset "\x1b[0m"

void go_up(int m[4][4], int event[4][4]);
void go_down(int m[4][4], int event[4][4]);
void go_right(int m[4][4], int event[4][4]);
void go_left(int m[4][4], int event[4][4]);

void go_back(int m[4][4], int event[4][4]);
bool end_game(int m[4][4]);

void bg_color(int m[4][4], int i, int j);
void print_shape(int m[4][4]);
int main(void)
{
    printf("\n\n");
    printf("\t\t     Wellcome to 2048");
    printf("\n\n\n\n\n\n\n\n\n\n\n");

    sleep(1);
    printf("\33[A");
    puts("\t\t\tProgrammer  ");
    sleep(2);
    printf("\33[A");
    puts(tx_red "\t\t\tAli Taghipour" reset);
    sleep(2);
    system("clear");

lable:
    while (1)
    {
        system("clear");

        char key;
        int chance, r1, r2, r3, r4, m[4][4] = {0}, event[4][4] = {0};
        time_t t = time(NULL);
        srand(t);
        r1 = rand() % 4;
        r2 = rand() % 4;
        r3 = rand() % 4;
        r4 = rand() % 4;

        chance = rand() % 3;
        if ((chance == 0) || (chance == 1))
        {
            m[r1][r2] = 2;
            event[r1][r2] = m[r1][r2];
            m[r3][r4] = 2;
            event[r3][r4] = m[r3][r4];
        }
        else
        {
            m[r1][r2] = 2;
            event[r1][r2] = m[r1][r2];
            m[r3][r4] = 4;
            event[r3][r4] = m[r3][r4];
        }

        print_shape(m);

        printf("w = up\ns = down\na = left\nd = right\nu = undo(you can use for one time per movement)\nr = restart the game\n\n");

        while (1)
        {
            if (end_game(m) == true)
            {
                printf("Game Over\n");
                gets(&key);
                printf("Do you wanna play again y/n?");
                while ((key != 'y') && (key != 'n'))
                {
                    printf("you have entered incorrect keyworld\nplease try again\n");
                    gets(&key);
                }
                if (key == 'y')
                {
                    goto lable;
                }
                else
                {
                    break;
                }
            }
            printf("please enter your keyworld\n");
            gets(&key);
            while ((key != 'w') && (key != 's') && (key != 'd') && (key != 'a') && (key != 'r') && (key != 'u'))
            {
                printf("you have entered incorrect keyworld\nplease try again\n");
                gets(&key);
            }

            if (key == 'r')
            {
                goto lable;
            }

            else if (key == 'u')
            {
                go_back(m, event);
            }

            else if (key == 'w')
            {
                go_up(m, event);
            }

            else if (key == 's')
            {
                go_down(m, event);
            }

            else if (key == 'd')
            {
                go_right(m, event);
            }

            else
            {
                go_left(m, event);
            }

            system("clear");

            print_shape(m);
        }
        break;
    }
    return 0;
}

void go_up(int m[4][4], int event[4][4])
{
    int i, j, g, r, r1, r2;
    bool move_event = false;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            event[i][j] = m[i][j];
        }
    }

    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 3; i++)
        {
            for (g = 0; g < 3; g++)
            {
                if (m[g][j] == 0)
                {
                    m[g][j] = m[g + 1][j];
                    m[g + 1][j] = 0;
                }
            }
        }

        for (i = 0; i < 3; i++)
        {
            if (m[i][j] == m[i + 1][j])
            {
                m[i][j] += m[i + 1][j];
                m[i + 1][j] = 0;
            }
        }

        for (i = 0; i < 2; i++)
        {
            for (g = 0; g < 3; g++)
            {
                if (m[g][j] == 0)
                {
                    m[g][j] = m[g + 1][j];
                    m[g + 1][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (event[i][j] != m[i][j])
            {
                move_event = true;
                break;
            }
        }
    }

    while (move_event == true)
    {
        r1 = rand() % 2 + 2;
        r2 = rand() % 4;

        if (m[r1][r2] == 0)
        {
            m[r1][r2] = 2;
            break;
        }
    }
}

void go_down(int m[4][4], int event[4][4])
{
    int i, j, g, r, r1, r2;
    bool move_event = false;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            event[i][j] = m[i][j];
        }
    }

    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 3; i++)
        {
            for (g = 3; g > 0; g--)
            {
                if (m[g][j] == 0)
                {
                    m[g][j] = m[g - 1][j];
                    m[g - 1][j] = 0;
                }
            }
        }

        for (i = 3; i > 0; i--)
        {
            if (m[i][j] == m[i - 1][j])
            {
                m[i][j] += m[i - 1][j];
                m[i - 1][j] = 0;
            }
        }

        for (i = 0; i < 2; i++)
        {
            for (g = 3; g > 0; g--)
            {
                if (m[g][j] == 0)
                {
                    m[g][j] = m[g - 1][j];
                    m[g - 1][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (event[i][j] != m[i][j])
            {
                move_event = true;
                break;
            }
        }
    }

    while (move_event == true)
    {
        r1 = rand() % 2;
        r2 = rand() % 4;

        if (m[r1][r2] == 0)
        {
            m[r1][r2] = 2;
            break;
        }
    }
}

void go_right(int m[4][4], int event[4][4])
{
    int i, j, g, r, r1, r2;
    bool move_event = false;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            event[i][j] = m[i][j];
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (g = 3; g > 0; g--)
            {
                if (m[i][g] == 0)
                {
                    m[i][g] = m[i][g - 1];
                    m[i][g - 1] = 0;
                }
            }
        }

        for (j = 3; j > 0; j--)
        {
            if (m[i][j] == m[i][j - 1])
            {
                m[i][j] += m[i][j - 1];
                m[i][j - 1] = 0;
            }
        }

        for (j = 0; j < 2; j++)
        {
            for (g = 3; g > 0; g--)
            {
                if (m[i][g] == 0)
                {
                    m[i][g] = m[i][g - 1];
                    m[i][g - 1] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (event[i][j] != m[i][j])
            {
                move_event = true;
                break;
            }
        }
    }

    while (move_event == true)
    {
        r1 = rand() % 4;
        r2 = rand() % 2;

        if (m[r1][r2] == 0)
        {
            m[r1][r2] = 2;
            break;
        }
    }
}

void go_left(int m[4][4], int event[4][4])
{
    int i, j, g, r, r1, r2;
    bool move_event = false;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            event[i][j] = m[i][j];
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (g = 0; g < 3; g++)
            {
                if (m[i][g] == 0)
                {
                    m[i][g] = m[i][g + 1];
                    m[i][g + 1] = 0;
                }
            }
        }

        for (j = 0; j < 3; j++)
        {
            if (m[i][j] == m[i][j + 1])
            {
                m[i][j] += m[i][j + 1];
                m[i][j + 1] = 0;
            }
        }

        for (j = 0; j < 2; j++)
        {
            for (g = 0; g < 3; g++)
            {
                if (m[i][g] == 0)
                {
                    m[i][g] = m[i][g + 1];
                    m[i][g + 1] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (event[i][j] != m[i][j])
            {
                move_event = true;
                break;
            }
        }
    }

    while (move_event == true)
    {
        r1 = rand() % 4;
        r2 = rand() % 2 + 2;

        if (m[r1][r2] == 0)
        {
            m[r1][r2] = 2;
            break;
        }
    }
}

void go_back(int m[4][4], int event[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            m[i][j] = event[i][j];
        }
    }
}

bool end_game(int m[4][4])
{
    int i, j, essum = 0;
    bool up_down = true;
    bool left_right = true;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (m[i][j] == 0)
            {
                essum++;
            }
        }
    }

    if (essum == 0)
    {
        // ability to sum from up_down
        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 3; i++)
            {
                if (m[i][j] == m[i + 1][j])
                {
                    up_down = false;
                }
            }
        }

        // ability to sum from left_right
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (m[i][j] == m[i][j + 1])
                {
                    left_right = false;
                }
            }
        }

        if ((up_down == true) && (left_right == true))
        {
            return true;
        }
    }
    return false;
}

void bg_num_color(int m[4][4], int i, int j)
{
    char color[12][15] = {red, lightRed, green, lightGreen, yellow, lightYellow, blue, lightBlue, magenta, lightMagenta, cryn, lightCryn};
    int mcolor[4][4];
    mcolor[i][j] = m[i][j];
    int power = 0;

    while (mcolor[i][j] > 1)
    {
        mcolor[i][j] /= 2;
        power++;
    }
    power--;

    if (m[i][j] != 0)
    {
        printf("%s" black
               "%d" reset,
               color[power], m[i][j]);
    }
    else
    {
        printf(gray " " reset);
    }
}
void bg_color(int m[4][4], int i, int j)
{
    char color[12][15] = {red, lightRed, green, lightGreen, yellow, lightYellow, blue, lightBlue, magenta, lightMagenta, cryn, lightCryn};
    int mcolor[4][4];
    mcolor[i][j] = m[i][j];
    int power = 0;

    while (mcolor[i][j] > 1)
    {
        mcolor[i][j] /= 2;
        power++;
    }
    power--;

    if (m[i][j] != 0)
    {
        printf("%s"
               " " reset,
               color[power]);
    }
    else
    {
        printf(gray " " reset);
    }
}

void print_shape(int m[4][4])
{
    int w, h, i1[4][4] = {0}, i2[4][4] = {0}, mcount1, mcount2;

    for (mcount1 = 0; mcount1 < 4; mcount1++)
    {
        for (mcount2 = 0; mcount2 < 4; mcount2++)
        {
            if (m[mcount1][mcount2] > 9)
            {
                if (m[mcount1][mcount2] < 100)
                {
                    i1[mcount1][mcount2] = 1;
                    i2[mcount1][mcount2] = 0;
                }
                else if (m[mcount1][mcount2] < 1000)
                {
                    i1[mcount1][mcount2] = 1;
                    i2[mcount1][mcount2] = 1;
                }
                else if (m[mcount1][mcount2] < 10000)
                {
                    i1[mcount1][mcount2] = 2;
                    i2[mcount1][mcount2] = 1;
                }
                else if (m[mcount1][mcount2] < 100000)
                {
                    i1[mcount1][mcount2] = 2;
                    i2[mcount1][mcount2] = 2;
                }
                else if (m[mcount1][mcount2] < 1000000)
                {
                    i1[mcount1][mcount2] = 3;
                    i2[mcount1][mcount2] = 2;
                }
            }
        }
    }

    for (w = 1; w < 25; w++)
    {
        for (h = 1; h < 49; h++)
        {
            if (w == 0)
            {
                printf("");
            }

            // m[0][0]
            else if (((0 < h) && (h < 12)) && ((0 < w) && (w < 6)))
            {
                if (((h >= 6 - i1[0][0]) && (h < 6)) && (w == 3))
                {
                    printf("");
                }
                else if ((h == 6) && (w == 3))
                {
                    bg_num_color(m, 0, 0);
                }
                else if (((h > 6) && (h <= 6 + i2[0][0])) && (w == 3))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 0, 0);
                }
            }

            // m[1][0]
            else if (((0 < h) && (h < 12)) && ((6 < w) && (w < 12)))
            {
                if (((h >= 6 - i1[1][0]) && (h < 6)) && (w == 9))
                {
                    printf("");
                }
                else if ((h == 6) && (w == 9))
                {
                    bg_num_color(m, 1, 0);
                }
                else if (((h > 6) && (h <= 6 + i2[1][0])) && (w == 9))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 1, 0);
                }
            }

            // m[2][0]
            else if (((0 < h) && (h < 12)) && ((12 < w) && (w < 18)))
            {
                if (((h >= 6 - i1[2][0]) && (h < 6)) && (w == 15))
                {
                    printf("");
                }
                else if ((h == 6) && (w == 15))
                {
                    bg_num_color(m, 2, 0);
                }
                else if (((h > 6) && (h <= 6 + i2[2][0])) && (w == 15))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 2, 0);
                }
            }

            // m[3][0]
            else if (((0 < h) && (h < 12)) && ((18 < w) && (w < 24)))
            {
                if (((h >= 6 - i1[3][0]) && (h < 6)) && (w == 21))
                {
                    printf("");
                }
                else if ((h == 6) && (w == 21))
                {
                    bg_num_color(m, 3, 0);
                }
                else if (((h > 6) && (h <= 6 + i2[3][0])) && (w == 21))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 3, 0);
                }
            }

            else if (h == 12)
            {
                printf(" ");
            }

            // m[0][1]
            else if (((12 <= h) && (h < 24)) && ((0 < w) && (w < 6)))
            {
                if (((h >= 18 - i1[0][1]) && (h < 18)) && (w == 3))
                {
                    printf("");
                }
                else if ((h == 18) && (w == 3))
                {
                    bg_num_color(m, 0, 1);
                }
                else if (((h > 18) && (h <= 18 + i2[0][1])) && (w == 3))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 0, 1);
                }
            }

            // m[1][1]
            else if (((12 <= h) && (h < 24)) && ((6 < w) && (w < 12)))
            {
                if (((h >= 18 - i1[1][1]) && (h < 18)) && (w == 9))
                {
                    printf("");
                }
                else if ((h == 18) && (w == 9))
                {
                    bg_num_color(m, 1, 1);
                }
                else if (((h > 18) && (h <= 18 + i2[1][1])) && (w == 9))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 1, 1);
                }
            }

            // m[2][1]
            else if (((12 <= h) && (h < 24)) && ((12 < w) && (w < 18)))
            {
                if (((h >= 18 - i1[2][1]) && (h < 18)) && (w == 15))
                {
                    printf("");
                }
                else if ((h == 18) && (w == 15))
                {
                    bg_num_color(m, 2, 1);
                }
                else if (((h > 18) && (h <= 18 + i2[2][1])) && (w == 15))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 2, 1);
                }
            }

            // m[3][1]
            else if (((12 <= h) && (h < 24)) && ((18 < w) && (w < 24)))
            {
                if (((h >= 18 - i1[3][1]) && (h < 18)) && (w == 21))
                {
                    printf("");
                }
                else if ((h == 18) && (w == 21))
                {
                    bg_num_color(m, 3, 1);
                }
                else if (((h > 18) && (h <= 18 + i2[3][1])) && (w == 21))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 3, 1);
                }
            }

            else if (h == 24)
            {
                printf(" ");
            }

            // m[0][2]
            else if (((23 <= h) && (h < 36)) && ((0 < w) && (w < 6)))
            {
                if (((h >= 30 - i1[0][2]) && (h < 30)) && (w == 3))
                {
                    printf("");
                }
                else if ((h == 30) && (w == 3))
                {
                    bg_num_color(m, 0, 2);
                }
                else if (((h > 30) && (h <= 30 + i2[0][2])) && (w == 3))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 0, 2);
                }
            }

            // m[1][2]
            else if (((23 <= h) && (h < 36)) && ((6 < w) && (w < 12)))
            {
                if (((h >= 30 - i1[1][2]) && (h < 30)) && (w == 9))
                {
                    printf("");
                }
                else if ((h == 30) && (w == 9))
                {
                    bg_num_color(m, 1, 2);
                }
                else if (((h > 30) && (h <= 30 + i2[1][2])) && (w == 9))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 1, 2);
                }
            }

            // m[2][2]
            else if (((23 <= h) && (h < 36)) && ((12 < w) && (w < 18)))
            {
                if (((h >= 30 - i1[2][2]) && (h < 30)) && (w == 15))
                {
                    printf("");
                }
                else if ((h == 30) && (w == 15))
                {
                    bg_num_color(m, 2, 2);
                }
                else if (((h > 30) && (h <= 30 + i2[2][2])) && (w == 15))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 2, 2);
                }
            }

            // m[3][2]
            else if (((23 <= h) && (h < 36)) && ((18 < w) && (w < 24)))
            {
                if (((h >= 30 - i1[3][2]) && (h < 30)) && (w == 21))
                {
                    printf("");
                }
                else if ((h == 30) && (w == 21))
                {
                    bg_num_color(m, 3, 2);
                }
                else if (((h > 30) && (h <= 30 + i2[3][2])) && (w == 21))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 3, 2);
                }
            }

            else if (h == 36)
            {
                printf(" ");
            }

            // m[0][3]
            else if (((35 <= h) && (h < 48)) && ((0 < w) && (w < 6)))
            {
                if (((h >= 42 - i1[0][3]) && (h < 42)) && (w == 3))
                {
                    printf("");
                }
                else if ((h == 42) && (w == 3))
                {
                    bg_num_color(m, 0, 3);
                }
                else if (((h > 42) && (h <= 42 + i2[0][3])) && (w == 3))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 0, 3);
                }
            }

            // m[1][3]
            else if (((35 <= h) && (h < 48)) && ((6 < w) && (w < 12)))
            {
                if (((h >= 42 - i1[1][3]) && (h < 42)) && (w == 9))
                {
                    printf("");
                }
                else if ((h == 42) && (w == 9))
                {
                    bg_num_color(m, 1, 3);
                }
                else if (((h > 42) && (h <= 42 + i2[1][3])) && (w == 9))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 1, 3);
                }
            }

            // m[2][3]
            else if (((35 <= h) && (h < 48)) && ((12 < w) && (w < 18)))
            {
                if (((h >= 42 - i1[2][3]) && (h < 42)) && (w == 15))
                {
                    printf("");
                }
                else if ((h == 42) && (w == 15))
                {
                    bg_num_color(m, 2, 3);
                }
                else if (((h > 42) && (h <= 42 + i2[2][3])) && (w == 15))
                {
                    printf("");
                }

                else
                {
                    bg_color(m, 2, 3);
                }
            }

            // m[3][3]
            else if (((35 <= h) && (h < 48)) && ((18 < w) && (w < 24)))
            {
                if (((h >= 42 - i1[3][3]) && (h < 42)) && (w == 21))
                {
                    printf("");
                }
                else if ((h == 42) && (w == 21))
                {
                    bg_num_color(m, 3, 3);
                }

                else if (((h > 42) && (h <= 42 + i2[3][3])) && (w == 21))
                {
                    printf("");
                }
                else
                {
                    bg_color(m, 3, 3);
                }
            }

            else if (h == 48)
            {
                printf(" ");
            }

            else if ((w == 6) || (w == 12) || (w == 18) || (w == 24))
            {
                printf(" ");
            }
        }

        printf("\n");
    }
    printf("\n\n");
}
