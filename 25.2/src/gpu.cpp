#include <iostream>
#include "gpu.h"
#include "ram.h"

void read(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}
