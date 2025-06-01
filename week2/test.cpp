#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    int x, y; 
public:
    Shape() : x(0), y(0) {}
    virtual ~Shape() {}

    virtual int getShape() const = 0;
    virtual string getShapeName() const = 0;

    void setCoordinates(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }
    pair<int, int> getCoordinates() const {
        return {x, y};
    }
};
class Rectangle : public Shape {
protected:
    int length, breadth;
    string color;
public:
    Rectangle(int l = 0, int b = 0, string c = "none") : length(l), breadth(b), color(c) {}

    int getLength() const {
        return length;
    }

    int getBreadth() const {
        return breadth;
    }

    string getColor() const {
        return color;
    }

    int getArea() const {
        return length * breadth;
    }

    int getPerimeter() const {
        return 2 * (length + breadth);
    }

    bool isSquare() const {
        return length == breadth;
    }

    int getShape() const override {
        return 0; // Rectangle
    }

    string getShapeName() const override {
        return "Rectangle";
    }
};
class Square : public Rectangle {
public:
    Square(int side = 0, string c = "none") : Rectangle(side, side, c) {}

    int getShape() const override {
        return 1;
    }

    string getShapeName() const override {
        return "Square";
    }

    bool isSquare() const {
        return true;
    }
};
class Ellipse : public Shape {
protected:
    int semi_major, semi_minor;
public:
    Ellipse(int a = 0, int b = 0) : semi_major(a), semi_minor(b) {}

    int getXLength() const {
        return semi_major;
    }

    int getYLength() const {
        return semi_minor;
    }

    float getArea() const {
        return 3.14 * semi_major * semi_minor;
    }

    int getShape() const override {
        return 3; // Ellipse
    }

    string getShapeName() const override {
        return "Ellipse";
    }
};

class Circle : public Ellipse {
public:
    Circle(int r = 0) : Ellipse(r, r) {}

    int getRadii() const {
        return semi_major;
    }

    float getPerimeter() const {
        return 2 * 3.14 * semi_major;
    }

    int getShape() const override {
        return 2; // Circle
    }

    string getShapeName() const override {
        return "Circle";
    }
};

int main() {
    Shape* A;

    A = new Rectangle(5, 3, "Red");
    cout << A->getShape() << " - " << A->getShapeName() << " - Perimeter "  << dynamic_cast<Rectangle*>(A)->getPerimeter() << endl;

    A = new Square(4, "Blue");
    cout << A->getShape() << " - " << A->getShapeName() << " - Area "<< dynamic_cast<Square*>(A)->getArea() <<endl;

    A = new Circle(7);
    cout << A->getShape() << " - " << A->getShapeName() << " - Radius " << dynamic_cast<Circle*>(A)->getRadii() << endl;

    A = new Ellipse(8, 4);
    cout << A->getShape() << " - " << A->getShapeName() << " - Area "<< dynamic_cast<Ellipse*>(A)->getArea() << endl;

    delete A;

    return 0;
}
