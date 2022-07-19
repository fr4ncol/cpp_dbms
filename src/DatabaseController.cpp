#include <DatabaseController.hpp>

DatabaseController::DatabaseController() {

};

void DatabaseController::addRecord(int numberOfRecords) {
    for(int i=0; i<numberOfRecords; i++) {
        std::string studentName;
        std::string studentLastName;
        std::string studentIndex;
        std::string studentDateOfBirth;
        bool isTypeCorrect;

		std::cout << "\nStudent name:";
		std::cin >> studentName;
		std::cout << "\nStudent last name:";
		std::cin >> studentLastName;

        do {
            std::string regexIndex = "\\b\\d{6}\\b";
            std::regex regexp(regexIndex);
			std::smatch result;
			std::cout << "\nIndex number (6 digits): " << std::endl;
			std::cin >> studentIndex;
            std::string indexString = studentIndex;
			if (!regex_search(indexString, result, regexp)) {
				isTypeCorrect = false;
				std::cout << "Something went wrong. Try again." << std::endl;
			}
			else {
				isTypeCorrect = true;
			}
			
			
		} while (isTypeCorrect == false);

        do {
			std::string regexDate = "\\b\\d{2}[-]\\d{2}[-]\\d{4}\\b";
			std::regex regexp(regexDate);
			std::smatch result;
			std::cout << "\nDate of birth: " << std::endl;
			std::cin >> studentDateOfBirth;
			std::string dateString = studentDateOfBirth;
			if (!regex_search(dateString, result, regexp)) {
				isTypeCorrect = false;
				std::cout << "Something went wrong. Try again." << std::endl;
			}
			else {
				isTypeCorrect = true;
			}

		} while (isTypeCorrect == false);

        database.push_back({studentName, studentLastName, studentIndex, studentDateOfBirth});

    }
}


void DatabaseController::printRecords() const {
    system("clear");
    if(database.size()==0) {
        std::cout<<"Database is currently empty. Load data from file or add new records";
    }
    else {
    int indexNumbers = 1;
    for(auto i: database) {
        std::cout<<indexNumbers<< " | ";
        std::cout<<i.name<< " | ";
        std::cout<<i.lastName<< " | ";
        std::cout<<i.dateOfBirth<< " | ";
        std::cout<<i.index<< " | \n";
        indexNumbers++;
    }
    }
}


void DatabaseController::removeRecord() {
    system("clear");
    if(database.size()==0) {
        std::cout<<"Database is currently empty. Load data from file or add new records";
    }
    else {
    printRecords();
    int itemIndex;
	std::cout << "\nEnter index of record, which is going to be removed" << std::endl;
	std::cin >> itemIndex;
	itemIndex = itemIndex - 1;
    database.erase(database.begin() + itemIndex);

    }
}

void DatabaseController::searchRecords() const {
    system("clear");
	std::string searchedValue;
	std::cout << "Enter value, which is going to be searched: ";
	std::cin >> searchedValue;
	std::regex regexp(searchedValue);
	std::smatch results;
    std::string orginalValue;
	bool isFound = false;

	int column;

	std::cout << "Choose type of searched data (1-name, 2-second name, 3-date of birth, 4-student index): ";
	std::cin >> column;
    std::cout<<"\n";

	switch (column) {
	case 1:
        {
		for (std::size_t i = 0; i < database.size(); i++) {
			orginalValue = database[i].name;
			if (regex_search(orginalValue, results, regexp)) {
				std::cout << i+1 << ". " << orginalValue << std::endl;
				isFound = true;
			}
        }
        }
		break;
	case 2:
        {
		for (std::size_t i = 0; i < database.size(); i++) {
			orginalValue = database[i].lastName;
			if (regex_search(orginalValue, results, regexp)) {
				std::cout << i+1 << ". " << orginalValue << std::endl;
				isFound = true;
			}
		}
        }
		break;
	case 3:
        {   
		for (std::size_t i = 0; i < database.size(); i++) {
			orginalValue = database[i].dateOfBirth;
			if (regex_search(orginalValue, results, regexp)) {
				std::cout << i+1 << ". " << orginalValue << std::endl;
				isFound = true;
			}
		}
        }
		break;
	case 4:
        {
		for (std::size_t i = 0; i < database.size(); i++) {
			std::string orginalValue = database[i].index;
			if (regex_search(orginalValue, results, regexp)) {
				std::cout << i+1 << ". " << orginalValue << std::endl;
				isFound = true;
			}
		}
        }
		break;
	default:
		std::cout << "Wrong data category\n";

	}
	if (isFound == false) {
		std::cout << "\nThere are no matching records in database\n";
	}
}


void DatabaseController::modifyRecord() {
    system("clear");
	if (database.size() == 0) {
		std::cout << "Database is currently empty. To modify, you have to first add some records" << std::endl;
		return;
	}
	int databaseIndex;
	int databaseColumn;
	printRecords();
	std::cout << "\nIndex of record you want to modify: ";
	std::cin>>databaseIndex;
	databaseIndex = databaseIndex - 1;
	std::cout << "\nChoose column to modify (1-name, 2-second name, 3-student index, 4-date of birth):  ";
	std::cin >> databaseColumn;

    std::string studentName;
    std::string studentLastName;
    std::string studentIndex;
    std::string studentDateOfBirth;
    bool isTypeCorrect;

    switch (databaseColumn) {
	case 1: {
        std::cout << "\nNew student name:";
		std::cin >> studentName;
        database[databaseIndex].name = studentName;
    }
    break;
    case 2: {
        std::cout << "\nNew student last name:";
		std::cin >> studentLastName;
        database[databaseIndex].name = studentLastName;
    }
    break;
    case 3: {
        do {
            std::string regexIndex = "\\b\\d{6}\\b";
            std::regex regexp(regexIndex);
			std::smatch result;
			std::cout << "\nIndex number (6 digits): " << std::endl;
			std::cin >> studentIndex;
            std::string indexString = studentIndex;
			if (!regex_search(indexString, result, regexp)) {
				isTypeCorrect = false;
				std::cout << "Something went wrong. Try again." << std::endl;
			}
			else {
				isTypeCorrect = true;
                database[databaseIndex].index = studentIndex;
			}
			
			
		} while (isTypeCorrect == false);

    }
    break;
    case 4: {
        do {
			std::string regexDate = "\\b\\d{2}[-]\\d{2}[-]\\d{4}\\b";
			std::regex regexp(regexDate);
			std::smatch result;
			std::cout << "\nDate of birth: " << std::endl;
			std::cin >> studentDateOfBirth;
			std::string dateString = studentDateOfBirth;
			if (!regex_search(dateString, result, regexp)) {
				isTypeCorrect = false;
				std::cout << "Something went wrong. Try again." << std::endl;
			}
			else {
				isTypeCorrect = true;
                database[databaseIndex].dateOfBirth = studentDateOfBirth;
			}

		} while (isTypeCorrect == false);
    }
    break;
		

	default:
		std::cout << "Wrong column." << std::endl;

	}
}

void DatabaseController::saveToFile() {
    std::string fileName;
	system("clear");
	std::cout << "Enter name of a file: ";
	std::cin >> fileName;
	fileName = "../data/"+fileName + ".txt";
	std::cout<<"\n";
	std::cout << "Database saved." << std::endl;

	std::ofstream file;

	file.open(fileName, std::ios::out | std::ios::trunc);
	if (file.good() == true)
	{	
		for (auto i: database)
		{
			file << i.name << ";" << i.lastName << ";" << i.index << ";" << i.dateOfBirth << std::endl;

		}
		file.close();
	}
}

void DatabaseController::readFromFile() {
    system("clear");
	std::string line;
	std::fstream file;
	std::string fileName;
	std::cout << "Enter name of a file: ";
	std::cin >> fileName;
	fileName = "../data/"+fileName + ".txt";

	file.open(fileName, std::ios::in);
	if (file.good() == true)
	{
		while (!file.eof())
		{	
            std::getline(file,line);
			std::stringstream test(line);
			std::string segment;
			std::vector<std::string> segmentList;
			if (line == "") {
				break;
			}

			while (getline(test, segment, ';'))
			{
				segmentList.push_back(segment);
				
			}

			//konwersje

			database.push_back({segmentList[0],segmentList[1],segmentList[2],segmentList[3]});
		    std::cout << "\nDatabase loading completed!" << std::endl;
        
	}
 }
}
