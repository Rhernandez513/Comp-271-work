#include <iostream>
#include <cstring>
#include "hw2.h"

using namespace std;

Album* CollectionCreator ();
const int collectionSize = 3;

void main () 
{
  // Create holders for printing variable
  char ** outTitle;
  char ** outArtist;
  char * outTitle = new char [collectionSize];
  char * outArtist = new char [collectionSize];
  
  // Instantiate my music collection
  Album* myCollection = CollectionCreator();

  // Simple loop to print contents of the albumCollection
  for(int i = 0; i < collectionSize; i++) {
    if ((myCollection[i].get_title(outTitle[i]))){
      cout << "Album Title #" << i << outTitle[i] << endl;
    }
    if (myCollection[i].get_artist(outArtist[i])){
      cout << "By: " << outArtist[i] << "\n" << endl;
    }
  }
  
  // Memory Cleanup
  delete [] outTitle;
  delete [] outArtist;
  for (int i = 0; i < collectionSize; i++) {
   delete &myCollection[i];
  }
  delete [] myCollection;
}

// Creates collection of albums, allows the main
// to stand alone without hard coded variables
Album* CollectionCreator ()
{
  Album ** albumCollection;
  char ** artist;
  char * inArtists = { "Monstercat" } ;
  char * inTitles[256] = { "Solace", "Aspect", "Contact" } ;
  char * artist = new char [collectionSize] ;
  for (int i = 0; i < collectionSize; i++) {
    artist[i] = &inArtists[0];
  }
  for (int i = 0; i < collectionSize; i++) {
    albumCollection[i] = new Album(*&inTitles[i], *&artist[i]);
  }
  delete [] inTitles;
  delete [] inArtists;
  return * albumCollection;
}
