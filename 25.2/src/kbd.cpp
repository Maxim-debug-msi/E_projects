#include <iostream>
#include "kbd.h"
#include "ram.h"

void write(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        std::cin >> *(arr + i);
    }
}