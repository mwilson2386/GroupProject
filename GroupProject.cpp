#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

//truct teams {
   // string employeeName[4]; // we store the emoplyees names here. 
   // double employeeSales[4]; // store the that employees sale here
   // double totalTeamWeekSales[4]; // add the weekly sales here for all employees and save them. 
//};
const int ROWS = 3;
const int COLS = 4;

struct Team {
    string Names[ROWS] = {};
    int Scores[ROWS][COLS] = {};
    int Totals[ROWS] = {};
};

// prototypes
void MenuOption();
void Banner();
int GetTeam1(Team Teams[2]);

int main()
{
    // for my switch case
    enum{MENU = 'M', TEAM1 = 'F', TEAM2 = 'S', DISPLAY = 'D', EXIT = 'E' };

    bool loopFlag = true; // for my do while loop.
    char userChoice; // user input
   // teams teamNum[2];// creating each team
    Team Teams[2];
    
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
            GetTeam1(Teams);
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

int GetTeam1(Team Teams[2])
{
    int OverallTotalTeam1 = { 0 };
    int Team1Avg = { 0 };

    fstream my_file;
    my_file.open("Team1Scores.txt");
    if (!my_file) {
        cout << "File Not Found";
        return (-1);
    }
    for (int r = 0; r < ROWS; r++)
    {
        my_file >> Teams[0].Names[r];

        for (int c = 0; c < COLS; c++)
        {

            my_file >> Teams[0].Scores[r][c];
        };

    }
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            Teams[0].Totals[r] += Teams[0].Scores[r][c];
        }
    }
    for (int r = 0; r < ROWS; r++)
    {
        OverallTotalTeam1 += Teams[0].Totals[r];
    }

    Team1Avg = OverallTotalTeam1 / ROWS;

    //Code to Display Results below this Comment.....
    for (int r = 0; r < ROWS; r++)
    {
        cout << Teams[0].Names[r] << " ";


        for (int c = 0; c < COLS; c++)
        {

            cout << Teams[0].Scores[r][c] << " ";


        };
        cout << Teams[0].Totals[r] << endl;

    };
    cout << "The total for Team 1 is: " << OverallTotalTeam1 << endl;
    cout << "The Overall Average for Team 1 is " << Team1Avg << endl;

    my_file.close();
    return (Team1Avg);
};