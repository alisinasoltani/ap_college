#ifndef __SHAPES__
    #define __SHAPES__
    class Triangle {
        private:
            const float a;
            const float b;
            const float c;
        
        public:
            Triangle(float a, float b, float c): a(a), b(b), c(c) {}
            float perimeter() const;
            bool is_valid() const;
    };

    class Rectangle {
        private:
            float width;
            float height;

        public:
            Rectangle(float width, float height) {
                if (height > width) {
                    this->height = width;
                    this->width = height;
                } else {
                    this->height = height;
                    this->width = width;
                }
            }
            float space() const;
            float perimeter() const;
            float getWidth() const;
            float getHeight() const;
            bool setWidth(float width);
            bool setHeight(float height);
    };

    class Circle {
        private:
            const float radius;

        public:
            const double PI = 3.14159265359;
            Circle(float radius): radius(radius) {}
            double space() const;
            double perimeter() const;
    };
#endif