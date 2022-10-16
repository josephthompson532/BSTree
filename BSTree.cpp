#include "BSTree.h"
#include "Course.h"


void BSTree::PrintCourseList(Course* course) {

      if (course == nullptr) {
          return;
      }
      
      PrintCourseList(course->left);
      
      cout << endl;
      
      cout << course->courseNumber << ": "; 
      cout << course->courseName << endl;
  
      cout << "Prerequisites: " << endl;
      for( auto prereq : course->prereqs ) {
          Course* prereqObj = Search(prereq);
          cout << prereqObj->courseNumber << " " << prereqObj->courseName << " " << endl;
      }
      
      
      PrintCourseList(course->right);
      
}

void BSTree::Insert(Course* course) {

    if (this->root == nullptr) {
        this->root = course;
        course->left = nullptr;
        course->right = nullptr;
    } else {
        Course* cur = this->root;
        bool flag = true;
        while (flag) {
            if (course->courseNumber < cur->courseNumber) {
                if (cur->left == nullptr) {
                    cur->left = course;
                    flag = false;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right == nullptr) {
                    cur->right = course;
                    flag = false;
                } else {
                    cur = cur->right;
                }
            }
        }
        course->left = nullptr;
        course->right = nullptr;
    }
}

Course* BSTree::Search(string courseNumber) {

    Course* cur = this->root;
    
    while (cur != nullptr) {
        if (cur->courseNumber == courseNumber) {
            return cur;
        }
        
        if (courseNumber < cur->courseNumber ) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    Course* course;
    return course;
}

void BSTree::PrintCourse(Course* course) {
    cout << course->courseNumber << ": " << course->courseName << endl;
    
    cout << "Prerequisites: " << endl;
    for( auto prereq : course->prereqs ) {
        Course* prereqObj = Search(prereq);
        cout << prereqObj->courseNumber << " " << prereqObj->courseName << " " << endl;
    }
    
    cout << endl;
}
