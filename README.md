Final Project 2023
the Project written in C++.

Background :

The size of the smallest k-regular graph of girth g is denoted by the 
function n(k, g).

In the project I focused on a variant of the problem with the function n(H2,3 , g).
The girth of a graph is the length of its shortest cycle.

* Reminder *
H2,3 - half of the vertices are of degree 2 and half are of degree 3

The Algorithm:

Exhaustive search on all graphs given n, g.
Start with a graph whose vertices are all degree 2, and add edges between even vertices that will be of degree 3.
Graph whose vertices are all degree 2 => graph of cycles.

Part 1:
Partition vertex 0...n-1 to cycles, each with even length and minimal length >=g
