 // Listing 15.2 - An array of objects
 #include <iostream> 
 
 class CAT
 {
 public:
     CAT() { itsAge = 1; itsWeight=5; } // default constructor
     ~CAT() {}                          // destructor
     int GetAge() const { return itsAge; }
     int GetWeight() const { return itsWeight; }
     void SetAge(int age) { itsAge = age; }

 private:
     int itsAge;
     int itsWeight;
 };

 int main()
 {
     CAT Litter[5];    // create an array of 5 objects
     int i;
     for (i = 0; i < 5; i++)
         Litter[i].SetAge(2*i +1);

     for (i = 0; i < 5; i++)
         std::cout << "Cat #" << i+1<< ": "
             << Litter[i].GetAge() << std::endl;
     return 0;
 }