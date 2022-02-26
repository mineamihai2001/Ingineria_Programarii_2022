#include <iostream>
#include <vector>
#include "Figure.h"

void PrintFiguresDetails(std::vector<Figure*> FigureArr)
{
    for (auto i : FigureArr)
        i->PrintDetails();
}

void PrintFiguresTotalArea(std::vector<Figure*> FigureArr)
{
    float totalArea = 0;
    for (auto i : FigureArr)
    {
        totalArea += i->GetArea();
        i->PrintArea();
    }
    std::cout << "\nTotal area of the figures is " << totalArea << '\n';
}

int main()
{
    std::vector<Figure*> FigureArray;
    Point center1(5, 5), a(0, 0), b(2, 0), c(2, 2), d(0, 2);
    Circle c1(2, 2, 3), c2(center1, 1);

    Triangle t1(a, b, c), t2(a, b, c);
    t2 *= 1.5;

    Square s1(a, b, c, d), s2(a, b *= 2, c *= 2, d *= 2);
    s2.AddPoint4(-2, 2);

    FigureArray.push_back(&c1);
    FigureArray.push_back(&c2);
    FigureArray.push_back(&t1);
    FigureArray.push_back(&t2);
    FigureArray.push_back(&s1);
    FigureArray.push_back(&s2);
        
    PrintFiguresDetails(FigureArray);
    PrintFiguresTotalArea(FigureArray);
}