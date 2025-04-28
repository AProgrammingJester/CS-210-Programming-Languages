// Tyler Bryant
// 4/16/2025
// CS 210 Project 3 Module 7-3

#include <iostream>
#include "ItemFrequencyManager.h" // Include the header file for the ItemFrequencyManager class

int main() {
    // Create an instance of the ItemFrequencyManager to manage item frequencies
    ItemFrequencyManager manager;

    bool running = true; // Control variable for the main loop

    // Main loop for the program
    while (running) {
        // Display the menu options to the user
        std::cout << "\nCorner Grocer Item Tracking System\n";
        std::cout << "=================================================\n";
        std::cout << "1. Search for the frequency of a specific item  |\n";
        std::cout << "2. Display the frequencies of all items         |\n";
        std::cout << "3. Show a histogram of item frequencies         |\n";
        std::cout << "4. Exit                                         |\n";
        std::cout << "=================================================\n\n";
        std::cout << "Please enter your choice: ";

        int choice;
        std::cin >> choice; // Read the user's choice

        // Clear the input buffer to handle any input errors
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            // Prompt user to input the name of the item they want to search for
            std::string item;
            std::cout << "Enter the name of the item to search for: ";
            std::getline(std::cin, item); // Read the item name from the user

            // Display the frequency of the specified item
            manager.showItemFrequency(item);
            break;
        }
        case 2:
            // Display the frequencies of all items in the system
            manager.showAllItemFrequencies();
            break;
        case 3:
            // Display the histogram of item frequencies
            manager.displayFrequencyHistogram();
            break;
        case 4:
            // Exit the program
            std::cout << "Exiting program." << std::endl;
            running = false; // Set running to false to exit the loop and end the program
            break;
        default:
            // Handle invalid menu options
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0; // Return 0 to indicate successful completion of the program
}