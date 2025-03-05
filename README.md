Student Management System.
1. A simple C program for managing student records.
2. This system allows users to perform operations such as adding, displaying, searching, updating, and deleting student records stored in a binary file.

Features.
1. Add Student: Add a new student's record with details like ID, name, age, and marks.
2. Display Students: Display all student records stored in the system.
3. Search Student: Search for a student by their ID and view their details.
4. Update Student: Update the details of an existing student using their ID.
5. Delete Student: Delete a student's record based on their ID.

Requirements.
1. A C Compiler (e.g., GCC) or an IDE (e.g., Visual Studio, Code::Blocks, Dev C++)
2. Basic understanding of file handling in C.

How to Use.
1. Open the Program.
2. Open the code.c file in your preferred C IDE (e.g., Visual Studio, Code::Blocks, etc.).

Run the Program.
Simply click the "Run" button in your IDE to compile and execute the program.

Menu Options.
Once the program is running, you will be presented with a menu that allows you to:

1. Add Student: Enter student details (ID, name, age, marks) to add a new student.
2. Display Students: View the list of all students stored in the system.
3. Search Students: Enter a student ID to search and display their details.
4. Update Students: Update a student’s information based on their ID.
5. Delete Students: Delete a student’s record based on their ID.
6. Exit: Exit the program.

Example Menu:

=== Student Management System ===
1. Add Student
2. Display Students
3. Search Students
4. Update Students
5. Delete Students
6. Exit
Enter your choice:
The program will prompt you to input the student details or a student ID based on the operation selected.

File Format.
The program stores student records in a binary file called StudentRec.DAT. The format of the record is as follows:
1. id (int): Student ID
2. name (char[25]): Student's name (up to 24 characters)
3. age (int): Student's age
4. marks (float): Student's marks

How It Works.
1. Add Student: The program asks for student details and appends them to the file StudentRec.DAT.
2. Display Students: Reads the file and displays all stored student records.
3. Search Student: Finds and displays a student's details by their ID.
4. Update Student: Allows updating the student's name, age, and marks using their ID.
5. Delete Student: Deletes the student record from the file by ID.

Notes.
1. The program uses file handling to store student records persistently in the binary file StudentRec.DAT.
2. Ensure that the StudentRec.DAT file exists in the directory where the program is run, or it will be created upon adding new records.
3. The program does not implement any error handling for invalid inputs (such as entering non-numeric values for ID or marks), so please ensure the data is entered correctly.

Sample Output.
=== Student Management System ===
1. Add Student
2. Display Students
3. Search Students
4. Update Students
5. Delete Students
6. Exit
Enter your choice: 2
=== Student Records ===
ID: 111.
Name: Genny
Age: 25
Marks: 567.80
ID: 222
Name: Jhon
Age: 22
Marks: 678.90

License.
This program is free to use and modify. For personal use only.
