class tuple {
    public:
        tuple() {}
        tuple(double _x, double _y, double _z, double _w) :
            x(_x), y(_y), z(_z), w(_w) {}

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

class point : public tuple {
    public:
        point() {}
        point(double _x, double _y, double _z) :tuple(_x, _y, _z, 1.0) {}
};


class vector : public tuple {
    public:
        vector() {}
        vector(double _x, double _y, double _z) :tuple(_x, _y, _z, 0.0) {}
};
