#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>
#include "LifeOfGame.h"

int main()
{
    auto arr = new int[WIDTH][HEIGHT]() ; 
    Begin(arr) ; 
    
    for(int i = 0 ; i < GENERATION ; i++)
    {
        Draw(arr, i) ; 
        Sleep(50) ; 
        Next(arr) ; 
    }
    delete[] arr ; 
    _CrtDumpMemoryLeaks() ; 
    return 0 ; 
}

