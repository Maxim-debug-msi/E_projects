#include <iostream>
#include <vector>
#include "my-lib2.h"
#include "my-lib.h"

struct point
{
    double x;
    double y;
};

std::vector<point> points;

void input()
{
    points.push_back(point{});
    std::cin >> points[points.size() - 1].x >> points[points.size() - 1].y;
}

void output(int i = 0)
{
    std::cout << points[points.size() - 1 - i].x << ":" << points[points.size() - 1 - i].y << std::endl;
}

bool compare()
{
    if (points[0].x == points[points.size() - 2].x && points[0].y == points[points.size() - 2].y
        && points[1].x == points[points.size() - 1].x
        && points[points.size() - 1].y == points[points.size() - 1].y) {
        return true;
    }
    return false;
}

void del()
{
    points.pop_back();
}

void scalpel()
{
    std::cout << "Incision " << std::endl;
    output(1);
    output();
}

void hemostat()
{
    std::cout << "Hemostat: " << std::endl;
    output();
}

void tweezers()
{
    std::cout << "Tweezers: " << std::endl;
    output();
}

void suture()
{
    std::cout << "Suture: " << std::endl;
    output(1);
    output();
    std::cout << "Operation successes!" <<std::endl;
}
