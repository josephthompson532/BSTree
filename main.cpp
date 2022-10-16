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
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    
    fstream file (filepath, ios::in);
    
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();
            
            stringstream str(line);
            while (getline(str, word, ',')) {
                row.push_back(word);
            }
            content.push_back(row);
            
        }
        
        for ( auto row_vector : content) {
            string courseNumber;
            string courseName;
            vector<string> prereqs;
            
            courseNumber = row_vector.at(0);
            courseName = row_vector.at(1);
            
            if ( row_vector.size() > 2 ) {
                for ( int y = 2; y < row_vector.size(); y++ ) {
                    prereqs.push_back(row_vector.at(y));
                }
            }
            Course* course = new Course(courseNumber, courseName, prereqs);
            dataStructure->Insert(course);
        }
        
    } else {
        cout << "File was not able to be open" << endl;
    }
}

//int main(int argc, char **argv)
//{
//    
//    string filepath;
//    cout << "What is the filepath: ";
//    cin >> filepath;
//    readFile(filepath);
//    
//}

int main(int argc, char **argv)
{
    
    string filePath;
    cout << "What is the filepath: ";
    cin >> filePath;
    
    BSTree* tree = new BSTree();
    
    Course course;
    
    int choice = 0;
    while(choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
        case 1:
            readFile(filePath, tree);
            break;
        case 2:
            tree->PrintCourseList(tree->root);
            break;
        case 3:
        {
            string userCourseNumber;
            
            cout << "Please enter a course number: ";
            cin >> userCourseNumber;
            
            Course* chosenCourse = tree->Search(userCourseNumber);
            cout << endl;
            
            tree->PrintCourse(chosenCourse);
            break;
            
        }
        default:
            cout << endl;
            cout << "That is not a valid option. \nChoose only 1, 2, 3, or 9.";
            cout << endl << endl;
            break;
        }
    }
    
	printf("hello world\n");
	return 0;
}