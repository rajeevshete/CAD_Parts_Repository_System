README – CAD Parts Repository System

This project is a console-based CAD Parts Repository System written in C++. 
It allows users to add, view, search, sort, and delete different types of CAD parts such as pipes, valves, elbows, and flanges. 
All parts share common properties through a base class, and specific part types are created using inheritance.

The program uses smart pointers to manage memory safely and avoid leaks. 
STL vectors store the parts, and algorithms are used for searching and sorting. 
Operator overloading is implemented where needed, and templates are used to make certain components generic. 
Basic exception handling is included, for example when users enter invalid values such as negative dimensions.

The system works through a simple menu in the console, making it easy to interact with. 
The design is modular and can be extended easily by adding new part types or additional features.
