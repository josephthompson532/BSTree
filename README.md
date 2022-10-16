# Module 8 Repo

### What was the problem you were solving in the projects for this course?

Academic Advising wanted me to make a program that could do 2 things:
- print a list of all of the computer science courses in alphanumeric order
- given a course's Number, print other details about the course and its prerequisites

Necessary also in doing this was writing a program that could parse a csv file into a set of course objects. There also needed to be an easy to use menu since the advising team does not know how to program.

### How did you approach the problem? Consider why data structures are important to understand.

I approached my problem by first asking myself which data structure would be most appropriate to use for solving this problem most efficiently. In this case, we were interested in printing out the courses in a particular order and doing quick lookups of a given course. For each of these problems, the binary search tree was the ideal candidate. A hashmap would have had slightly faster lookups, but would still need to be sorted like a vector to be printed in order, would made binary search tree still the better choice.

### How did you overcome any roadblocks you encountered while going through the activities or project?

I overcame these roadblocks by spreqding out the work over time. Increasingly I find that I am much more productive if I break my work into separate sittings with breaks in between. Also, I break my work down into separate smaller pieces and attempt to solve only one piece in a given sitting. This prevents me from feeling overwhelmed and trying to get things done too quick. Rushing doesn't help in programming. In fact, it is conducive to creating bugs.

### How has your work on this project expanded your approach to designing software and developing programs?

I now have a whole new set of tools in my toolbelt. Not only can I address how to solve a problem, but the most efficient way to solve a problem. Also, depending on my operating platform and time constraints, I can address issues related to memory constraints or time constraints by picking a better data structure or algorithm.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

I found that first writing the program in pseudocode helps me to plan, conceptualize, and architect a solution without getting too hung up on the syntax of a picky language like C++. Ultimately it actually speeds up development.