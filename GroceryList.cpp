// Tyler Bryant
// 4/16/2025
// CS 210 Project 3 Module 7-3

#include "ItemFrequencyManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>
#include <iomanip>
#include <algorithm>

// Helper function: Convert a string to lowercase for case-insensitive comparison
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Constructor: Loads item data from file and writes initial frequencies to backup file
ItemFrequencyManager::ItemFrequencyManager() {
    loadItemsFromFile("CS210_Project_Three_Input_File.txt");
    saveFrequenciesToFile("frequency.dat");
}

// Load item data from a file into the frequency map
void ItemFrequencyManager::loadItemsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string item;
    while (file >> item) {
        itemFrequencies[toLower(item)]++;
    }

    file.close();
}

// Show the frequency of a specific item
void ItemFrequencyManager::showItemFrequency(const std::string& item) const {
    std::cout << "\n" << std::endl;

    std::string lowerItem = toLower(item);
    auto it = itemFrequencies.find(lowerItem);

    if (it != itemFrequencies.end()) {
        std::cout << item << ": " << it->second << std::endl;
    }
    else {
        std::cout << "Item not found." << std::endl;
    }
}

// Display frequencies for all items
void ItemFrequencyManager::showAllItemFrequencies() const {
    std::cout << "\n" << std::endl;
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Display histogram of frequencies using heatmap-style coloring
void ItemFrequencyManager::displayFrequencyHistogram() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    size_t longestNameLength = 0;
    for (const auto& pair : itemFrequencies) {
        if (pair.first.length() > longestNameLength) {
            longestNameLength = pair.first.length();
        }
    }

    int maxFrequency = 0;
    for (const auto& pair : itemFrequencies) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }

    std::cout << "\n" << std::endl;
    for (const auto& pair : itemFrequencies) {
        double ratio = pair.second / static_cast<double>(maxFrequency);

        int colorCode;
        if (ratio < 0.2) colorCode = 9;
        else if (ratio < 0.4) colorCode = 10;
        else if (ratio < 0.6) colorCode = 11;
        else if (ratio < 0.8) colorCode = 13;
        else colorCode = 15;

        SetConsoleTextAttribute(hConsole, colorCode);

        std::cout << std::left << std::setw(longestNameLength) << pair.first << " : ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    SetConsoleTextAttribute(hConsole, 7); // Reset color
}

// Save item frequencies to a file
void ItemFrequencyManager::saveFrequenciesToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& pair : itemFrequencies) {
        file << pair.first << " " << pair.second << std::endl;
    }

    file.close();
}