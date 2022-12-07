#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

struct teams {
    int week[4];
};

void MenuOption();
void Banner();

int main()
{
    enum{MENU = 'M', TEAM1 = 'F', TEAM2 = 'S', DISPLAY = 'D', EXIT = 'E' };
    bool loopFlag = true;
    char userChoice;
    teams teamNum[2];

    Banner();
    MenuOption();
    do {
        cout << "Please enter your choice: ";
        cin >> userChoice;
        cout << endl;
        userChoice = toupper(userChoice);

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
    
    return 0;
}


void MenuOption() {
    string options[5]{ "Show menu options press 'M'", "Load in team 1 data press 'F'",
        "Load in team 2 data press 'S'", "Display the who has the highest average press 'D'", "To exit press 'E'"};
    for (string i : options) {
        cout << i << endl;
    }
    cout << endl;
}

void Banner() {
    int starsRows(32);
    int writingStars(4);

    cout << setfill('*');
    cout << setw(starsRows) << "" << endl
        << setw(writingStars) << right << " " << "Sales Comparsion Program" << setw(writingStars) << left << " " << endl
        << setw(starsRows) << "" << endl << endl;
}