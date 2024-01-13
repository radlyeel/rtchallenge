class tuple {
    public:
        tuple() {}
        tuple(double _x, double _y, double _z, double _w) :
            x(_x), y(_y), z(_z), w(_w) {}
        tuple(tuple &t) : x(t.x), y(t.y), z(t.z), w(t.w) {}
        inline virtual void operator=(const tuple &t)  {
            x = t.x; 
            y = t.y;
            z = t.z;
            w = t.w;
        }

        double x;
        double y;
        double z;
        double w;
};

// I/O operators
inline std::ostream& operator<<(std::ostream &out, tuple &t) {
    return out << t.x << ' ' << t.y << ' ' << t.z << ' ' << t.w;
}

// Equality operator
const double EPS = 0.00001;
inline bool operator==(const tuple &t1, const tuple &t2) {
    return (fabs(t1.w - t2.w) < EPS) && // checking w first because a point cannot
           (fabs(t1.x - t2.x) < EPS) && // ... equal a vector
           (fabs(t1.y - t2.y) < EPS) &&
           (fabs(t1.z - t2.z) < EPS);
}

inline bool operator!=(const tuple &t1, const tuple &t2) {
    return ! (t1 == t2); 
}


inline tuple operator+(const tuple &t1, const tuple &t2) {
    // Note that if the user adds two points, w = 2;  rather than encumber the code
    // with error handling at this level, we just make that the user's problem, pg. 33
    tuple res; 
    res.x = t1.x + t2.x;
    res.y = t1.y + t2.y;
    res.z = t1.z + t2.z;
    res.w = t1.w + t2.w;
    return res;
}

class point : public tuple {
    public:
        point() {}
        point(double _x, double _y, double _z) :tuple(_x, _y, _z, 1.0) {}
        // point(const point &p) : tuple(p.x, p.y, p.z, p.w) {}
        inline virtual void operator=(const tuple &t)  {
         x = t.x; 
         y = t.y; 
         z = t.z; 
         w = t.w;
        }
};


class vector : public tuple {
    public:
        vector() {}
        vector(double _x, double _y, double _z) :tuple(_x, _y, _z, 0.0) {}
};
