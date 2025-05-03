# CS-210-Programming-Languages-project-3-Corner-Grocer

1. Summarize the project and what problem it was solving.
My project aimed to create a grocery item tracking system that reads data from a text file, counts how often each item appears, and provides multiple ways to view this frequency data visually. The goal was to help users quickly identify trends in grocery purchases.

2. What did you do particularly well?
I implemented clean and modular code using Object-Oriented Programming. I was particularly effective in creating a user-friendly menu system and designing a histogram visualization with color coding, which added an intuitive interface to interpret item frequency data.

3. Where could you enhance your code?
Enhancements could include:

Input validation: Strengthen handling of user input to prevent incorrect or unexpected behavior.

Cross-platform support: Replace windows.h with standard output manipulation for compatibility on non-Windows systems.

Efficiency: Cache max frequency instead of recalculating in loops.

4. Which pieces of the code did you find most challenging to write, and how did you overcome this?
The most challenging part was implementing the color-coded histogram with Windows-specific console manipulation. I overcame this by researching SetConsoleTextAttribute and experimenting with different color codes. Resources like C++ topics were very helpful in understanding Windows console behavior.

5. What skills from this project will be particularly transferable to other projects or coursework?
File I/O handling using C++

Object-Oriented Programming (encapsulation, abstraction)

User input handling

Basic data visualization (histograms)

Debugging and refactoring based on design goals

These skills are widely applicable in software development and data analysis tasks.

6. How did you make this program maintainable, readable, and adaptable?
Readable: Clear naming conventions and comments explaining each step.

Maintainable: Separated functionality using classes and headers, making the code modular.

Adaptable: Used standard data structures (std::map, std::string) and encapsulated logic in methods that can easily be reused or extended.
