//============================================================================
// Name         : Hotel Cpp
// Author       : Haad Mehboob
// Version      : 0
// Date Created : 13-12-2023
// Date Modified: 13-12-2023
//============================================================================

#include"hotel.hpp"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

//=================================================================
// Hotel constructor
Hotel::Hotel(string name, string city, string stars, string price, string country, string address) {
  this->name = name;
  this->city = city;
  this->stars = stars;
  this->price = price;
  this->country = country;
  this->address = address;
}

// Basic getter methods
//=================================================================

string Hotel::getName() {
  return name;
}

//=================================================================

string Hotel::getCity() {
  return city;
}

//=================================================================

string Hotel::getStars() {
  return stars;
}

//=================================================================

string Hotel::getPrice() {
  return price;
}

//=================================================================

string Hotel::getCountry() {
  return country;
}

//=================================================================

string Hotel::getAddress() {
  return address;
}

//=================================================================

// converts to a particular format of string
string Hotel::toString() {
  return name + "," + city + "," + stars + "," + price + "," + country + "," + address;
}

//=================================================================

// converts to a particular format of string to show in terminal
void Hotel::print() {
  cout << "Hotel Name: " << name << endl;
  cout << "City      : " << city << endl;
  cout << "Stars     : " << stars << endl;
  cout << "Price     : " << price << " $/night" << endl;
  cout << "Country   : " << country << endl;
  cout << "Address   : " << address << endl;
}

//=================================================================
// converts to a particular format of string to show in terminal
void Hotel::print2() {
   cout<<std::left<<setw(50)<<name<<" "<<setw(10)<<city<<" "<<setw(5)<<stars<<" "<<setw(10)<<price<<" "<<setw(20)<<country<<" "<<address<<endl;
}

//=================================================================