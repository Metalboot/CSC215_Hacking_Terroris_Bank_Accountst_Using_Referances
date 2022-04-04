// hackingandBankruptingTerroristsUsingReferences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Author: Donald Christensen
Email : donchris@uat.edu
Assignment Name : Hacking and Draining Bank Accounts Using References
*/

// Includes certain libraries & header files
#include <iostream>
#include <string>
#include <Windows.h>

// Namespace Block
using namespace std;

// Variable Block
string agentName = "";
string assignAns = "";
string donutCave = "Donalds Donut Cave";

// Function Block
int runAssign();

void opening() {
    cout << "\n------------------------------------\n\n";
    cout << "Today we will be spying on a terrorist organization's bank account at Star Bank." << endl;
    cout << "When the time comes, we will swap their bank account balance with the balance of a local coffee shop, " << donutCave << "." << endl;
    cout << "When we send you the cue to strike, you will have to swap the account balances." << endl;
    cout << "As always you will have the chance to accept or deny the job, but remember it's terrorist.\n";
    cout << "\n------------------------------------\n\n";
}

void normBal(double terrBal, int swapState) { // Creates a void function with terrBal as a double and swapState as an int.
    if (swapState == 0) {
        cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
        cout << "Currently viewing 'NoTerroristHere_Organization' account balance..." << endl;
        cout << "'NoTerroristHere_Organization' balance is $" << terrBal << "" << endl;
    }
    else {
        cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
        cout << "Currently viewing " << donutCave << " account balance..." << endl;
        cout << donutCave << " balance is $" << terrBal << "" << endl;
    }
}

void swapBal(double& terrBal, double& newBal, int swapState) { // Creates a void function with terrBal now as a referenced double from the original, creates a referenced double as newBal, and finally swapState as an int.
    if (swapState == 0) {
        cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
        cout << "Currently viewing " << donutCave << " account balance..." << endl;
        cout << donutCave << " balance is $" << newBal << "" << endl;
    }
    else {
        cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
        cout << "Currently viewing 'NoTerroristHere_Organization' account balance..." << endl;
        cout << "'NoTerroristHere_Organization' balance is $" << newBal << "" << endl;
    }
}

int main() {
    cout << "If you choose to accept this assignment please complete the following.\n";
    cout << "Please log in to verify credentials.\n";
    cout << "Enter Last Name: ";
    cin >> agentName;
    cout << "\nWelcome, Agent " << agentName << ".\n";
    Sleep(3000); // Delays output for three seconds. 

    opening();
    cout << ": ";
    cin >> assignAns;
    // If assignment answer is yes, run the assignment.
    if (assignAns == "yes" || assignAns == "Yes" || assignAns == "YES") {
        runAssign();
    }
    // If the user types anything but yes after the introduction of the assignment, return a value of 0 and turminate the program.
    else {
        cout << "\nConnection Terminated... Goodbye Agent " << agentName << ".\n";
        return 0;
    }
}

int runAssign() {
    // Variables for balances & swap string.
    double noTerroristBal = 100001.61;
    double& terrBal = noTerroristBal;
    double coffeeBal = 107.28;
    double& r_coffeeBal = coffeeBal;
    string change = "";

    cout << "\nOkay Agent " << agentName << ", today is the day we make the switch." << endl;
    cout << "First we will check the current balance of the donut cave.\n" << endl;
    Sleep(5000);
    normBal(coffeeBal, 1); // Runs the normBal function with terrBal set to coffeeBal and swapState set to 1.
    cout << "\nNow we will look at the terrorist's current balance.\n" << endl;
    Sleep(5000);
    normBal(noTerroristBal, 0); // Runs the normBal function with terrBal set to terrBal and swapState set to 0.

    cout << "\nOkay, we know both account's current balances. Now we have to swap them." << endl;
    cout << "On my mark, type 'change' and the account's balances will switch.\n" << endl;
    Sleep(5000);
    cout << "3...\n" << endl;
    Sleep(1000);
    cout << "2...\n" << endl;
    Sleep(1000);
    cout << "1...\n" << endl;
    Sleep(1000);
    cout << "Swap them!\n" << endl;

    while (change != "change" || change != "Change") {
        cout << ": ";
        cin >> change;
        // Once the user correctly types swap, break the loop.
        if (change == "change" || change == "Change") {
            break;
        }
        else {
            cout << "\nNot quite, you need to type 'change'.\n\n";
        }
    }

    cout << "\nGood work, lets see the new account balances.\n\n";
    Sleep(5000);
    swapBal(r_coffeeBal, noTerroristBal, 0); // Runs the swapBal function with reference terrBal set to reference coffeeBal, reference newBal set to reference terrBal, and swapState set to 0.
    cout << "\nNow we will look at the terrorist's current balance.\n" << endl;
    Sleep(5000);
    swapBal(noTerroristBal, r_coffeeBal, 1); // Runs the swapBal function with reference terrBal set to reference terrBal, reference newBal set to coffeeBal, and swapState set to 1.
    Sleep(3000);
    cout << "\nAs always great work Agent " << agentName << ". We have successfully drained the bank account of the terrorist organization and benefitted the " << donutCave << "." << endl;
    cout << "\nA new assigment will be given to you within the coming weeks. Until then, wait for further instruction." << endl;
    cout << "\nConnection Terminated... Goodbye Agent " << agentName << "." << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
