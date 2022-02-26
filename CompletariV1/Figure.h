#include <iostream>
#include <math.h>
#define PI 3.1415

class Figure
{
public:
    virtual void PrintArea() = 0;
    virtual void PrintDetails() = 0;
    virtual float GetArea() = 0;
};

class Point
{
private:
    float x, y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(float new_x, float new_y) : x(new_x), y(new_y) {}

    ~Point()
    {
        // std::cout << "Destructor called";
    }

    Point(const Point& point)
    {
        this->x = point.x;
        this->y = point.y;
    }

    void PrintDetails()
    {
        std::cout << "\nPoint info: \ncoordinate x = " << this->x << ", coordinate y = " << this->y << '\n';
    }

    void GetCoords()
    {
        std::cout << "coordinate x = " << this->x << " , coordinate y = " << this->y;
    }

    float GetX()
    {
        return this->x;
    }

    float GetY()
    {
        return this->y;
    }

    Point operator*=(int scale)
    {
        this->x *= scale;
        this->y *= scale;
        return *this;
    }

    void AddPoint(float valueX, float valueY)
    {
        this->x += valueX;
        this->y += valueY;
    }

    friend float GetDistance(Point a, Point b);
};

float GetDistance(Point a, Point b)
{
    //Euclidian 2D
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class Circle : public Figure
{
private:
    Point center;
    float radius;

public:
    Circle()
    {
        this->center = Point();
        this->radius = 0;
    }

    Circle(float new_x, float new_y, float new_radius) : center(Point(new_x, new_y)), radius(new_radius) {}

    Circle(Point new_center, int new_radius) : center(new_center) , radius(new_radius) {}
    
    Circle(const Circle& circle2)
    {
        this->center = circle2.center;
        this->radius = circle2.radius;
    }

    ~Circle()
    {
        // std::cout << "Destructor called";
    }

    void PrintArea()
    {
        std::cout << "\nThe area of the circle is: " << PI * this->radius * this->radius << '\n';
    }
    float GetArea()
    {
        return PI * this->radius * this->radius;
    }
    Point GetCenter()
    {
        return center;
    }
    float GetRadius()
    {
        return radius;
    }
    
    void PrintDetails()
    {
        std::cout << "\nCircle info:\nCenter has ";
        this->center.GetCoords();
        PrintArea();
    }

    Circle operator*=(float scale)
    {
        if (scale > 0)
            this->radius *= scale;
        return *this;
    }

    void ChangeCenter(Point new_center)
    {
        this->center = new_center;
    }

    void AddCenter(float valueX, float valueY)
    {
        this->center.AddPoint(valueX, valueY);
    }
};


class Triangle : public Figure
{
private:
    Point a, b, c;

public:
    Triangle()
    {
        this->a = Point();
        this->b = Point();
        this->c = Point();
    }

    Triangle(Point new_a,Point new_b,Point new_c) : a(new_a), b(new_b), c(new_c) {}
    
    Triangle(const Triangle& triangle2)
    {
        this->a = triangle2.a;
        this->b = triangle2.b;
        this->c = triangle2.c;
    }
    ~Triangle()
    {
        // std::cout << "Destructor called";
    }

    float GetArea()
    {
        //p=perrimeter/2
        float length1, length2, length3, p, area;
        length1 = GetDistance(this->a, this->b);
        length2 = GetDistance(this->a, this->c);
        length3 = GetDistance(this->b, this->c);

        p = (length1 + length2 + length3) / 2;
        return sqrt(p * (p - length1) * (p - length2) * (p - length3));
    }
    void PrintArea()
    {
        std::cout << "\nThe area of the triangle is: " << GetArea() << '\n';
    }

    void PrintDetails()
    {
        if(!CheckTriangle())
            std::cout << "\nWarning:The given points do not form a triangle!\n";
        std::cout << "\nTriangle info:\nPoint 1 has ";
        this->a.GetCoords();

        std::cout << "\nPoint 2 has ";
        this->b.GetCoords();

        std::cout << "\nPoint 3 has ";
        this->c.GetCoords();

        std::cout << "\nThe area of the triangle is " << GetArea() << '\n';
    }

    bool CheckTriangle()
    {
        return (this->GetArea() != 0);
    }
    
    Triangle operator*=(float scale)
    {
        this->a *= scale;
        this->b *= scale;
        this->c *= scale;
        return *this;
    }

    void AddPoint1(float valueX, float valueY)
    {
        this->a.AddPoint(valueX, valueY);
    }

    void AddPoint2(float valueX, float valueY)
    {
        this->b.AddPoint(valueX, valueY);
    }

    void AddPoint3(float valueX, float valueY)
    {
        this->c.AddPoint(valueX, valueY);
    }

};


class Square : public Figure
{
private:
    Point a, b, c, d;

public:
    Square()
    {
        this->a = Point();
        this->b = Point();
        this->c = Point();
        this->d = Point();
    }

    Square(Point new_a, Point new_b, Point new_c, Point new_d) : a(new_a), b(new_b), c(new_c), d(new_d) {}

    Square(const Square& square2)
    {
        this->a = square2.a;
        this->b = square2.b;
        this->c = square2.c;
        this->d = square2.d;
    }

    ~Square()
    {
        // std::cout << "Destructor called";
    }

    float GetArea()
    {
        if (CheckSquare())
        {
            float length = GetDistance(this->a, this->b);
            return length * length;
        }        
        return 0;            
    }
    void PrintArea()
    {
        std::cout << "\nThe area of the square is " << GetArea() << '\n';
    }

    void PrintDetails()
    {
        if (!CheckSquare())
            std::cout << "\nWarning:The points given do not form a square!\n";
        
        std::cout << "\nSquare info:\nPoint 1 has ";
        a.GetCoords();

        std::cout << "\nPoint 2 has ";
        b.GetCoords();

        std::cout << "\nPoint 3 has ";
        c.GetCoords();

        std::cout << "\nPoint 4 has ";
        d.GetCoords();

        std::cout << "\nThe area of the square is " << GetArea() << '\n';
    }

    bool CheckSquare()
    {
        float lengths[4];
        int i, j;
        lengths[0] = GetDistance(this->a, this->b);
        lengths[1] = GetDistance(this->b, this->c);
        lengths[2] = GetDistance(this->c, this->d);
        lengths[3] = GetDistance(this->d, this->a);
        for (i = 0; i < 3; ++i)
            for (j = i + 1; j < 4; ++j)
                if (lengths[i] != lengths[j])
                    return 0;
        return 1;
    }

    Square operator*=(float scale)
    {
        this->a *= scale;
        this->b *= scale;
        this->c *= scale;
        this->d *= scale;
        return *this;
    }

    void AddPoint1(float valueX, float valueY)
    {
        this->a.AddPoint(valueX, valueY);
    }

    void AddPoint2(float valueX, float valueY)
    {
        this->b.AddPoint(valueX, valueY);
    }

    void AddPoint3(float valueX, float valueY)
    {
        this->c.AddPoint(valueX, valueY);
    }

    void AddPoint4(float valueX, float valueY)
    {
        this->d.AddPoint(valueX, valueY);
    }    
};