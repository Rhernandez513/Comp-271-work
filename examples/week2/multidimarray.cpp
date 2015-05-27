 // Listing 15.3 - Creating A Multidimensional Array
 #include <iostream>
 
 int main()
 {
     int SomeArray[5][2] = { {0,0}, {1,2}, {2,4}, {3,6}, {4,8}};
     for (int i = 0; i<5; i++)
         for (int j=0; j<2; j++)
         {
             std::cout << "SomeArray[" << i << "][" << j << "]: ";
             std::cout << SomeArray[i][j]<< std::endl;
         }
     return 0;
 }
