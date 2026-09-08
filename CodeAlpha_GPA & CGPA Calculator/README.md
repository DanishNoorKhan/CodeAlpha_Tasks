# 🎓 SGPA & CGPA Calculator (C++)
 
A console-based **SGPA & CGPA Calculator** built in C++ that helps students calculate their Semester GPA (SGPA) and Cumulative GPA (CGPA) based on course grades and credit hours, following the standard 4.0 grading scale.
 
> 🎓 Developed as part of the **CodeAlpha C++ Programming Internship**.
 
---
 
## ✨ Features
 
- 📘 **Calculate SGPA** for a single semester (course-by-course, with grade + credit hours)
- 📗 **Calculate CGPA** directly from semester GPAs, across up to **8 semesters**
- 📙 **Combined SGPA + CGPA Calculator** — tracks every course per semester and rolls the results up into a running CGPA automatically
- 📖 Built-in **Help menu** explaining every option, the grading scale, and the formulas used
- 🔒 Input validation on grades, credit hours, course counts, and GPA values
---
 
## 🛠️ Tech Stack
 
| | |
|---|---|
| **Language** | C++ |
| **Concepts Used** | Object-Oriented Programming (Classes & Objects), Arrays of Objects, Functions, Loops, Input Validation |
| **Platform** | Windows (uses `<windows.h>`, `system("cls")`, `system("pause")`) |
 
---
 
## 📂 Project Structure
 
| Class / Function | Responsibility |
|---|---|
| `gpa` | Stores a single course's details — name, course number, grade, credit hours |
| `cgpa` | Stores a semester's summary — semester number, SGPA, total credits, total quality points |
| `Grade_table()` | Converts a letter grade into its grade point value |
| `show_gpa()` | Calculates GPA/SGPA as Total Quality Points ÷ Total Credit Hours |
| `GPA_Calculation()` | Menu option 2 — calculates SGPA for one semester |
| `CGPA_Calculation()` | Menu option 3 — calculates CGPA directly from entered semester GPAs (up to 8 semesters) |
| `GPA_and_SGPA_Calculation()` | Menu option 1 — full course-level tracking of SGPA per semester, rolling up into CGPA |
| `help()` | Displays instructions, grading scale, and formulas |
 
---
 
## 🎯 Grading Scale
 
| Grade | Points | Grade | Points |
|---|---|---|---|
| A | 4.0 | C+ | 2.3 |
| A- | 3.7 | C | 2.0 |
| B+ | 3.3 | C- | 1.7 |
| B | 3.0 | D+ | 1.3 |
| B- | 2.7 | D | 1.0 |
| | | F | 0.0 |
 
---
 
## 🧮 Formulas Used
 
```
Quality Points = Grade Point × Credit Hours
 
SGPA = Total Quality Points ÷ Total Credit Hours
 
CGPA = Total Quality Points (all semesters) ÷ Total Credit Hours (all semesters)
```
 
---
 
## ✅ Input Rules
 
| Field | Rule |
|---|---|
| Courses per semester | 1 – 12 |
| Credit hours per course | 1 – 4 |
| Semesters (CGPA mode) | Up to 8 |
| GPA (CGPA mode) | 0.0 – 4.0 |
| Grade | Must match the grading scale exactly (e.g. `A`, `B+`, `C-`) |
 
---
 
## 🖥️ How to Use
 
1. Run the program.
2. Choose an option from the main menu:
   - **1** — Calculate SGPA and CGPA (semester-by-semester, up to 8 semesters)
   - **2** — Calculate SGPA (single semester only)
   - **3** — Calculate CGPA (from already-known semester GPAs)
   - **4** — Help (view instructions, grading scale & formulas)
   - **5** — Exit
3. Enter courses, grades, and credit hours as prompted.
4. View your calculated SGPA / CGPA instantly.
---
 
## 👤 Author
 
**Danish**
Built as part of the **CodeAlpha C++ Programming Internship**.
 
---
 
