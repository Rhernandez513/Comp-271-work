#include <iostream>
#include <fstream>
#include <cstring>
#include "albums.h"

using namespace std;
/*******************************************************************************
* find oldest album
* parameters:
*  albums: array of albums
*  num_of_albums: numer of albums in array
* return:
*   index of the albums that is the oldest
*This function finx the album in albums that is the oldest from your collection
*******************************************************************************/
int find_oldest_album(Album **& albums, int num_of_albums){
	int newest_index=-1;
	return newest_index;
}

int main()
{
	// Create variables for file reading
  const char * albumFile = "albums.txt", outputFile = "oldest.txt";
  std::fstream albumStream (albumFile, std::fstream::in);

	// Generate a file called oldest.txt here to write the oldest album in there
  std::fstream outputStream (outputFile, std::fstream::out);

	// Do a check to make sure the file is found say file found and start parsing
  // Else say file not found and let it exit
  std::cout << std::strcat(albumFile,
                           albumStream.is_open() ? " Open." : " Failed.");
  if(!albumStream.is_open()) {
    std:: << "\n Goodbye" << std::endl;
    return 0;
  }
  
	// Write out all the album information that you read in here
  char character;
  int lineCount = 0;
  while(albumStream.get(character)) {
    std::cout << character;
    lineCount++;
  }

  // Reset back to begining of file
  albumStream.seekg(0, albumStream.beg);

  // Convert text file into raw char arrays
  char ** unformattedIndividualAlbum = new char * [lineCount];
  for(int i = 0; i < lineCount; i++) {
    unformattedIndividualAlbum[i] = new char [256];
  }

  // Get individual albums
	for(int i = 0; i < lineCount; i++) {
    albumStream.getline(unformattedIndividualAlbum[i], 256);
  }
  
  // Now with indidual albums in AlbumData, separate albums
  
  // Individual albulms
  char *** formattedIndividualAlbum = new char ** [lineCount];
	for(int i = 0; i < lineCount; i++) {
    // Properties of each album
    **formattedIndividualAlbum = new char * [7];
    for(int j = 0; j < 8; j++) {
      // Individual characters per property
      *formattedIndividualAlbum = new char [256];
    }
  }
  
  // Convert char array to int 
  int ** numbers = new int * [3];
  int * numbers = new int[32];
  bool isNumber = true;
  for (int i = 0, k = 0; i < 8; i++) {
    int test = (int)**formattedIndividualAlbum[i];
    if(test < 48 || test > 57) {
      isNumber = false;
    }
    if(isNumber) {
      for(int j = 0; j < 32; j++) {
       *numbers[k] = ((int)*formattedIndividualAlbum[j] - 48);
      }
      k++;
  }
  // Create a test album
  Album first = new Album(**formattedIndividualAlbum[0], **formattedIndividualAlbum[1]);

  // Generate a file called oldest.txt here to write the oldest album in there
  std::fstream outputStream (outputFile, std::fstream::out);





	// Clean up your memory
	return 0;
}

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
