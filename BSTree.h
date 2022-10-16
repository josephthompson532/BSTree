#ifndef BSTREE_H
#define BSTREE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <fstream>
#include <sstream>
#include "Course.h"

using namespace std;

class BSTree {
public:
    Course* root;
    void Insert(Course* course);
    void PrintCourseList(Course* course);
    Course* Search(string CourseNumber);
    void PrintCourse(Course* course);
};

#endif // BSTREE_H
