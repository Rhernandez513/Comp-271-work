#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "album.h"

int totalProperties = 7;

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
bool checkStream(std::fstream &stream)
{
  const char * message = stream.is_open() ? " Open." : " Failed.";
  std::cout << message << std::endl;
  if (!stream.is_open()) {
    std::cout << "\n Goodbye" << std::endl;
    std::system("pause");
    return false;
  } else {
    return true;
  }
}

char *** ParseAlbumFile(std::fstream &albumStream, const int lineCount)
{
  char tempChar;
  // Convert text file into raw char arrays
  char ** unformattedText = new char *[lineCount];
  for (int i = 0; i <= lineCount; i++) {
    unformattedText[i] = new char[256];
    for (int j = 0; albumStream.peek() != EOF; j++) {
      tempChar = albumStream.get();
      if (tempChar != '\n') {
        unformattedText[i][j] = tempChar;
      } else {
        unformattedText[i][j] = '\0';
        break;
      }
    }
  }

  /*=========Now with individual albums as unformatted text, organize===========*/

  // Create Individual album data containers
  char *** IndividualAlbums = new char **[lineCount];
  for (int albumMetaData = 0; albumMetaData < lineCount; albumMetaData++) {
    // Properties of each album
    IndividualAlbums[albumMetaData] = new char *[totalProperties];
    for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
      // Individual characters per property
      IndividualAlbums[albumMetaData][currentProperty] = new char[256];
    }
  }
  // Split unformatted char arrays into tokens and place into prepared container
  char * delimiterPtr;
  const char delimiters[] = { '\t' };
  for (int currentLine = 0; currentLine < lineCount; currentLine++) {
    delimiterPtr = std::strtok(unformattedText[currentLine], delimiters);
    for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
      if (delimiterPtr == nullptr) {
        break;
      } else {
        IndividualAlbums[currentLine][currentProperty] = delimiterPtr;
        delimiterPtr = std::strtok(nullptr, delimiters);
      }
    }
  }

  // Memory Cleanup  
  // Can't delete/null unformattedText[]
  // Still referenced by IndividualAlbums[][]
  delimiterPtr = nullptr;

  //// Uncomment Below to verify data is being correctly placed
  //for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
  //  char* testProp = IndividualAlbum[currentLine][currentProperty];
  //  if (*testProp == -51) {  // Check for empty propeties
  //    break;
  //  } else {
  //    // Confirm properties by printing individual properties to console
  //    std::cout << IndividualAlbum[currentLine][currentProperty] << std::endl;
  //  }
  //}

  return IndividualAlbums;
}


int main()
{
	// Create variables for file reading

  /*=========== SUBSTITUTE THIS FOR YOUR FILE PATH TO "albums.txt" ===========*/
  char * albumFile = "F:\\User\\Documents\\GitHub\\Comp-271-work\\Hmwk3\\albums.txt";
  std::fstream albumStream(albumFile, std::fstream::in);
  if (!checkStream(albumStream)) {
    return 0;
  }

	// Generate a file called oldest.txt here to write the oldest album in there
  char * outputFile = "oldest.txt";
  std::fstream outputStream (outputFile, std::fstream::out);

	// Do a check to make sure the file is found say file found and start parsing
  // Else say file not found and let it exit
  std::cout << albumFile << std::endl;
  
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

  char *** AlbumData;
  AlbumData = ParseAlbumFile(albumStream, lineCount);

  // Actually creates all the albums as objects
  const int collectionSize = lineCount;
  hw2::Album **albumCollection = new hw2::Album *[collectionSize];
  for (int i = 1; i < lineCount - 1; i++) {   // Skip the first line
    for (int j = 0; j < 2; j++) {
      albumCollection[i] = new hw2::Album();
      albumCollection[i]->set_artist(AlbumData[i][totalProperties - 7]);
      albumCollection[i]->set_title(AlbumData[i][totalProperties - 6]);
      albumCollection[i]->set_year_released(atoi(AlbumData[i][totalProperties - 5]));
      albumCollection[i]->set_num_songs(atoi(AlbumData[i][totalProperties - 4]));
      albumCollection[i]->set_record_label(AlbumData[i][totalProperties - 3]);
      albumCollection[i]->set_num_minutes_long(atoi(AlbumData[i][totalProperties - 2]));
      albumCollection[i]->set_genre(AlbumData[i][totalProperties - 1]);
    }
    std::cout << "test created album: #" << i << "\n" << std::endl;
    albumCollection[i]->write_console();
  }

  /*======================================================================== */
                          /* Works until here */
  /*======================================================================== */

  //// Create Int holders
  //int numIntProperties = 3;
  //int ** numbers = new int * [numIntProperties];
  //for (int i = 0; i <= numIntProperties; i++) { 
  //  numbers[i] = new int[32];
  //}
  
  //// Convert char array to int 
  //bool isNumber;
  //for (int i = 0, k = 0; i <= totalProperties; i++) {
  //  isNumber = true;                // Set/Reset Number checker

  //  // Check each property of an Album
  //  int test = (int)**IndividualAlbum[i];
  //  if (test < 48 || test > 57) {   // Check to see if char is a number
  //    isNumber = false;
  //    continue;
  //  }
  //  if (isNumber) {                 // Start transferring on first number found
  //    for (int j = 0; j < 10; j++) {
  //      int temp = ((int)IndividualAlbum[i][j]);
  //      if (temp == 9) {            // Check for Tab chars
  //        break;
  //      }
  //     *numbers[k] = temp;
  //    }
  //  k++;
  //  }
  //}

	// Clean up your memory
  for (int i = 1; i < lineCount; i++) {
    // Properties of each album
    delete[] *AlbumData[i];
  }
  delete[] AlbumData;
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
