#include <stdio.h>
#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <fstream>
#include <sstream>
#include "BSTree.h"
#include "Course.h"


using namespace std;


void readFile(string filepath, BSTree* dataStructure) {
    
    // Declare variables to hold data about the ocurse object
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    
    // Open the file stream
    fstream file (filepath, ios::in);
    
    // if the file is successfully opened, pasre the csv, otherwise send an error message to the user
    if (file.is_open()) {
        // insofar as there is a next line, keep running
        while (getline(file, line)) {
            row.clear();
            
            stringstream str(line);
            // loop, getting each word using ',' as a delimiter
            while (getline(str, word, ',')) {
                row.push_back(word);
            }
            content.push_back(row);
            
        }
        
        // take each row and create a course object using its contents
        for ( auto row_vector : content) {
            
            // create the variables that make up a course object
            string courseNumber;
            string courseName;
            vector<string> prereqs;
            
            courseNumber = row_vector.at(0);
            courseName = row_vector.at(1);
            
            // if the course has any prereqs, pass these into a vector
            if ( row_vector.size() > 2 ) {
                for ( int y = 2; y < row_vector.size(); y++ ) {
                    prereqs.push_back(row_vector.at(y));
                }
            }
            
            // Instantiate the new course object
            Course* course = new Course(courseNumber, courseName, prereqs);
            // Add the new course into its proper place in the Binary Search Tree
            dataStructure->Insert(course);
        }
        
    } else {
        // if file is unopenable, let the user know.
        cout << "File was not able to be open" << endl;
    }
}


int main(int argc, char **argv)
{
    
    // first, ask the user for the path to the csv file
    string filePath;
    cout << "What is the filepath: ";
    cin >> filePath;
    
    // Create the data structure that will hold the course info from the csv.
    BSTree* tree = new BSTree();
    
    // Print out a menu of choices for the user
    int choice = 0;
    while(choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        
        // Read in the users choice
        cin >> choice;
        
        // depending on the users choice, execute a different block of code.
        switch(choice) {
        case 1:
            // Read in the lines from the csv
            readFile(filePath, tree);
            break;
        case 2:
            // print out all the courses in alphanumeric order. 
            tree->PrintCourseList(tree->root);
            break;
        case 3:
        {
        
            string userCourseNumber;
            
            // ask the user for a course number to lookup
            cout << "Please enter a course number: ";
            cin >> userCourseNumber;
            
            // lookup the actual course from the courseNumber
            Course* chosenCourse = tree->Search(userCourseNumber);
            cout << endl;
            
            // print the course details
            tree->PrintCourse(chosenCourse);
            break;
            
        }
        // if the user doesn't enter a valid choice, prompt them to enter a better one.
        default:
            cout << endl;
            cout << "That is not a valid option. \nChoose only 1, 2, 3, or 9.";
            cout << endl << endl;
            break;
        }
    }
    
	return 0;
}