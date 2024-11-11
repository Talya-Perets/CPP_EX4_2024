This repository contains the solution for Exercise 4 of my C++ course, focusing on implementing graph algorithms, Euler Circuits, and various memory management techniques. The project demonstrates my ability to implement core C++ concepts, handle graphs, and utilize various development tools such as Valgrind for memory management analysis.

Features
Graph Data Structure: Implementation of a graph using adjacency lists.
Euler Circuit Algorithm: Algorithm to find Eulerian circuits in the graph.
Random Graph Generation: Tools to generate random graphs with customizable parameters.
Memory Management: Analysis and memory leak detection using Valgrind.
Thread Safety: Implementation of a Singleton pattern and a Guard class using mutex locking for thread safety.
Files
Graph.cpp, Graph.hpp: Contains the graph data structure and functions for finding Euler circuits.
main.cpp: Demonstrates the use of the graph and algorithms.
Makefile: For building the project.
guard.cpp, singleton.cpp: Implements thread-safe classes.
test.cpp: (optional) Unit tests for ensuring the functionality of the implemented algorithms.
Getting Started
Prerequisites
Make sure you have the following installed:

C++ Compiler (e.g., g++)
Valgrind for memory management testing
Building the Project
To build the project, run the following command:

go
Copy code
make
This will compile the project files as per the Makefile.

Running the Program
To run the program after building:

bash
Copy code
./main
Testing
To test the program using Valgrind for memory leaks:

css
Copy code
valgrind --leak-check=full ./main
This will provide memory leak analysis during runtime.



