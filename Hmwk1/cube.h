#ifndef CUBE_H
#define CUBE_H
class Cube {
     private:
          int length;
          int width;
          int depth;
          char* cube_name;
     public:
          Cube();
          Cube(int l, int w, int d, char* name);
          Cube(int l, int w, int d);     // set values of three class
          ~Cube();                       // variables and checks that the
                                         // values are positive integers

          int get_length();              // return length of cube
          int get_width();               // return width of cube
          int get_depth();               // return depth of cube
          int get_area();                // length x width x depth
          int get_surface_area();        // sum of area of all six sides
          char* get_cube_name();
          //your mutators
          bool set_length(int l);
          bool set_width(int w);
          bool set_cube_name(char* n);
};

#endif //CUBE_H
