#include <iostream>
#include "ShapeFactory.h"
#include "Shapes.h"

using namespace std;

int main() {
    Triangle *triangle1 = ShapeFactory::buildTrinagle(1,2,3);
    if (triangle1->is_valid()) {
        cout << "triangle1 is valid" << endl;
    } else {
        cout << "triangle1 is not valid" << endl;
    }
    Triangle *triangle2 = ShapeFactory::buildTrinagle(1,1,0);
    if (triangle2->is_valid()) {
        cout << "triangle2 is valid" << endl;
    } else {
        cout << "triangle2 is not valid" << endl;
    }

    Rectangle *rect1 = ShapeFactory::buildRectangle(2, 2);
    cout << "rect1 perimeter: " << rect1->perimeter() << endl;
    cout << "rect1 space: " << rect1->space() << endl;
    Rectangle *rect2 = ShapeFactory::buildRectangle(4, 2);
    cout << "rect2 perimeter: " << rect2->perimeter() << endl;
    cout << "rect2 space: " << rect2->space() << endl;
    Rectangle *rect3 = ShapeFactory::buildRectangle(2, 4);
    cout << "rect3 perimeter: " << rect3->perimeter() << endl;
    cout << "rect3 space: " << rect3->space() << endl;
    rect3->setWidth(7);
    rect3->setHeight(3);
    cout << "updated rect3 perimeter: " << rect3->perimeter() << endl;
    cout << "updated rect3 space: " << rect3->space() << endl;

    Circle *circle = ShapeFactory::buildCircle();
    cout << "circle perimeter: " << circle->perimeter() << endl;
    cout << "circle space: " << circle->space() << endl;

    cout << "All Triangles Count: " << ShapeFactory::triangleCount() << endl;
    cout << "All Rectangles Count: " << ShapeFactory::rectangleCount() << endl;
    cout << "All Circles Count: " << ShapeFactory::circleCount() << endl;
    return 0;
}