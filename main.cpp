//============================================================================
// Name         : Hotel Finder
// Author       : Haad Mehboob
// Version      : 0
// Date Created : 13-12-2023
// Date Modified: 13-12-2023
// Description  : This program inserts a database using a csv file of a specific format.
//                The program then allows the user to search for a hotel based on the   criteria they input. The implementation uses a simply hash code and binary search tree for efficient search
//                Based on legal file input assumption as per assignment guidelines.
//============================================================================

#include "hashtable.hpp" // include main hashtable header file
#include <cstdio> // include cstdio for file handling
#include <cstring> // include cstring for string handling
#include <exception> // include exception for error handling
#include <fstream> // include fstream for file handling
#include <iostream> // include iostream for input and output
#include <list> // include list for list handling
#include <math.h> // include math.h for mathematical operations
#include <sstream> // include sstream for string handling
#include <string>

using namespace std;

// Function to convert a string to relevant Hotel format using string functions
Hotel *stringtoHotel(string details) {
  try {
    string name, city, country, address, stars, price;
    stringstream sstr(details);
    getline(sstr, name, ',');
    getline(sstr, city, ',');
    getline(sstr, stars, ',');
    getline(sstr, price, ',');
    getline(sstr, country, ',');
    getline(sstr, address);

    Hotel *hotel = new Hotel(name, city, stars, price, country, address);
    return hotel;
  } catch (exception &ex) {
    cout << "Invalid Hotel details. Please use the following format" << endl;
    cout << "hotelName,cityName,stars,price,countryName,address" << endl;
    return nullptr;
  }
}
//=========================================================
void listCommands() {
  cout << "--------------------------------------------------------------------"
          "-----------------------------------"
       << endl;
  cout << "List of Commands:" << endl;
  cout << "insert <Hotel Details>          :Add a new record to the Database "
          "using the formart "
          "<HotelName,CityName,Stars,Price,CountryName,Address>"
       << endl;
  cout << "find <HotelName,CityName>       :Find a specific hotel in the given "
          "City."
       << endl;
  cout << "findAll <CityName>              :Find all hotels of the given City."
       << endl;
  cout << "findAll <CityName,Stars>        :Find all hotels of the given City "
          "which have the stars given as argument."
       << endl;
  cout << "delete <HotelName,CityName>     :Delete a specific record." << endl;
  cout << "dump <file>                     :Dump the content of the entire "
          "structure(s) into the given file."
       << endl;
  cout << "exit                            :Quit the program." << endl;
  cout << "--------------------------------------------------------------------"
          "-----------------------------------"
       << endl;
}
//======================================================
int main(int argc, char **args) {
  HashTable myHashTable(125003); // create a new hash table with a size of 125003

  if (argc == 3 and strcmp(args[1], "-f") == 0) {
    ifstream fin;
    fin.open(args[2]);
    if (!fin) {
      cout << "Can not open the file!" << endl;
      exit(-1); // exit the program
    }

    string line;
    getline(fin, line); // skip first line
    while (!fin.eof()) { // read the file line by line
      getline(fin, line);
      if (line == "") // skip empty lines
        continue;
      Hotel *hotel = stringtoHotel(line);
      myHashTable.insert(hotel->getName() + "," + hotel->getCity(), hotel); // insert the hotel into the hash table
    }
    fin.close();
  }
  cout << "--------------------------------------------------------------------"
          "-----------------------------------"
       << endl;
  cout << "Hash Table size = " << myHashTable.getSize() << endl;
  cout << "Total number of collisions = " << myHashTable.getCollisions()
       << endl;
  cout << "% of collisions = "
       << float(myHashTable.getCollisions()) / myHashTable.getSize() * 100
       << endl; // calculate the percentage of collisions

  listCommands();
  while (true) {
    string user_input, command, argument1, argument2;
    cout << ">";
    getline(cin, user_input);

    stringstream sstr(user_input);
    getline(sstr, command, ' ');
    getline(sstr, argument1, ',');
    getline(sstr, argument2);

    // cout<<argument1<<endl<<argument2<<endl;

    if (command == "find") {
      Hotel *result = myHashTable.find(argument1 + "," + argument2); // search for the hotel in the hash table
      if (result != nullptr) // cout<<result->toString()<<endl;
        result->print();
      fflush(stdin);
      cin.clear();
    } else if (command == "height") {
      myHashTable.getHeight(); // print the height of the tree
    } else if (command == "findAll") {
      myHashTable.findAll(argument1, argument2);
      fflush(stdin); // clear the input buffer
      cin.clear();
    } else if (command == "insert") {
      Hotel *hotel = stringtoHotel(argument1 + "," + argument2); // convert the string to a hotel object
      int checker = -1;
      if (hotel != nullptr) // if the input is in correct format
        checker = myHashTable.insert(hotel->getName() + "," + hotel->getCity(), hotel);
      if (checker == 1)
        cout << "Necessary changes have been made to records." << endl;
      else if (checker == 2)
        cout << "New entry made into database." << endl;
    } else if (command == "delete")
      myHashTable.erase(argument1 + "," + argument2);
    else if (command == "help")
      listCommands();
    else if (command == "dump")
      myHashTable.dump(argument1); // dump the hash table into the file
    else if (command == "exit")
      break;
    else
      cout << "Invalid command !!!" << endl;
  }
  return 0;
}