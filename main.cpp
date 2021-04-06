#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

double division(double const &a, double const &b) {
    if (b == 0)
        throw std::invalid_argument("Division by zero");
    else
        return a / b;

}

int main() {
    double a = 0;
    double b = 0;
    std::cout << "Enter a: " << std::endl;
    std::cin >> a;
    std::cout << "Enter b: " << std::endl;
    std::cin >> b;
    try {
        std::cout << "a / b =  " << division(a, b) << std::endl;
    }
    catch (const std::exception &ia) {
        std::cout << ia.what() << std::endl;
    }

//------------------------------------------------------------

    std::string testString = "shookOnes";
    std::cout << "Enter index to access character" << std::endl;
    int index;
    std::cin >> index;
    try {
        if (index > testString.length()) throw std::out_of_range("Out of range");
        std::cout << testString[index] << std::endl;
    }
    catch (const std::out_of_range &oor) {
        std::cout << oor.what() << std::endl;
    }

//------------------------------------------------------------

    try {
        // vector throws a length_error if resized above max_size
        std::vector<int> my_vector;
        my_vector.resize(my_vector.max_size()+1);
    }
    catch (const std::length_error& le) {
        std::cerr << le.what() << std::endl;
    }

//------------------------------------------------------------

    class Parent {virtual void member(){}};
    class Son : Parent {};


        try
        {
            Parent p;
            Son& s = dynamic_cast<Son&>(p);
        }
        catch (std::bad_cast& bc)
        {
            std::cerr << "bad_cast caught: " << bc.what() << std::endl;
        }
//------------------------------------------------------------

    try {
        while (true) {
            new int[100000000ul];
        }
    } catch (const std::bad_alloc& ba) {
        std::cout << "Allocation failed: " << ba.what() << std::endl;
    }


    return 0;
}