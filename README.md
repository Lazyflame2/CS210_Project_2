# CS210_Project_2
Project 2 - Compound Interest app

This project will take financial data from user input and outputs report with compound interest building over a set number of years, both with monthly investments and without.

To enhance the project I would like to upgrade the interface to make it easier to use, allow reading input from a file, and output the reports to a file. I would like to further seperate the financial calculations/data and output/menu into different classes. I could have included more named values to further increase readability. I also could have expanded the error checking functionality and included well written exceptions for potential future changes to the program.

The most challenging part was finding a good way to get input that enables the user to return to the menu on a single key press immediately after the reports are printed. I landed on starting an endless loop when the reports were printed that had a small delay incase the user kept the last button pressed for too long. Then it iterates across all keyboard keys looking for a button press with GetAsyncKeyState(), in which case it returns to the main menu. I got the idea from testing new techniques for menu navigation with the keyboard where a seperate thread handled key checking and updated the menu/active line when a key was pressed.

I think the transferable skills from this project include the understanding of proper naming, data security with proper accessors, input handling, and output formatting.

I tried to make the program easy to maintain and read through comments and naming conventions that convey what is happening, and through replacing raw values in code with named values via constants and enumerations. I made each function for a specific task and tried to minimize code complexity so it's easy to understand. I tried to make the program adaptable through modularizing the code into a class and specific methods so the program flow can be easily updated.
