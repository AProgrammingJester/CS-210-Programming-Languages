// Tyler Bryant
// 4/16/2025
// CS 210 Project 3 Module 7-3

#pragma once
#ifndef ITEM_FREQUENCY_MANAGER_H
#define ITEM_FREQUENCY_MANAGER_H

#include <string>
#include <map>

// Class responsible for managing the frequency of grocery items
class ItemFrequencyManager {
private:
    // A map to store item names as keys and their frequencies as values
    std::map<std::string, int> itemFrequencies;

public:
    // Constructor that initializes the object, including loading item data from a file
    ItemFrequencyManager();

    // Reads item data from the specified file and populates the frequency map
    void loadItemsFromFile(const std::string& filename);

    // Displays the frequency of a specific item
    void showItemFrequency(const std::string& item) const;

    // Displays the frequencies of all items
    void showAllItemFrequencies() const;

    // Displays a histogram of item frequencies with a heat map color scheme
    void displayFrequencyHistogram() const;

    // Writes the frequencies of all items to a specified file
    void saveFrequenciesToFile(const std::string& filename) const;
};

#endif // ITEM_FREQUENCY_MANAGER_H