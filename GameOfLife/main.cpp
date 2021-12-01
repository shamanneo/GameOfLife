#include <cstdlib>
#include <crtdbg.h>
#include "LifeOfGame.h"

int main()
{
    auto arr = new int[HEIGHT][WIDTH]() ; 
    Begin(arr) ; 
    Draw(arr, 0) ; 

    for(int i = 0 ; i <= GENERATION ; i++)
    {
        Draw(arr, i) ; 
        Sleep(10) ; 
        Update(arr) ; 
    }
    
    delete[] arr ; 
    _CrtDumpMemoryLeaks() ; 
    return 0 ; 
}

