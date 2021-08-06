#include <iostream>
#include "my-lib.h"
#include "my-lib2.h"

int main() {
    std::string command;
    bool flag = false;
    bool begin = false;
    do {
        std::cout << "Enter command: " << std::endl;
        std::cin >> command;

        if(command == "scalpel")
        {
            std::cout << "Enter the coordinates of the start and end of the cut: " << std::endl;
            input();
            input();
            scalpel();
            begin = true;
        }
        else if(command == "hemostat" && begin)
        {
            input();
            hemostat();
        }
        else if(command == "tweezers" && begin)
        {
            input();
            tweezers();
        }
        else if(command == "suture" && begin)
        {
           input();
           input();
           if(!compare())
           {
               std::cout << "Incorrect input! Try again!" << std::endl;
               del();
               del();
           }
           else
           {
               suture();
               flag = true;
           }
        }
        if(!begin) std::cout << "To start the operation, make an incision!" << std::endl;
    }while(!flag);
    system("pause");
    return 0;
}
