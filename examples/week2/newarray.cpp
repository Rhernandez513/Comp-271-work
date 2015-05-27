 // Listing 15.5 - An array on the heap
 #include <iostream>
 
 class CAT
 {
 public:
     CAT() { itsAge = 1; itsWeight=5; }      // default constructor
     ~CAT();                                 // destructor
     int GetAge() const { return itsAge; }
     int GetWeight() const { return itsWeight; }
     void SetAge(int age) { itsAge = age; }
 
 private:
     int itsAge;
     int itsWeight;
 };
 
 CAT :: ~CAT()
 {
 //  std::cout << "Destructor called!\n";
 }
 
 int main()
 {
     CAT * Family = new CAT[500];
     int i;
     CAT * pCat;
     for (i = 0; i < 500; i++)
     {
         pCat = new CAT;
         pCat->SetAge(2*i +1);
         Family[i] = *pCat;
         delete pCat;
     }
 
     for (i = 0; i < 500; i++)
         std::cout << "Cat #" << i+1 << ": " 
             << Family[i].GetAge() << std::endl;
 
     delete [] Family;
 
     return 0;
 } 
