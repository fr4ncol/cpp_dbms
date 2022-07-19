#include <AuthorizedUser.hpp>
#include <DatabaseController.hpp>

void AuthorizedUser::runApp() {
    DatabaseController base;
    int chosenOperation;
	bool program = true;

	while (program == true) {
		std::cout << "---------------------------" << std::endl;
		std::cout << "Simple Database" << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "Choose operation: " << std::endl;
		std::cout << "1 - Load database from file" << std::endl;
		std::cout << "2 - Search for record" << std::endl;
		std::cout << "3 - Print all records" << std::endl;
		std::cout << "4 - Terminate program" << std::endl;
		std::cout << "" << std::endl;
		std::cin >> chosenOperation;

		switch (chosenOperation) {

		case 1: 
			base.readFromFile();
			break;
		case 2:
			base.searchRecords();
			break;
		case 3:
			base.printRecords();
			break;
		case 4:
			program = false;
			break;		
		default:
			std::cout << "Wrong operation" << std::endl;

		}
	}
}