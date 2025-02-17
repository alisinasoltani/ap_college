#include "Shapes.h"
#include "ShapeFactory.h"

int ShapeFactory::triangles = 0;
int ShapeFactory::rectangles = 0;
int ShapeFactory::circles = 0;

Triangle* ShapeFactory::buildTrinagle(float a, float b, float c) {
    ShapeFactory::triangles += 1;
    Triangle *new_triangle = new Triangle(a, b, c);
    return new_triangle;
}

Rectangle* ShapeFactory::buildRectangle(float width, float height) {
    ShapeFactory::rectangles += 1;
    Rectangle *new_rect = new Rectangle(width, height);
    return new_rect;
}

Circle* ShapeFactory::buildCircle(float raduis) {
    ShapeFactory::circles += 1;
    Circle *new_circle = new Circle(raduis);
    return new_circle;
}

int ShapeFactory::triangleCount() {
    return ShapeFactory::triangles;
}

int ShapeFactory::rectangleCount() {
    return ShapeFactory::rectangles;
}

int ShapeFactory::circleCount() {
    return ShapeFactory::circles;
}