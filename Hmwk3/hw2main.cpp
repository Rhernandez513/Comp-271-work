#include <iostream>
#include <cstring>
#include "ALBUM.h"
using namespace hw2;
Album ** CollectionCreator ();
  const int collectionSize = 3;

  void main () 
  {
    // Create holders for printing variable
    char ** outTitle = new char * [collectionSize];
    char ** outArtist = new char * [collectionSize];
    *outTitle = new char [256];
    *outArtist = new char [256];

    // Instantiate my music collection
    Album ** myCollection = CollectionCreator();

    // Simple loop to print contents of the albumCollection
    for(int i = 0; i < collectionSize; i++) {
      if ((myCollection[i]->get_title(outTitle[i]))){
        std::cout << "Album Title #" << i + 1 << " " << outTitle[i] << std::endl;
      }
      if (myCollection[i]->get_artist(outArtist[i])){
        std::cout << "By: " << outArtist[i] << "\n" << std::endl;
      }
    }

    // Memory Cleanup
    delete [] outTitle;
    delete [] outArtist;
    for (int i = 0; i < collectionSize; i++) {
      delete *&myCollection[i];
    }
    delete [] myCollection;
    std::cout << "Horray!" << std::endl;
    std::system("pause");
  }

  // Creates collection of albums, allows the main
  // to stand alone without hard coded variables
  Album** CollectionCreator ()
  {
    Album ** albumCollection = new Album * [collectionSize];
    char ** artist = new char * [collectionSize];
    for(int i = 0; i < collectionSize; i++) {
      artist[i] = new char [256];
    }

    // Album titles
    char * inTitles[256] = { "Solace", "Aspect", "Contact" } ;

    // Create Matching array of artist (same artist for all 3 albums)
    char * inArtists = { "Monstercat" } ;
    for (int i = 0; i < collectionSize; i++) {
      artist[i] = &inArtists[0];
    }
    for (int i = 0; i < collectionSize; i++) {
      albumCollection[i] = new Album(*&artist[i], *&inTitles[i]);
    }

    // De-refernce pointers to allow for deletion later

    artist = nullptr;
    return albumCollection;
  }
