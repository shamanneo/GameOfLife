#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 157
#define HEIGHT 35

#define GENERATION 400 

enum {DEAD, LIVE, WILLDEAD, WILLLIVE} ; 

void Begin(int p[][WIDTH]) ; 
void Draw(int p[][WIDTH], int generation) ;
int GetNeighbors(int x, int y, int p[][WIDTH]) ; 
void Update(int p[][WIDTH]) ;
void Goto(int x, int y) ; 


