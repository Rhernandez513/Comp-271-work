#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "album.h"


using namespace std;
using namespace hw2;
/*******************************************************************************
* find oldest album
* parameters:
*  albums: array of albums
*  num_of_albums: numer of albums in array
* return:
*   index of the albums that is the oldest
*This function finx the album in albums that is the oldest from your collection
*******************************************************************************/
//int find_oldest_album(Album **& albums, int num_of_albums){
//	int newest_index=-1;
//	return newest_index;
//}

int main()
{
	// Create variables for file reading
  //char * albumFile = "F:\\User\\Documents\\GitHub\\Comp-271-work\\Hmwk3\\albums.txt";
  char * albumFile = "C:\\Users\\rhernandez3\\Documents\\github\\Comp-271-work\\Hmwk3\\albums.txt";
  char * outputFile = "oldest.txt";
  std::fstream albumStream (albumFile, std::fstream::in);

	// Generate a file called oldest.txt here to write the oldest album in there
  std::fstream outputStream (outputFile, std::fstream::out);

	// Do a check to make sure the file is found say file found and start parsing
  // Else say file not found and let it exit
  std::cout << albumFile << std::endl;
  const char * message = albumStream.is_open() ? " Open." : " Failed.";
  std::cout << message << std::endl;
  if (!albumStream.is_open()) {
    std::cout << "\n Goodbye" << std::endl;
    std::system("pause");
    return 0;
  }
  
	// Write out all the album information that you read in here
  // Figure out how many lines (also albums) are in the file
  char character;
  int lineCount = 0;
  while(albumStream.get(character)) {
    std::cout << character;
    if (character == '\n') {
      lineCount++;
    }
  }

  // Reset back to beginning of file
  albumStream.clear();
  albumStream.seekg(0);

  // Convert text file into raw char arrays
  char ** unformattedText = new char * [lineCount];
  for (int i = 0; i <= lineCount; i++) {
    unformattedText[i] = new char [256];
    for (int j = 0; albumStream.peek() != EOF; j++) {
      character = albumStream.get();
      if (character != '\n') {
        unformattedText[i][j] = character;
      } else {
        unformattedText[i][j] = '\0';
        break;
      }
    }
  }
  
  // Now with individual albums as unformatted text, separate albums
  
  // Create Individual album data containers
  int totalProperties = 7;
  char *** IndividualAlbum = new char ** [lineCount];
	for (int albumMetaData = 0; albumMetaData < lineCount; albumMetaData++) {
    // Properties of each album
    IndividualAlbum[albumMetaData] = new char * [totalProperties];
    for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
      // Individual characters per property
      IndividualAlbum[albumMetaData][currentProperty] = new char [256];
    }
  }
  
  // Split unformatted char arrays into tokens and place into prepared container
  char * delimiterPtr;
  const char delimiters[] = { '\t' };
  for (int currentLine = 0; currentLine <= lineCount; currentLine++) {
    delimiterPtr = std::strtok(unformattedText[currentLine], delimiters);
    for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
      if(delimiterPtr == nullptr) {
        break; 
      } else {
      IndividualAlbum[currentLine][currentProperty] = delimiterPtr;
      delimiterPtr = std::strtok(nullptr, delimiters);
      }
    }
  }
    // Uncomment Below to verify data is being correctly placed
    //for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
    //  char* testProp = IndividualAlbum[currentLine][currentProperty];
    //  if (*testProp == -51) {  // Check for empty propeties
    //    break;
    //  } else {
    //    // Confirm properties by printing individual properties to console
    //    std::cout << IndividualAlbum[currentLine][currentProperty] << std::endl;
    //  }
    //}
  /*======================================================================== */
                          /* Works until here */
  /*======================================================================== */
  // Create Int holders
  int numIntProperties = 3;
  int ** numbers = new int * [numIntProperties];
  for (int i = 0; i <= numIntProperties; i++) { 
    numbers[i] = new int[32];
  }
  
  // Convert char array to int 
  bool isNumber = true;
  for (int i = 0, k = 0; i <= totalProperties; i++) {
    // Check each property of an Album
    int test = (int)**IndividualAlbum[i];
    if (test < 48 || test > 57) { // Check to see if char is a number
      isNumber = false;
      continue;
    }
    if (isNumber) { // Start transferring on first number found
      for (int j = 0; j < 32; j++) {
        int temp = ((int)IndividualAlbum[i][j]) - 48;
        if (temp == 9) { // Check for Tab chars
          break;
        }
       *numbers[k] = temp;
      }
    k++;
    }
  }
  std::system("pause");
  // Create a test album
  Album* first = new Album(**&IndividualAlbum[0], **&IndividualAlbum[1]);





	// Clean up your memory
	return 0;
}
//Album** CollectionCreator ()
//{
//  Album ** albumCollection = new Album * [collectionSize];
//  char ** artist = new char * [collectionSize];
//  for (int i = 0; i < collectionSize; i++) {
//    artist[i] = new char [256];
//  }
//
//  // Album titles
//  char * inTitles[256] = { "Solace", "Aspect", "Contact" } ;
//
//  // Create Matching array of artist (same artist for all 3 albums)
//  char * inArtists = { "Monstercat" } ;
//  for (int i = 0; i < collectionSize; i++) {
//    artist[i] = &inArtists[0];
//  }
//  for (int i = 0; i < collectionSize; i++) {
//    albumCollection[i] = new Album(*&artist[i], *&inTitles[i]);
//  }
//
//  // De-refernce pointers to allow for deletion later
//
//  artist = nullptr;
//  RETURN albumCollection;
//}
