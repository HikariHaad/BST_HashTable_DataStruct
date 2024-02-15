//============================================================================
// Name         : Hashtable hpp
// Author       : Haad Mehboob
// Version      : 0
// Date Created : 13-12-2023
// Date Modified: 13-12-2023
//============================================================================
#ifndef HASHTABLE_H
#define HASHTABLE_H
#pragma once 
#include<iostream>
#include<fstream>
#include<sstream>
#include<math.h>
#include<list>
#include "hotel.hpp"
#include "bst.hpp"
#include "bst.cpp"
// an entry is treated as a key value pair with the key identifying an entry and the value containing the rest of the information
using namespace std;
class Entry
{
  private:
    string key;			//hotel key
    Hotel *value;		//hotel value
  public:
    Entry(string key, Hotel *value)
    {
      this->key = key;
      this->value = value;
    }
    friend class HashTable;
};
//===============================================================
class HashTable
{
  private:
    list<Entry> *buckets;		    		 	
    BST<string,Hotel*> cityRecords;
    unsigned int size;					   		
    unsigned int capacity;				    	
    unsigned int collisions; 					
  public:
    HashTable(int capacity);		
    unsigned long hashCode(string key); // hash function cyclic
    int insert(string key, Hotel* value); // inserts a new entry into the hash table
    Hotel* find(string key); // finds an entry in the hash table
    void findAll(string city,string stars); // finds all entries corressponding to a city or stars using binary tree for efficient traversal
    void erase(string key); // erases an entry from the hash table
    unsigned int getSize(); // returns the size of the hash table
    unsigned int getCollisions(); // returns the number of collisions
    void dump(string path); // dumps the hash table to a file
    void getHeight(); // gets the height of the tree
    ~HashTable();
};
#endif