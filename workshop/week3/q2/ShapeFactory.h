#include "Shapes.h"

#ifndef __FACTORY__
    #define __FACTORY__
    class ShapeFactory {
        private:
            ShapeFactory();
            ShapeFactory(const ShapeFactory&);
            static int triangles;
            static int rectangles;
            static int circles;
        
        public:
            static Triangle* buildTrinagle(float a, float b, float c);
            static Rectangle* buildRectangle(float width = 10, float height = 5);
            static Circle* buildCircle(float raduis = 5);
            static int triangleCount();   
            static int rectangleCount();   
            static int circleCount();
    };
#endif