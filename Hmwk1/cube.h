class Cube {
     private:
          int length;
          int width;
          int depth;
     public:
          Cube(int l, int w, int d);     // set values of three class
                                    // variables and checks that the
                                    // values are positive integers
          int get_length();         // return length of cube
          int get_width();               // return width of cube
          int get_depth();               // return depth of cube
          int get_area();           // length x width x depth
          int get_surface_area();   // sum of area of all six sides
};
