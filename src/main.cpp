#include <DatabaseController.hpp>
#include <AuthorizedUser.hpp>
#include <RootUser.hpp>

int main() {
    AuthorizedUser auth;
    RootUser root;
    std::string choice;
    std::cout << "Which account do you want to use? (root, auth): ";
    std::cin >> choice;
    if (choice=="root") {
        system("clear");
        root.runApp();
    }
    else if(choice == "auth") {
        system("clear");
        auth.runApp();
    }
    else {
        std::cout<<"User not found.";
    }
    return 0;
}