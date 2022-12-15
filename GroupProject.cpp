#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

// 3 const int that will show up all program
const int ROWS = 3;
const int COLS = 4;
const int TEAMS_NO = 2;


// setting up our structure
struct Team {
    string Names[ROWS] = {};
    int Scores[ROWS][COLS] = {};
    int Totals[ROWS] = {};
    int Average = {};
};

// prototypes
void MenuOption();
void Banner();
bool GetTeam1 (Team teams[TEAMS_NO]);
void GetTeam2(Team teams[TEAMS_NO]);
void displaySales(Team teams[TEAMS_NO], int teamNumber);
void showAverage(Team teams[TEAMS_NO]);
void saveToFile(Team teams[TEAMS_NO]);

int main()
{
    // for my switch case
    enum{MENU = 'M', TEAM1 = 'F', TEAM2 = 'S', DISPLAYAVG = 'A', EXIT = 'E' };
    // using to pass as a variable later
    int teamNumber = 0;
    string result;
    bool loopFlag = true; // for my do while loop.
    char userChoice; // user input
   // teams teamNum[2];// creating each team
    Team Teams[TEAMS_NO];
    
    // call my opening of the program
    Banner();
    // creating the result of simple if then statement
    result = (GetTeam1(Teams) == true) ? "Team 1 Data loaded!" : "Data File did not load. Please exit and try again";
    cout << result << endl;

    // get team data
    GetTeam2(Teams);

    // start with the menu options
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
            teamNumber = 0;
            displaySales(Teams, teamNumber);
            break;
        case(TEAM2):
            teamNumber = 1;
            displaySales(Teams, teamNumber);
            break;
        case(DISPLAYAVG):
            showAverage(Teams);
            break;
        case(EXIT):
            cout << "Thank you." << endl;
            saveToFile(Teams);
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
    string options[5]{ "Show menu options press 'M'", "Display Team 1 Sales 'F'",
        "Display Team 2 Sales 'S'", "Display the which team has the highest average press 'A'", "To exit press 'E'"};
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

bool GetTeam1(Team Teams[TEAMS_NO])
{
    int OverallTotalTeam1 = { 0 };
    int Team1Avg = { 0 };

    fstream my_file;
    my_file.open("Team1Scores.txt");
    if (!my_file) {
        cout << "File Not Found";
        my_file.close();
        return false;
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

    Teams[0].Average = OverallTotalTeam1 / ROWS;

   // cout << "The total for Team 1 is: " << OverallTotalTeam1 << endl;
   // cout << "The Overall Average for Team 1 is " << Team1Avg << endl;

    my_file.close();
    return true;
};

void GetTeam2(Team teams[TEAMS_NO])
{
    // A. LOADING TEAM 2
    cout << endl << "Please enter the information for Team 2's members below." << endl << endl;
    // Variables
    string names;
    int OverallTotalTeam2 = 0;
    int Team2Avg = 0;
    // Outer loop
    for (int i = 0; i < ROWS; i++)
    {
        // Prompting for names
        cout << "MEMBER " << i + 1 << "." << endl;
        cout << "Name: ";
        cin >> teams[1].Names[i];

        // // Reset the total after each row
       // teams[1].Totals[i] = 0;

        // Inner loop
        for (int j = 0; j < COLS; j++)
        {
            // Prompting for scores
            cout << "Week " << j + 1 << ": ";
            cin >> teams[1].Scores[i][j];

            // Calculating the total for each member
            teams[1].Totals[i] += teams[1].Scores[i][j];

        } // end inner loop

        // Calculating the total for the whole team
        OverallTotalTeam2 += teams[1].Totals[i];

        cout << endl;
    } // end outer loop
    // Calculating the average for the whole team
    teams[1].Average = OverallTotalTeam2 / ROWS;

}

void displaySales(Team teams[TEAMS_NO], int teamNumber) {
   
    // set a banner
    cout <<setfill('*') << setw(20) << right << " " << "Sales Comparsion Program" << setw(20) << left << " " << endl << endl;
    cout << setfill('.');

    // set the output statement looading top information
    cout << setw(15) << left << "Name";
    // display the weeks with a loop
    for (int i = 1; i < 5; i++) {
        cout << "week" << i << setw(6) << left << "";
    }
    // display the total
    cout << "Total" << endl;
    // set seprator
    cout << setfill('-') << setw(66) << "" << endl;
    cout << setfill('.');
    // star with the teams
    for (int r = 0; r < ROWS; r++)
    {
        cout <<setfill ('.') << setw(15) << left << teams[teamNumber].Names[r] << "$";

        // go through the team members weekly score then display them the 
        for (int c = 0; c < COLS; c++)
        {
            cout << left << setw(10) << teams[teamNumber].Scores[r][c] << right << "$";
        };
        // show the total sales for the team member
        cout << "" << teams[teamNumber].Totals[r] << endl << endl;
    }
}
void showAverage(Team teams[TEAMS_NO]) {
    // two local variables
    string highest;
    int teamNum;

    // for loop for same line
    for (int i = 0; i < TEAMS_NO; i++) {

        cout << "The average for team " << i + 1 << " is $ : " << teams[i].Average << endl;
    }
    // if else statement to get highest value and teamNum values
    if (teams[0].Average > teams[1].Average) {
        highest = "Team 1";
        teamNum = 0;
    }
    else {
        highest = "Team 2";
        teamNum = 1;
    }
    // showing the highest value
    cout << "The highest average selling tean is " << highest << " with an average of sales of :$ "<< teams[teamNum].Average << endl;

}
void saveToFile(Team teams[TEAMS_NO]) {
    ofstream outFile;

    string highest;
    int teamNum;
    outFile.open("salesdata.txt");
    // set a banner
    outFile << setfill('*') << setw(20) << right << " " << "Sales Comparsion Program" << setw(20) << left << " " << endl << endl;
    outFile << setfill('.');
    for (int x = 0; x < TEAMS_NO; x++) {
        outFile << setw(15) << left << "Name";
        // display the weeks with a loop
        for (int i = 1; i < 5; i++) {
            outFile << "week" << i << setw(6) << left << "";
        }
        // display the total
        outFile << "Total" << endl;
        // set seprator
        outFile << setfill('-') << setw(66) << "" << endl;
        outFile << setfill('.');
        // star with the teams
        for (int r = 0; r < ROWS; r++)
        {
            outFile << setfill('.') << setw(15) << left << teams[x].Names[r] << "$";

            // go through the team members weekly score then display them the 
            for (int c = 0; c < COLS; c++)
            {
                outFile << left << setw(10) << teams[x].Scores[r][c] << right << "$";
            };
            // show the total sales for the team member
            outFile << "" << teams[x].Totals[r] << endl << endl;
        }
        outFile << "The average for team " << x + 1 << " is $ : " << teams[x].Average << endl;
    }

    // if else statement to get highest value and teamNum values
    if (teams[0].Average > teams[1].Average) {
        highest = "Team 1";
        teamNum = 0;
    }
    else {
        highest = "Team 2";
        teamNum = 1;
    }
    // showing the highest value
    outFile << "The highest average selling tean is " << highest << " with an average of sales of $" << teams[teamNum].Average << endl;
   
    outFile.close();
}