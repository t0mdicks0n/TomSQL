//
//  main.cpp
//  TomSQL
//
//  Created by Tom Dickson on 2017-10-20.
//  Copyright © 2017 Tom Dickson. All rights reserved.
//

#include <iostream>
#include <fstream>

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

Table::Table (std::string tableName) {
  name = tableName;
  // Save the structure of the table to the persisting DB
  // structure folder
  
  // std::ofstream dbStructFile ("./Structure/db_structure.bin", std::ios::out | std::ios::binary);
  
}

void insertData(Table::tableStructure rowToInsert) {
  
  // Convert the struct to binary:
  char* row_bytes = reinterpret_cast<char*>(&rowToInsert);
  // Write the binary to disk
  std::ofstream myFile ("./data/testData.binary", std::ios::out | std::ios::binary);
  myFile.write(row_bytes, 100);
}

void writeBinary(std::string fileName, char *buffer) {
  std::ofstream openFile (fileName, std::ios::out | std::ios::binary);
  openFile.write(buffer, 100);
  openFile.close();
}

void initDB() {
  // Check if struct file exist
  std::ifstream infile("./Structure/db_structure.bin");
  if (infile.good()) {
    
  } else {
    // Create table name file
    std::string tableNames[200];
    char* tableNames_bytes = reinterpret_cast<char*>(&tableNames);
    writeBinary("./Structure/table_names.bin", tableNames_bytes);
    //
  }
}

int main() {
  initDB();
  Table myFriends ("my_friends");
  // Create a row:
  Table::tableStructure *oneFriend = nullptr;
  oneFriend->id = 1;
  oneFriend->firstName = "Franky";
  oneFriend->lastName = "The Frenchy";
  oneFriend->age = 6;
  // Insert the row to the database
  // myFriends.insertData(oneFriend);
  
  return 0;
}

