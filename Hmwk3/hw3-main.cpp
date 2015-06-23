#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "album.h"


using namespace hw2;
int totalProperties = 7;

/*******************************************************************************
* find oldest album
* parameters:
*  albums: array of albums
*  num_of_albums: number of albums in array
* return:
*   index of the albums that is the oldest
*This function finds the album in albums that is the oldest from your collection
*******************************************************************************/
int find_oldest_album(hw2::Album **& albums, const int num_of_albums){
	int newest_index = 0;
  int runningMin = albums[0]->get_year_released();
  for (int i = 0; i < num_of_albums; i++) {
    int temp = albums[i]->get_year_released();
    if (temp < runningMin && temp != 0) {
      runningMin = temp;
      newest_index = i;
    }
  }
	return newest_index;
}

// Verifies that the FStream is open
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

// Creates container and parses stream for all data
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

  /*=========Now with individual albums as unformatted text, organize=========*/

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
  // Which is returned by this func
  delimiterPtr = nullptr;

  /*========Uncomment Below to verify data is being correctly placed==========*/

  //for (int currentProperty = 0; currentProperty <= totalProperties; currentProperty++) {
  //  char* testProp = IndividualAlbum[currentLine][currentProperty];
  //  if (*testProp == -51) {  // Check for empty properties
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

  // Do a check to make sure the file is found say file found and start parsing
  // Else say file not found and let it exit
  std::fstream albumStream(albumFile, std::fstream::in);
  if (!checkStream(albumStream)) {
    return 0;
  }

	// Write out all the album information that you read in here
  // Figures out how many lines (also albums) are in the file
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

  char *** AlbumData = ParseAlbumFile(albumStream, lineCount);
  albumStream.close();

  // Actually creates all the albums as objects
  const int collectionSize = lineCount;
  hw2::Album **albumCollection = new hw2::Album *[collectionSize];
  for (int i = 1, j = 0; i < lineCount; i++, j++) {   // Skip the first line
    std::cout << "\ntest created album: #" << i << "\n";
    albumCollection[j] = new hw2::Album();
    albumCollection[j]->set_artist(AlbumData[i][0]);
    albumCollection[j]->set_title(AlbumData[i][1]);
    albumCollection[j]->set_year_released((atoi(AlbumData[i][2])));
    albumCollection[j]->set_record_label(AlbumData[i][3]);
    albumCollection[j]->set_num_songs((atoi(AlbumData[i][4])));
    albumCollection[j]->set_num_minutes_long((atoi(AlbumData[i][5])));
    albumCollection[j]->set_genre(AlbumData[i][6]);
    albumCollection[j]->write_console();
    std::cout << std::endl;
  }


  // Generate a file called oldest.txt here to write the oldest album in there
    int oldestAlbum = find_oldest_album(albumCollection, lineCount - 1);
  std::cout << "\n\nOldest Album released in: ";
  std::cout << albumCollection[oldestAlbum]->get_year_released() << std::endl;
  char * outputFile = "oldest.txt";
  albumCollection[oldestAlbum]->write_file(outputFile);


	// Clean up your memory
  for (int i = 1; i < lineCount; i++) {
    // Properties of each album
    delete[] *AlbumData[i];
  }
  delete[] AlbumData;

  for (int i = 1; i < lineCount - 1; i++) {
    delete albumCollection[i];
  }
  delete[] albumCollection;
	return 1;
}
