#include <iostream>
#include <vector>
#include "Figure.h"

void PrintVector(vector<Figure *> FigureArr)
{
    for (auto i : FigureArr)
    {
        i->GetDetails();
    }
}

int main()
{
    vector<Figure *> FigureArr;
    Circle c(2, 2, 3);
    Triangle t(3, 4, 5);
    Square s(10);

    FigureArr.push_back(&c);
    FigureArr.push_back(&t);
    FigureArr.push_back(new Square(10));

    PrintVector(FigureArr);
    t *= 10;
    t.GetArea();
    t.GetDetails();
}
