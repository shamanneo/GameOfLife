#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 155
#define HEIGHT 35

#define GENERATION 500 

enum {DEAD, LIVE, WILLDEAD, WILLLIVE} ; 

void Begin(int p[][WIDTH]) ; 
void Draw(int p[][WIDTH], int generation) ;
int GetNeighbors(int x, int y, int p[][WIDTH]) ; 
void Next(int p[][WIDTH]) ;
void Goto(int x, int y) ; 


