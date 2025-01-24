Library Management System

Overview
The Library Management System is a console-based C++ application designed to manage a collection of books. It allows users to perform various operations such as adding, deleting, searching, and displaying books. Additionally, the system provides a feature to change the background color of the console for a more interactive user experience.

## Installation Instructions
1. Clone the repository or copy the source code.
2. Make sure you have a C++ compiler installed (e.g., g++, MinGW, or Visual Studio).
3. Save the code into a file named `library_management_system.cpp`.
4. Compile the code using your C++ compiler:
   bash
   g++ library_management_system.cpp -o library_management_system
   ```
5. Run the compiled executable:
   ```bash
   ./library_management_system
   ```
Usage Guide
Upon running the program, you will be presented with a menu of options:

1. Add Book: Enter the details of the book (ID, Title, Author) to add it to the library.
2. Delete Book: Remove a book from the library by specifying its ID.
3. Search Book: Look up a book in the library using its ID.
4. Display All Books: View a list of all books currently in the library.
5. Change Background Color: Select a background color for the console from the available options (Blue, Green, Red, Default).
6. Exit: Exit the program.

Example
To add a book:
  ```
  Enter Book ID: 101
  Enter Book Title: The Great Gatsby
  Enter Book Author: F. Scott Fitzgerald
  Book added successfully!
  ```

To search for a book:
  ```
  Enter Book ID to search: 101
  Book Found:
  ID: 101
  Title: The Great Gatsby
  Author: F. Scott Fitzgerald
  ```

Results
The system maintains an up-to-date list of books and displays them in a tabular format. Below is an example:

```
Books in Library:
ID        Title                          Author
------------------------------------------------------------
101       The Great Gatsby               F. Scott Fitzgerald
102       To Kill a Mockingbird         Harper Lee
```

Changing the background color of the console enhances the visual appeal, making the program more engaging.

Features Demonstrated
Data Structures: The program uses a singly linked list to manage book records dynamically.
Algorithms: The system performs operations such as insertion, deletion, and traversal on the linked list.
Error Handling: Input validation ensures the program handles invalid inputs gracefully.
Interactive Console: Users can customize the console appearance using the background color feature.

Future Enhancements
Add support for saving and loading the library database to/from a file.
Implement user authentication for restricted access.
Include additional search filters (e.g., by title or author).
Provide a graphical user interface (GUI) for a more user-friendly experience.

License
This project is open-source and free to use under the MIT License.

