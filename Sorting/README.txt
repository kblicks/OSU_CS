
Name: Katie Blickenstaff
ONID: blickenk
CS 162 Section 01
Assignment #1

Description: This program can read in two text files contain information about wizards and the other about spellbooks and spells. 
The user can login as a wizard with the right ID and password then sort the spellbooks and spells as the user decides. 
The spellbooks can be sorted by number of pages in ascending order or by average success rate. The spells can be grouped by effect. 
The user can then choose to print the results to the console or create and open a file of their naming to write the spells to. 
If the file has already been created, then the information can be appended to the current file. The program will continue
sorting and printing the information until the user decides to quite. 

Instructions: 
1. Run the program with the command  ./run_wizard.cpp wizards.txt spellbooks.txt
2. Enter ID
3. Enter password 
4. Choose an option 1-3
5. Choose how you want the results displayed 1-2
6. Continue to sort and print until option 4-quit is chosen


Limitations: There is no error handling for entering a filename, but the user cannot enter a blank name.
The command line argument will not work if wizards text is not entered before spellbooks text.  