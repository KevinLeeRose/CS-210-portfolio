# CS 210 Portfolio Submission – Corner Grocer Tracker
This repository contains my final project for CS 210, a C++ program designed to track grocery item frequencies from a transaction log. The goal was to build a tool that reads input from a file, counts how often each item appears, and provides a menu-driven interface for users to search, view, and export that data. I structured the logic around a dedicated class to keep things modular and maintainable, and I validated functionality through hands-on testing and iterative refinement.

## Journal Reflection
This project tackled a practical inventory problem—how to track item frequency from a raw transaction list. I built a class-based solution using C++ maps to store item counts, and added functions to print results, generate a histogram, and write a backup file. The menu system lets users interact with the data in a clean, guided way.

One thing I did particularly well was separating concerns. The `GroceryTracker` class handles all file I/O and frequency logic, while `main()` focuses on user interaction. That separation made the code easier to test, annotate, and adapt. I also added input validation to catch bad entries and guide users back to the menu without crashing the program.

If I were to enhance the code, I’d add exception handling around file operations and improve input sanitization—especially for multi-word items and edge cases. These changes would make the program more robust and secure, especially if scaled for real-world use. I’d also consider adding case-insensitive search and trimming whitespace to improve usability.

The histogram logic was a fun challenge. I wanted it to be readable and scalable, so I used a simple loop to print asterisks based on item count. Testing that output helped me confirm the map was storing values correctly. I leaned on iterative testing and console output to validate each function before moving on.

Skills from this project—like modular design, input validation, and file handling—are directly transferable to future coursework and real-world development. The use of maps, loops, and structured logic applies to any data-driven application. I also practiced writing code that’s teachable and reproducible, which supports mentoring and collaborative troubleshooting.

To keep the program maintainable, I used consistent naming, clear comments, and a class structure that supports future expansion. Each function has a focused role, and the code is annotated to help others understand the logic. Whether someone’s reviewing it for grading or adapting it for a new use case, the structure makes it easy to follow and extend.
