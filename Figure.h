#include <iostream>
#include <math.h>
#define PI 3.1415
using namespace std;

class Figure
{
public:
    virtual void GetArea() = 0;
    virtual void GetDetails() = 0;
};

class Circle : public Figure
{
private:
    int x, y, radius;

public:
    Circle()
    {
        this->x = 0;
        this->y = 0;
        this->radius = 0;
    }
    Circle(int new_x, int new_y, int new_radius) : x(new_x), y(new_y), radius(new_radius) {}
    Circle(const Circle &circle2)
    {
        this->x = circle2.x;
        this->y = circle2.y;
        this->radius = circle2.radius;
    }
    ~Circle()
    {
        // std::cout << "Destructor called";
    }
    void GetArea()
    {
        std::cout << "The area of the circle is: " << PI * this->radius * this->radius << endl;
    }
    void GetDetails()
    {
        std::cout << "Circle info: " << this->x << " " << this->y << " " << this->radius << endl;
    }
    Circle operator*=(int scale)
    {
        this->radius *= scale;
        return *this;
    }
};

class Triangle : public Figure
{
private:
    int x, y, z;

public:
    Triangle()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Triangle(int new_x, int new_y, int new_z) : x(new_x), y(new_y), z(new_z) {}
    Triangle(const Triangle &triangle2)
    {
        this->x = triangle2.x;
        this->y = triangle2.y;
        this->z = triangle2.z;
    }
    ~Triangle()
    {
        // std::cout << "Destructor called";
    }
    void GetArea()
    {
        float p = (this->x + this->y + this->z) / 2;
        float area = sqrt(p * (p - this->x) * (p - this->y) * (p - this->z));
        std::cout << "The area of the triangle is: " << area << endl;
    }
    void GetDetails()
    {
        std::cout << "Triangle info: " << this->x << " " << this->y << " " << this->z << endl;
    }
    Triangle operator*=(int scale)
    {
        this->x *= scale;
        this->y *= scale;
        this->z *= scale;
        return *this;
    }
};

class Square : public Figure
{
private:
    int x;

public:
    Square()
    {
        this->x = 0;
    }
    Square(int new_x) : x(new_x) {}
    Square(const Square &square2)
    {
        this->x = square2.x;
    }
    ~Square()
    {
        // std::cout << "Destructor called";
    }
    void GetArea()
    {
        std::cout << "The area of the circle is: " << this->x * this->x << endl;
    }
    void GetDetails()
    {
        std::cout << "Square info: " << this->x << endl;
    }
    Square operator*=(int scale)
    {
        this->x *= scale;
        return *this;
    }
};