#include "Course.h"

Course::Course() {
    
};

Course::Course(string courseNumber, string courseName, vector<string> prereqs) {
    this->courseNumber = courseNumber;
    this->courseName = courseName;
    this->prereqs = prereqs;
};

Course::~Course() {
    
};
