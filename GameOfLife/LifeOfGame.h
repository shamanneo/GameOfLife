#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 150
#define WIDTH 30

#define GENERATION 1000 

enum {DEAD, LIVE, WILLDEAD, WILLLIVE} ; 

void Begin(int p[][HEIGHT]) ; 
void Draw(int p[][HEIGHT]) ;
int GetNeighbors(int x, int y, int p[][HEIGHT]) ; 
void Next(int p[][HEIGHT]) ;
void Goto(int x, int y) ; 


