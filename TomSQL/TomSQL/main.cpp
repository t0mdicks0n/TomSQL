//
//  main.cpp
//  TomSQL
//
//  Created by Tom Dickson on 2017-10-20.
//  Copyright © 2017 Tom Dickson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include<vector>

// Create class table that takes a name as input and
// - creates a csv file
// - creates some kind of a metadata file that describes the database
class Table {
private:
  std::string name;
public:
  // TODO: Make the table structure dynamically created:
  struct tableStructure {
    int id;
    std::string firstName;
    std::string lastName;
    int age;
  } my_friends;
  Table (std::string);
  void inputColumn(std::string);
  void insertData(tableStructure data[]);
};

void writeBinary(std::string fileName, char *buffer) {
  std::ofstream openFile (fileName, std::ios::out | std::ios::binary);
  openFile.write(buffer, 100);
  openFile.close();
}

void addTableNameToStruct(std::string tableName) {
  std::ifstream currTableNames ("./Structure/table_names.bin", std::ios::in | std::ios::binary);
  char buffer[100];
  currTableNames.read(buffer, 100);
  if (!currTableNames) {
    std::cout << "An error occurd when saving a new table to the struct file with the names of all tables. \n";
  } else {
    // Take the buffered file and convert it to a vector of strings.
    // Maybe you can do reinterpret_cast backwards somehow?
    // Then when you have the vector, input the new value.
    // Then create a new buffer.
    // And lastly store this new table_names to a new binary file (over writing the old one)
  }
  
  // char* columnNames_bytes = reinterpret_cast<char*>(&tableName);
  
  
  
}

Table::Table (std::string tableName) {
  name = tableName;
  // Save the structure of the table to the persisting DB
  // structure folder
  static std::vector<std::string> columnNames;
  columnNames.push_back("id");
  columnNames.push_back("firstName");
  columnNames.push_back("lastName");
  columnNames.push_back("age");
  char* columnNames_bytes = reinterpret_cast<char*>(&columnNames);
  writeBinary("./Structure/" + tableName + "_columns.bin", columnNames_bytes);
}

void insertData(Table::tableStructure rowToInsert) {
  // Convert the struct to binary:
  
}

void initDB() {
  // Check if struct file exist
  std::ifstream infile("./Structure/table_names.bin");
  if (infile.good()) {
    std::cout << "Database exist. \n";
  } else {
    // Create table name file
    static std::vector<std::string> tableNames;
    char* tableNames_bytes = reinterpret_cast<char*>(&tableNames);
    writeBinary("./Structure/table_names.bin", tableNames_bytes);
  }
}

int main() {
  initDB();
  Table myFriends ("my_friends");
  
  // Create a row:
  
//  Table::tableStructure *oneFriend = nullptr;
//  oneFriend->id = 1;
//  oneFriend->firstName = "Franky";
//  oneFriend->lastName = "The Frenchy";
//  oneFriend->age = 6;
  
  // Insert the row to the database
  // myFriends.insertData(oneFriend);
  
  return 0;
}
