4 classes student, pg_student, research_student, and TA. The student class has name and roll_number as data members. It has a pure virtual display member function. The pg_student class has course1, course2, and course3 data members. It also has a display member function that displays the name, roll_number, course1, 2, and 3 credited by the pg_student. The research_student class has course1 and research_area data members. It has a display function that displays the name, roll_number, course, and research_area of the research_student. The TA class has course_assigned and role data members. The ‘role’ can be either a "PG student" or a "Research student". It also has a display that displays the name, roll_number, course_assigned, and role. Based on the 'role', the display function is additionally display course1, 2, and 3 if the role was a "PG student", and course, and research_area if the role is a "Research student". Also, the course_assigned should is not same as course1, course2, and course3 for a pg_student, and course_assigned is not same as the course for a research_student.
The diamond inheritance is required and the virtual keywords is also used. Arrays of objects are created and details are set only for the TA class alone. Proper boundary conditions are maintained.
A menu-driven program with the following menus:

1. Set Details
2. Display
3. Exit
