//============================================================================
// Name         : Hotel hpp
// Author       : Haad Mehboob
// Version      : 0
// Date Created : 13-12-2023
// Date Modified: 13-12-2023
//============================================================================
#ifndef HOTEL_H
#define HOTEL_H

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Hotel
{
  private:
    string name;	//name of the hotel	
    string city;	//city of the hotel
    string stars;	//stars of the hotel
    string price;	//price per night
    string country;	//country
    string address;	//full address of the hotel
  public:
    Hotel(string name,string city, string stars,string price,string country,string address);	//constructor
    string getName();	
    string getCity();	
    string getStars();
    string getPrice();
    string getCountry();
    string getAddress();
    string toString();
    void print();
    void print2();
};
#endif
