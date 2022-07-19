#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>


struct studentData {
    std::string name;
    std::string lastName;
    std::string index;
    std::string dateOfBirth;
};


class DatabaseController {

private:

    std::vector<studentData>database;

public:
    DatabaseController();

    void addRecord(int numberOfRecords);

    void printRecords() const;

    void removeRecord();

    void modifyRecord();

    void searchRecords() const;

    void saveToFile();

    void readFromFile();

    
};