#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 200
#define WIDTH 60

#define GENERATION 1000 

enum {DEAD, LIVE, WILLDEAD, WILLLIVE} ; 

void Begin(int p[][HEIGHT]) ; 
void Draw(int p[][HEIGHT]) ;
int GetNeighbors(int x, int y, int p[][HEIGHT]) ; 
void Next(int p[][HEIGHT]) ;

