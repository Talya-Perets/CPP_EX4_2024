#include <iostream>
#include <string>

using std::ostream;
using std::string;


class Complex {
   private:
    double real;
    double imag;

   public:
    Complex(double real, double imag);

    double getReal();

    double getImag();

    
    bool operator==(const Complex &other) const;

   
    string to_str() const;

  
    bool operator<(const Complex &other);

    friend ostream &operator<<(ostream &os, const Complex &complex);
};

//Converts a complex number to a string. (overload the std::to_string function for Complex class)
string to_string(const Complex &complex);