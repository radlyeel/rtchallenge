#include <tuples.h>
#include <iostream>
#include <ostream>

class projectile {
    public:
        projectile() {}
        projectile(const point &position, const vector &velocity) :
            pos(position), vel(velocity) {} 
        projectile operator=(const projectile &p)  {
           this->pos = p.pos; 
           this->vel = p.vel; 
           return *this;
        }

        point pos;
        vector vel;
};

class environment {
    public:
        environment() {}
        environment(const vector &gravity, const vector &wind) :
            g(gravity), w(wind) {}

        vector g;
        vector w;
};

projectile  tick(const environment &env, projectile &proj) {
     point pos= proj.pos + proj.vel;
     vector vel = proj.vel + env.g + env.w;
     return projectile(pos, vel);
}
    
int main(int argc, char* argv[]) {
    point position = point(0,1,0);
    vector velocity = normalize(vector(1,1,0));
    projectile proj(position, velocity);
    environment e(vector(0, -0.1, 0), vector(-0.01, 0, 0));
    std::cout << "Trajectory:" << std::endl;
    while (proj.pos.y > 0) {
        proj = tick(e, proj);
        std::cout << "x = " << proj.pos.x 
                  << " y = " << proj.pos.y << std::endl; 
    }

    return 0;
}
