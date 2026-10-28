// Astudillo, Thomas Joseph T.
// CPE21S2
#include <iostream>


float toFahrenheit(float Kelvin) {
    return ((Kelvin - 273.15)*9/5)+ 32;
}

int main() {
    float Kelvin;

    std::cout << "--- Kelvin to Fahrenheit Converter ---" << std::endl;

    std::cout << "Please Enter Temperature in Kelvins (*K): ";
    std::cin >> Kelvin;

    std::cout << "Your temperature in From Kelvin to Fahrenheit is: " << toFahrenheit(Kelvin) << std::endl;
}