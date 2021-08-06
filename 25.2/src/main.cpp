#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"

int main() {
    std::string command;

    do {
        std::cout << "Enter command(sum, save, load, input, display, exit):" << std::endl;
        std::cin >> command;

        if(command == "sum")
        {
            compute(buffer);
        }
        else if(command == "save")
        {
            save(buffer);
        }
        else if(command == "load")
        {
            load(buffer);
        }
        else if(command == "input")
        {
            write(buffer);
        }
        else if(command == "display")
        {
            read(buffer);
        }
    }while(command != "exit");

    return 0;
}
