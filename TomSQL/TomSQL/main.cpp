//
//  main.cpp
//  TomSQL
//
//  Created by Tom Dickson on 2017-10-20.
//  Copyright © 2017 Tom Dickson. All rights reserved.
//

#include <iostream>
#include <fstream>

// The CSV data class
class CSV {
  std::string fileName;
public:
  CSV (std::string);
};

CSV::CSV (std::string tableName) {
  fileName = "./data/" + tableName + ".csv";
  //fileName = tableName + ".csv";
  std::ofstream dataFile;
  dataFile.open(fileName);
  dataFile << "Testing";
  dataFile.close();
}

// The metadata class


// Create class table that takes a name as input and
// - creates a csv file
// - creates some kind of a metadata file that describes the database
class Table {
  std::string name;
  std::string columnNames[20];
  int arrayCount = 0;
public:
  Table (std::string);
  void inputColumn(std::string);
};

Table::Table (std::string tableName) {
  name = tableName;
  CSV createdTable (tableName);
}

void Table::inputColumn (std::string columnName) {
  if (arrayCount == 20) {
    columnNames[20] = columnName;
  } else {
    columnNames[arrayCount++] = columnName;
  }
}

int main() {
  Table myFriends ("my_friends");
  myFriends.inputColumn("firstname");
  myFriends.inputColumn("lastname");
  std::cout << "Hello, World!\n";
  return 0;
}

