// CornerGrocerTracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>     // Console input/output
#include <fstream>      // File reading/writing
#include <map>          // Map for item counts
#include <string>       // String handling
using namespace std;

// Tracks item counts and handles file operations
class GroceryTracker {
public:
    GroceryTracker();                         // Loads data from input file
    int GetItemFrequency(const string& item); // Returns count for one item
    void PrintAllFrequencies();               // Shows all items and counts
    void PrintHistogram();                    // Shows items as asterisks
    void WriteBackupFile();                   // Saves counts to frequency.dat

private:
    map<string, int> itemFrequency;           // Item -> count
    void LoadDataFromFile();                  // Reads input file
};

// Loads data when object is created
GroceryTracker::GroceryTracker() {
    LoadDataFromFile();
}

// Reads items from file and updates map
void GroceryTracker::LoadDataFromFile() {
    ifstream inFile("CS210_Project_Three_Input_File.txt");
    string item;
    while (inFile >> item) {
        itemFrequency[item]++;
    }
    inFile.close();
}

// Returns how many times an item was found
int GroceryTracker::GetItemFrequency(const string& item) {
    return itemFrequency[item];
}

// Prints each item and its count
void GroceryTracker::PrintAllFrequencies() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Prints each item with asterisks for count
void GroceryTracker::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Writes item counts to backup file
void GroceryTracker::WriteBackupFile() {
    ofstream outFile("frequency.dat");
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();
}

// Runs the menu and handles user input
int main() {
    GroceryTracker tracker;          // Load data and create backup
    tracker.WriteBackupFile();

    int choice;
    string item;

    do {
        // Show menu
        cout << "\nCORNER GROCER MENU\n";
        cout << "1. Search for item frequency\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        // Check for letter input
        if (cin.fail()) {
            cin.clear();              // Clear error flag
            cin.ignore(1000, '\n');   // Discard invalid input
            cout << "Try again. Please enter a number between 1 and 4.\n";
            continue;                 // Skip to next loop iteration
        }



        switch (choice) {
        case 1:
            // Search for one item
            cout << "Enter item name: ";
            cin >> ws;
            getline(cin, item);
            cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times.\n";
            break;
        case 2:
            // Show all items
            tracker.PrintAllFrequencies();
            break;
        case 3:
            // Show histogram
            tracker.PrintHistogram();
            break;
        case 4:
            // Exit
            cout << "Exiting program...\n";
            break;
        default:
            // Handle bad input
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}