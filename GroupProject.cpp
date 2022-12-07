#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

struct teams {
    string employeeName[4]; // we store the emoplyees names here. 
    double employeeSales[4]; // store the that employees sale here
    double totalTeamWeekSales[4]; // add the weekly sales here for all employees and save them. 
};

// prototypes
void MenuOption();
void Banner();

int main()
{
    // for my switch case
    enum{MENU = 'M', TEAM1 = 'F', TEAM2 = 'S', DISPLAY = 'D', EXIT = 'E' };

    bool loopFlag = true; // for my do while loop.
    char userChoice; // user input
    teams teamNum[2];// creating each team
    
    // call my opening of the program
    Banner();
    MenuOption();

    // do while loop
    do {
        // get user input
        cout << "Please enter your choice: ";
        cin >> userChoice;
        cout << endl;
        userChoice = toupper(userChoice); // upper case, to make life easier on end user

        // using my switch case here
        switch (userChoice) {
        case(MENU):
            MenuOption();
            break;
        case(TEAM1):

            break;
        case(TEAM2):

            break;
        case(DISPLAY):

            break;
        case(EXIT):
            cout << "Thank you." << endl;
            loopFlag = false;
            break;
        default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        } while(loopFlag == true);
    
        // showing a succeful program
    return 0;
}


void MenuOption() {
    // looping through stings for the menu options
    string options[5]{ "Show menu options press 'M'", "Load in team 1 data press 'F'",
        "Load in team 2 data press 'S'", "Display the who has the highest average press 'D'", "To exit press 'E'"};
    for (string i : options) {
        cout << i << endl;
    }
    cout << endl;
}

void Banner() {
    // setting up the size of my fille
    int starsRows(32);
    int writingStars(4);
     
    // banner
    cout << setfill('*');
    cout << setw(starsRows) << "" << endl
        << setw(writingStars) << right << " " << "Sales Comparsion Program" << setw(writingStars) << left << " " << endl
        << setw(starsRows) << "" << endl << endl;
}