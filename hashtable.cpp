//============================================================================
// Name         : Hashtable Cpp
// Author       : Haad Mehboob
// Version      : 0
// Date Created : 13-12-2023
// Date Modified: 13-12-2023
//============================================================================

#include "hashtable.hpp"
#include "bst.hpp"
#include <sstream>
#include <string>

//=================================================================

HashTable::HashTable(int capacity) {
  this->size = 0;
  this->capacity = capacity;
  this->collisions = 0;
  this->buckets = new list<Entry>[capacity]; // the buckets are list in this implementation
}

//=================================================================

HashTable::~HashTable() { delete[] buckets; } // to delete the buckets array which deconstructs the hashtable

//=================================================================

void HashTable::getHeight() {
  cout << this->cityRecords.height(cityRecords.getRoot()) << endl; // get height of the tree at any time, secret method
}

//=================================================================

unsigned long HashTable::hashCode(string key) {
  // simply cyclical hash code, works fairly efficiently with a viable percentage of clashes. Easy to implement and a good balance between time spent on algorithm and the potential output generated
  unsigned long hashCode = 0;
  for (unsigned int i = 0; i < key.length(); i++) {
    hashCode = (hashCode << 5) | (hashCode >> 27);
    hashCode += (unsigned long)key[i];
  }
  return hashCode; 
}

//=================================================================
// inserting into the hashtable using the hashcode
int HashTable::insert(string key, Hotel *value) {
  cityRecords.insert(cityRecords.getRoot(), value->getCity(), value);
  unsigned long index = hashCode(key) % capacity;

  if (!buckets[index].empty()) { // if a given non empty bucket is chosen to add something to consider it a collision
    this->collisions++;
  }

  for (Entry &entry : buckets[index]) { // iterating through the bucket to check if the key is already in the bucket
    if (entry.key == key) {
      entry.value = value;
      return 1; // return 1 for repetitive, when updating a record
    }
  }
  Entry newEntry(key, value);
  buckets[index].push_back(newEntry); // create a new entry and add it to the bucket

  size++;
  return 2; // return 2 when adding a new record
}

//=================================================================

Hotel *HashTable::find(string key) {
  unsigned long index = hashCode(key) % capacity; // finding if a specific key is in the database, hash and find
  int comparisions = 0
  for (Entry &entry : buckets[index]) { // iterate over the elements of a given bucket
    comparisons++; // comparison counter
    if (entry.key == key) {
      cout << "Comparisions: " << comparisons << endl;
      return entry.value; // return wehen found
    }
  }
  cout << "This entry was not found in database." << endl;
  return nullptr; // return nullptr when not found
}

//=================================================================

void HashTable::findAll(string city, string stars) {
  if (cityRecords.find(cityRecords.getRoot(), city, stars) == nullptr) // if the search returns root, then the city is not found
    cout << "No hotels found" << endl;
}

//=================================================================

void HashTable::erase(string key) {
  if (find(key) == nullptr) {
    cout << "Record does not exist." << endl;
    return; // immediately return upon null encounter
  }
  
  unsigned long index = hashCode(key) % capacity; // hash
  
  for (auto it = buckets[index].begin(); it != buckets[index].end(); it++) { //iterator
    if (it->key == key) {
      cityRecords.remove(cityRecords.getRoot(), it->value->getCity(), it->value); // remove when found from tree
      it = buckets[index].erase(it); // then erase from bucket to remove
      size--; // size adjustment
      cout << "Record deleted." << endl;
      return;
    }
  }
  cout << "Record does not exist." << endl;
}

//=================================================================

unsigned int HashTable::getSize() { return size; }

//=================================================================

unsigned int HashTable::getCollisions() { return collisions; }

//=================================================================

void HashTable::dump(string path) {
  ofstream outfile(path);

  if (!outfile.is_open()) {
    cerr << "Error: Unable to open file for dumping: " << path << endl;
    return;
  }

  // write the mandatory format representation
  outfile << "hotelName,cityName,stars,price,countryName,address" << endl;
  int entries = 0;
  // basic iterator use to go through the array of lists, use list iterator when going buckets
  for (unsigned int i = 0; i < capacity; ++i) {
    for (const auto &entry : buckets[i]) {
      Hotel *hotel = entry.value;

      // Write the hotel information in CSV format
      outfile << hotel->getName() << "," << hotel->getCity() << ","
              << hotel->getStars() << "," << hotel->getPrice() << ","
              << hotel->getCountry() << "," << hotel->getAddress() << endl;
      entries++;
    }
  }
  cout << "Dumped " << entries << " entries to " << path << endl; 
  outfile.close();
}

//=================================================================
