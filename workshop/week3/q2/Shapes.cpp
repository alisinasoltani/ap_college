#include <iostream>
#include "math.h"
#include "Shapes.h"

using namespace std;

float Triangle::perimeter() const {
    return this->a + this->b + this->c;
}

bool Triangle::is_valid() const {
    if (this->a + this->b > this->c && this->a < this->b + this->c && this->a + this->c > this->b) {
        return true;
    } else {
        return false;
    }
}

float Rectangle::space() const {
    return this->height * this->width;
}

float Rectangle::perimeter() const {
    return 2 * (this->height + this->width);
}

float Rectangle::getWidth() const {
    return this->width;
}

float Rectangle::getHeight() const {
    return this->height;
}

bool Rectangle::setWidth(float width) {
    this->width = width;
    return true;
}

bool Rectangle::setHeight(float height) {
    this->height = height;
    return false;
}

double Circle::space() const {
    return pow(this->radius, 2) * this->PI;
}

double Circle::perimeter() const {
    return 2 * this->radius * this->PI;
}