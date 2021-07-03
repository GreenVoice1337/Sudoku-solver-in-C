#include <stdio.h>

#define GRID_SIZE 9

int a = 0, b = 0;

int findEmpty();
int doesFit(int test, int row, int column);
int solve();
void printTable();

char grid[GRID_SIZE][GRID_SIZE] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 8, 0, 0, 2, 0, 0},
    {6, 1, 0, 0, 0, 4, 5, 0, 0},
    {4, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 6, 8, 1, 2, 5, 0, 0, 3},
    {0, 0, 0, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 4},
    {0, 0, 3, 0, 0, 0, 0, 5, 0},
    {0, 0, 0, 0, 7, 6, 8, 0, 0}
};

void main()
{
    printf("[ Unsolved table ]\n");
    printTable();

    solve();
    printf("\n[ Solved table ]\n");
    printTable();
    return;
}

int findEmpty()
{
    a = 0; b = 0;
    for(; a < GRID_SIZE; ++a)
    {
        for(; b < GRID_SIZE; ++b)
        {
            if(grid[a][b] == 0)
                return 1;
        }
        b = 0;
    }

    return 0;
}

int doesFit(int test, int row, int column)
{
    for(int x = 0; x < GRID_SIZE; ++x)
    {
        if(x == row)
            continue;

        if(grid[x][column] == test)
            return 0;
    }

    for(int y = 0; y < GRID_SIZE; ++y)
    {
        if(y == column)
            continue;

        if(grid[row][y] == test)
            return 0;
    }

    int x = row;
    int y = column;

    if (x >= 0 && x < 3 )x = 0; else
    if (x >= 3 && x < 6 )x = 3; else
    if (x >= 6 )x = 6;

    if (y >= 0 && y < 3 )y = 0; else
    if (y >= 3 && y <6 )y = 3; else
    if (y >= 6 )y = 6;

    for(int i = x; i < x+3; i++) {
        for(int j = y; j < y+3; j++) {
            if(i == row && j == column)
                continue;
            if(grid[i][j] == test) {
                return 0;
                break;
            }
        }
    }

    return 1;
}

int solve()
{
    int row, column;
    if(findEmpty())
    {
        row = a; column = b;
        for(int i = 1; i < 10; ++i)
        {
            if(doesFit(i, row, column))
            {
                grid[row][column] = i;
                if(solve())
                    return 1;
                grid[row][column] = 0;
            }
        }
        return 0;
    } else return 1;
}

void printTable()
{
    for(int i = 0; i < GRID_SIZE; ++i)
    {
        for(int y = 0; y < GRID_SIZE; ++y)
            printf("%d ", grid[i][y]);

        putchar('\n');
    }
}
