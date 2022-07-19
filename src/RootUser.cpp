#include <RootUser.hpp>
#include <DatabaseController.hpp>

void RootUser::runApp() {
    DatabaseController base;
    int chosenOperation;
	bool program = true;

    while (program == true) {
		std::cout << "---------------------------" << std::endl;
		std::cout << "Simple Database" << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "Choose operation: " << std::endl;
		std::cout << "1 - Load database from file" << std::endl;
		std::cout << "2 - Save database to file" << std::endl;
		std::cout << "3 - Add new record" << std::endl;
		std::cout << "4 - Delete record" << std::endl;
		std::cout << "5 - Modify record" << std::endl;
		std::cout << "6 - Search for records" << std::endl;
		std::cout << "7 - Print all records" << std::endl;
		std::cout << "8 - Terminate program" << std::endl;
		std::cout << "" << std::endl;
		std::cin >> chosenOperation;

		switch (chosenOperation) {

		case 1: 
			base.readFromFile();
			break;
		case 2:
			base.saveToFile();
			break;
		case 3:
            int countOfNewRecords;
            system("clear");
            std::cout<<"How many new records you want to add: ";
            std::cin >> countOfNewRecords;
			base.addRecord(countOfNewRecords);
			break;
		case 4:
			base.removeRecord();
			break;
		case 5: 
			base.modifyRecord();
			break;
		case 6:
			base.searchRecords();
			break;
		case 7:
			base.printRecords();
			break;
		case 8:
			program = false;
			break;
		default:
			std::cout << "Wrong operation" << std::endl;

		}
	}
}