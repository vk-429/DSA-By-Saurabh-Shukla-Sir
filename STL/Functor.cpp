#include <iostream>
#include <vector>
#include <algorithm>

// Define the functor
class MultiplyBy {
public:
    MultiplyBy(int factor) : factor(factor) {}
    
    // Overload the function call operator
    int operator()(int x) const {
        return x * factor;
    }
    
private:
    int factor;
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int factor = 3;
    
    // Create an instance of the functor
    MultiplyBy multiplyByFactor(factor);
    
    // Apply the functor to each element in the vector
    std::transform(vec.begin(), vec.end(), vec.begin(), multiplyByFactor);
    
    // Print the transformed vector
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


// Functors, also known as function objects, are objects that 
// can be called as if they are a function or function pointer.
// In C++ STL (Standard Template Library), functors provide a 
// way to define objects that can be invoked as functions. 
// This is useful because functors can maintain state and 
// can be more versatile than regular functions.

// Defining Functors

// A functor is created by defining a class or struct with 
// the operator() method. This method makes instances of 
// the class callable like a function.

