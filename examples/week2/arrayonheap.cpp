 // Listing 15.4 - An array of pointers to objects
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
     CAT * Family[500];
     int i;
     CAT * pCat;
     for (i = 0; i < 500; i++)
     {
         pCat = new CAT;
         pCat->SetAge(2*i +1);
         Family[i] = pCat;
     }
 
     for (i = 0; i < 500; i++)
         std::cout << "Cat #" << i+1 << ": " 
             << Family[i]->GetAge() << std::endl;
 
     for (i = 0; i < 500; i++)
     {
         delete Family[i];
         Family[i] = NULL;
     }
 
     return 0;
 }
