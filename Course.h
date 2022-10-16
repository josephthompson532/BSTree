#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Course {
    
    private:
    
    public:
        string courseNumber;
        string courseName;
        vector<string> prereqs;
        Course* left;
        Course* right;
        Course(string courseNumber, string courseName, vector<string> prereqs);
        Course();
        ~Course();
        
};

#endif // COURSE_H
