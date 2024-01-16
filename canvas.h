#include <cstdlib>

class color {
    public:
        color () {}
        color(double r, double g, double b) : red(r), green(g), blue(b) {}
        color(const color &c) : red(c.red), green(c.green), blue(c.blue) {}

        double red;
        double green;
        double blue;
};

inline color operator+(const color &c1, const color &c2) {
    color res; 
    res.red = c1.red + c2.red;
    res.green = c1.green + c2.green;
    res.blue = c1.blue + c2.blue;
    return res;
}

inline color operator-(const color &c1, const color &c2) {
    color res; 
    res.red = c1.red - c2.red;
    res.green = c1.green - c2.green;
    res.blue = c1.blue - c2.blue;
    return res;
}

inline color operator*(const color &c1, const color &c2) {
    color res; 
    res.red = c1.red * c2.red;
    res.green = c1.green * c2.green;
    res.blue = c1.blue * c2.blue; 
    return res;
}

inline color operator*(const color &c, double s) {
    color res; 
    res.red = c.red * s;
    res.green = c.green * s;
    res.blue = c.blue * s;
    return res;
}

inline color operator*(double s, const color &c) {
    return c * s;
}

inline bool operator==(const color &c1, const color &c2) {
    return (fabs(c1.red - c2.red) < EPS) && 
           (fabs(c1.green - c2.green) < EPS) &&
           (fabs(c1.blue - c2.blue) < EPS);  
}

inline bool operator!=(const color &c1, const color &c2) {
    return ! (c1 == c2); 
}
//TODO:  consider renaming parameters & member data
class canvas {
    public:
        canvas() {}
        canvas(int _r, int _c) : _rows(_r), _cols(_c) {
            pixels = (color*)malloc(sizeof(color));
            for(int i = 0; i < _rows; i++) {
                for(int j = 0; j < _cols; j++) {
                    pixels[i*_cols + j] = color(0,0,0);
                }
            }
        }
        ~canvas() { free( pixels); }
        color& pixel_at(int r, int c) {
            return pixels[r*_cols + c];
        }
        int rows() { return _rows; }
        int cols() { return _cols; }

    private:
        int _rows;
        int _cols;
        color*  pixels;
};
