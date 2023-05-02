#include <iostream>
#include <string>
#include <cmath>

class Shape {
public:
    Shape();
    Shape(double dHeigh, double dWidth);
    virtual ~Shape();
    virtual void scale(double scaleFactor) = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void displayProperties();

protected:
    double m_dHeight;
    double m_dWidth;
    std::string m_strType;
};

// Rectangle inherits from Shape
class Rectangle : public Shape {
public:
    Rectangle(double dHeight, double dWidth);
    virtual ~Rectangle();
    void scale(double scaleFactor);
    double area();
    double perimeter();
private:
};

// Circle inherits from Shape
class Circle : public Shape {
public:
    Circle(double dHeight, double dWidth);
    virtual ~Circle();
    void scale(double scaleFactor);
    double area();
    double perimeter();
private:
};

Shape::Shape() {
    m_dHeight = 0;
    m_dWidth = 0;
    m_strType = "Shape";
}

Shape::Shape(double dHeight, double dWidth) {
    m_dHeight = dHeight;
    m_dWidth = dWidth;
    m_strType = "Shape";
}

Shape::~Shape() {
    // Nothing to do here
}

void Shape::displayProperties() {
    std::cout << "Shape Type: " << m_strType << ", " << "Height: " << m_dHeight << ", " << "Width: " << m_dWidth << std::endl;
}

// Rectangle constructor
Rectangle::Rectangle(double dHeight, double dWidth) {
    m_dHeight = dHeight;
    m_dWidth = dWidth;
    m_strType = "Rectangle";
}

// Rectangle destructor
Rectangle::~Rectangle() {
    // Nothing to do here
}

// Rectangle scale method
void Rectangle::scale(double scaleFactor)  {
    m_dHeight *= scaleFactor;
    m_dWidth *= scaleFactor;
}

// Rectangle area method
double Rectangle::area() {
    return m_dHeight * m_dWidth;
}

// Rectangle perimeter method
double Rectangle::perimeter() {
    return 2 * m_dHeight + 2 * m_dWidth;
}

Circle::Circle(double dHeight, double dWidth) {
    m_dHeight = dHeight;
    m_dWidth = dWidth;
    m_strType = "Circle";
}

Circle::~Circle() {
}

void Circle::scale(double scaleFactor) {
    m_dHeight *= scaleFactor;
    m_dWidth *= scaleFactor;
}

double Circle::area() {
    return 0.25 * M_PI * pow(m_dHeight, 2);
}

double Circle::perimeter() {
    return M_PI * m_dHeight;
}