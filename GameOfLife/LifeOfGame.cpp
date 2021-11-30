#include "LifeOfGame.h"

void Begin(int p[][HEIGHT])
{
    srand((unsigned int)time(NULL)) ; 
    for(int x = 1 ; x < WIDTH - 1 ; x++)
    {
        for(int y = 1 ; y < HEIGHT - 1 ; y++)
        {
            int life = rand() % 2 ;
            p[x][y] = life ; 
        }
    }
}

void Draw(int p[][HEIGHT], int generation)
{
    int count = 0 ; 
    Goto(0, 0) ; 
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE) ; 
    srand((unsigned int)time(NULL)) ; 
    for(int x = 1 ; x < WIDTH - 1 ; x++)
    {
        for(int y = 1 ; y < HEIGHT - 1 ; y++)
        {
            if((p[x][y] == DEAD) || (p[x][y] == WILLDEAD))
            {
                p[x][y] = DEAD ; 
                printf(" ") ; 
            }
            else if((p[x][y] == LIVE) || (p[x][y] == WILLLIVE))
            {
                count++ ; 
                p[x][y] = LIVE ;
                SetConsoleTextAttribute(handle, rand() % 16) ;
                printf("*") ; 
            }
        }
        printf("\n") ; 
    }
    Goto(0, WIDTH + 1) ; 
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED) ;
    printf("\rCount : %d  Generation : %d     ", count, generation) ; 
}

int GetNeighbors(int x, int y, int p[][HEIGHT])
{
    int count = 0 ; 

    if((p[x - 1][y - 1] == LIVE) || (p[x - 1][y - 1] == WILLDEAD)) // Up, Left.
    {
        count++ ; 
    }
    if((p[x][y - 1] == LIVE) || (p[x][y - 1] == WILLDEAD)) // Up.
    {
        count++ ; 
    }
    if((p[x + 1][y - 1] == LIVE) || (p[x + 1][y - 1] == WILLDEAD)) // Up, Right.
    {
        count++ ; 
    }
    if((p[x - 1][y] == LIVE) || (p[x - 1][y] == WILLDEAD)) // Left.
    {
        count++ ; 
    }
    if((p[x + 1][y] == LIVE) || (p[x + 1][y] == WILLDEAD)) // Right.
    {
        count++ ; 
    }
    if((p[x - 1][y + 1] == LIVE) || (p[x - 1][y + 1] == WILLDEAD)) // Down, Left.
    {
        count++ ; 
    }
    if((p[x][y + 1] == LIVE) || (p[x][y + 1] == WILLDEAD)) // Down.
    {
        count++ ; 
    }
    if((p[x + 1][y + 1] == LIVE) || (p[x + 1][y + 1] == WILLDEAD)) // Down, Right.
    {
        count++ ; 
    }
    return count ;
}

void Next(int p[][HEIGHT]) 
{
    int neighbor_count = 0 ; 
    for(int x = 1 ; x < WIDTH - 1 ; x++)
    {
        for(int y = 1 ; y < HEIGHT - 1 ; y++)
        {
            neighbor_count = GetNeighbors(x, y, p) ; 
            if(p[x][y] == DEAD)
            {
                if(neighbor_count == 3)
                {
                    p[x][y] = WILLLIVE ;
                }
                else
                {
                    p[x][y] = DEAD ; 
                }
            }
            else if(p[x][y] == LIVE)
            {
                if((neighbor_count == 2) || (neighbor_count == 3))
                {
                    p[x][y] = LIVE ;
                }
                else 
                {
                    p[x][y] = WILLDEAD ; 
                }
            }
        }
    }
}

void Goto(int x, int y)
{
    const COORD pos = {(SHORT)x, (SHORT)y} ; 
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE) ; 
    SetConsoleCursorPosition(handle, pos) ;
}

