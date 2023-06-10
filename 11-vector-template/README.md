# Vector Arithmetic and Sorting

This program is designed to perform operations on mathematical vectors and sort them in a specific order. It utilizes the capabilities of C++ templates and operator overloading to create a robust and flexible tool for vector manipulation.

It's an illustrative example of how to leverage templates and operator overloading.

## Main Features:

- **Determining the Maximum**: The template function allows you to identify the greater of two values.
- **Array Sorting**: A simple implementation of the bubble sort algorithm that can sort arrays of any data type in descending order.
- **Vector Class**: The core of this project is the templated Vector class which allows you to create vectors of any length and data type. This class has built-in methods to support addition of vectors (operator+), accessing individual components (operator[]), and converting a vector to its magnitude (operator float).
- **Vector Addition**: When you add two vectors together using the + operator, the program returns a new vector whose components are the sum of the corresponding components of the input vectors.
- **Components Access**: You can directly access and modify individual components of a vector.
- **Float Conversion**: When a vector is converted to float, it returns the vector's magnitude, which is the square root of the sum of the squares of its components.
- **Vector Operations**: In the main function, the program demonstrates the usage of the Vector class by creating and manipulating 4-dimensional integer vectors. The vectors are added together, printed, and converted to their magnitudes. Then, an array of vectors is sorted in descending order of their magnitudes.
