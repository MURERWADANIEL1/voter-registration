/*The Interim Independent Electoral Commission (IIEC) of Kenya requires an Electronic Voting Management System (EVMS) through which new voters can be added, invalid voters deleted as well as displaying of a voter’s details, among other functions.

Voter details include voter card ID, National ID Number, First Name, middle name, surname, polling station, date of birth (entered in dd-mm-yyyy format) and  gender .

In an interview for  an advertised Software Developer position, the commission has requested you to demonstrate with a simple program how a voter details can be added and displayed.  Using your own defined and appropriate voter class and an interactive driver program (i.e. main function) write a C++ program to achieve this.*/


//code to be executed//

#include <iostream>//
#include <vector>//to be used in storing elements
#include <string>//to represent sequence of characters

using namespace std;//collection of related names and indentifiers

// Defining the Voter class
class Voter {
public://members will be accessible from anywhere where obj will be visible
    string voterCardID;
    string nationalIDNumber;
    string firstName;
    string middleName;
    string surname;
    string pollingStation;
    string dateOfBirth;
    string gender;
};

//vector to store values
vector<Voter> voters;

// Function for adding voters
void addVoter() {
    Voter voter;
    cout << "Enter Voter Card ID: "<<endl;
    cin >> voter.voterCardID;
    cout << "Enter National ID Number: "<<endl;
    cin >> voter.nationalIDNumber;
    cout << "Enter First Name: "<<endl;
    cin >> voter.firstName;
    cout << "Enter Middle Name: "<<endl;
    cin >> voter.middleName;
    cout << "Enter Surname: "<<endl;
    cin >> voter.surname;
    cout << "Enter Polling Station: "<<endl;
    cin >> voter.pollingStation;
    cout << "Enter Date of Birth (dd-mm-yyyy): "<<endl;
    cin >> voter.dateOfBirth;
    cout << "Enter Gender (male/female/undefined): "<<endl;
    cin >> voter.gender;
    voters.push_back(voter);//will increase size of vector when an element will be added
}

// Function for displaying added voters
void displayVoters() {
    cout << "Voter Details:" << endl;
    for (int i = 0; i < voters.size(); i++) {
        cout << "Voter Card ID: " << voters[i].voterCardID << endl;
        cout << "National ID Number: " << voters[i].nationalIDNumber << endl;
        cout << "Name: " << voters[i].firstName << " " << voters[i].middleName << " " << voters[i].surname << endl;
        cout << "Polling Station: " << voters[i].pollingStation << endl;
        cout << "Date of Birth: " << voters[i].dateOfBirth << endl;
        cout << "Gender: " << voters[i].gender << endl;
        cout << endl;
    }
}

// Function for deleting a voter
void deleteVoter() {
    string idToDelete;
    cout << "Enter Voter Card ID to delete: "<<endl;
    cin >> idToDelete;//takes in the id to be deleted
    for (int i = 0; i < voters.size(); i++) {
        if (voters[i].voterCardID == idToDelete) {
            voters.erase(voters.begin() + i);//for iterates this code depending on vector size
            cout << "Voter with ID " << idToDelete << " deleted successfully." << endl;
            return;
        }
    }
    cout << "Voter with ID " << idToDelete << " not found." << endl;
}

// code main
int main() {
    int choice;//prompts user to input a choice
    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Add Voter" << endl;//allows to add voter
        cout << "2. Display Voters" << endl;//displays voter
        cout << "3. Delete Voter" << endl;//allows to delete voter
        cout << "4. Exit" << endl;//exit the program
        cin >> choice;
        switch (choice) {
            case 1:
                addVoter();//when user chooses option 1
                break;//terminates the first case
            case 2:
                displayVoters();//when user inputs 2
                break;//terminates case
            case 3:
                deleteVoter();//when user chooses 3
                break;//terminates delete case
            case 4:
                cout << "Exiting..." << endl;
                break;//terminates when exit
            default://if opposite iption is selected
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);//while will first evaluate the condition
    return 0;//terminates execution of a function and returns control to calling function
}
