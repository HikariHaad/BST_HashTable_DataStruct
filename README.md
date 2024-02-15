# Hotel Finder

## Overview

**Hotel Finder** is a command-line program developed by Haad Mehboob. It allows users to manage a hotel database using CSV files. The program utilizes a hash table and a binary search tree for efficient data retrieval.

- **Version:** 0
- **Date Created:** 13-12-2023
- **Date Modified:** 13-12-2023
- **Author:** Haad Mehboob

## Description

The program reads a CSV file containing hotel details and populates a database. Users can then perform various operations, such as searching for hotels based on criteria, adding new records, deleting records, and more.

## Features

- **Data Structure:** The program employs a hash table with a binary search tree to efficiently manage and search for hotel records.

- **File Input:** Hotel details are read from a CSV file following a specific format. Assumptions regarding the input file format are based on assignment guidelines.

- **Command-Line Interface:** Users interact with the program through a command-line interface. Various commands allow users to perform different operations on the database.

## Usage

1. **Insert a Record:** Add a new record to the database using the `insert` command and providing hotel details in the format `<HotelName,CityName,Stars,Price,CountryName,Address>`.

2. **Find a Hotel:** Search for a specific hotel in a given city using the `find` command and specifying the hotel name and city.

3. **Find All Hotels:** Retrieve a list of all hotels in a given city using the `findAll` command with the city name. Optionally, specify stars as well.

4. **Delete a Record:** Delete a specific record using the `delete` command and providing the hotel name and city.

5. **Dump Data:** Dump the content of the entire data structure into a specified file using the `dump` command.

6. **Exit Program:** Quit the program using the `exit` command.

## Dependencies

- The program includes a header file "hashtable.hpp" for the main hashtable implementation.

## Getting Started

1. **Compile the Code:** Use a C++ compiler to compile the provided code.

2. **Run the Executable:** Execute the compiled program, providing a CSV file as input using the `-f` option.

3. **Interact with the Program:** Follow the on-screen instructions to interact with the hotel database.

## Note

- The program makes assumptions about the format of the CSV file based on assignment guidelines.

- For assistance, use the `help` command to display a list of available commands.

Enjoy using the Hotel Finder!
