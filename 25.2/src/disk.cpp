#include <iostream>
#include "disk.h"
#include "ram.h"
#include <fstream>

void save(int arr[])
{
    std::ofstream in;
    in.open("C:/E_files/data.txt");

    if(in.is_open()) in.write((char*)arr, 8 * 4);
    else std::cout << "Error write!" << std::endl;

    in.close();
}

void load(int arr[])
{
    std::ifstream out;
    out.open("C:/E_files/data.txt");

    if(out.is_open()) out.read((char*)arr, 8 * 4);
    else std::cout << "Error read!" << std::endl;

    out.close();
}

