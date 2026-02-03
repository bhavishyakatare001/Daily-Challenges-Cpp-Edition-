#  Reinventing the Wheel

> *"What I cannot create, I do not understand"* — **Richard Feynman**

##  The Philosophy
In modern software engineering, we stand on the shoulders of giants. We use Python Lists, C++ STL Vectors, and high-level libraries.

**This directory is the exception.**

Here, I deliberately strip away the "magic" of standard libraries (STL) to build core data structures from scratch. The goal is to build the **mental models** required to be a high-level engineer.

##  The Rules
1.  **No STL Containers:** No `#include <vector>`, `<set>`, or `<map>`.
2.  **Raw Memory Only:** Arrays and manual logic are the standard.
3.  **First Principles:** If a function exists in a library, I must implement the logic manually.

##  Project Directory

| Project Name | Concept Explored | Logic Used | Status |
| :--- | :--- | :--- | :--- |
| **[Cpp-manual-set](./cpp-manual-set)** | **The Set**: Uniqueness, Encapsulation | Linear Search (Loop) | ✅ Completed |
