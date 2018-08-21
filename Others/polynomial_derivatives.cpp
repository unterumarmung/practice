/*!
Task:
	Find a derivative of a polynomial. Polinomial can be "big",
	but powers are always non-negative. Both coefficients and powers are integers.
	The output must have no spaces. Also, output must be represented in descending order of monomial's powers,
	although the input may not satisfy this rule. The input can be provided with several monomials of the same power.
	Input-output examples are given in the test() function down below.
*/
#include <string>
#include <ctype.h> //isdigit()
#include <functional> //std::greater
#include <vector>
#include <sstream> //std::stringstream
#include <iostream>
#include <map>

/*!
* Simple conversion from an integer to a string representation of the number
* \param[in] number - the number to convert
* \return - needed string
*/
std::string int_to_str(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

/*!
* Get a string representation of a monomial's derivative based on its factor and power
* \param[in] factor - coefficient
* \param[in] power...
* \return - derivative
*/
std::string monomial_derivative(int factor, int power) {
	if (power == 1)
		//the monomial: 12*x -> derivative: 12
		return int_to_str(factor); 
	if (power == 2)
		//the monomial: 6*x^2 -> derivative: 12*x  
		return int_to_str(factor*power) + "*x";

	//other cases, e.g.: 
	//the monomial: 
	return int_to_str(factor*power) + "*x^" + int_to_str(power - 1);
}


std::string derivative(std::string polynomial) {
    std::string result = "";
    const char x = 'x';
    const char multiplication_sign = '*';
    const char power_sign = '^';
	const char minus_sign = '-';
    
    //the map from power of unique monomial to its actual factor, sorted in descending order
    std::map<int, int, std::greater<int>> factors;
    
    
    //parsing factors of every monomial
    size_t current_index = polynomial.find(x);
    bool possible = current_index != -1; //possible to extract another factor of x
    
    while (possible) {
        int current_factor = 0;
        int current_power = 0;
        
		//parsing a factor of the current monomial
        if (current_index > 0 && polynomial[current_index - 1] == multiplication_sign) {
			std::string factor_str;

			int end = current_index - 2;
			int begin = end;

			while (begin > -1 && isdigit(polynomial[begin])) 
				begin -= 1;
			begin += 1;

			int length = end - begin + 1;

			//considering possible negative sign of the factor
			if (begin != 0) {
				factor_str = polynomial.substr(begin - 1, length + 1); 
			} else {
				factor_str = polynomial.substr(begin, length);
			}

			current_factor = atoi(factor_str.c_str());
        } 
		else {
			//there's no multiplication sign => the factor is either 1 or -1
			if (current_index > 0 && polynomial[current_index - 1] == minus_sign)
				current_factor = -1;
			else
				current_factor = 1;
        }
        
		//parsing a power of the current monomial
		if (current_index < polynomial.length() - 1 && polynomial[current_index + 1] == power_sign) {
			std::string power_str;

			int begin = current_index + 2;
			int end = begin;

			while (end < polynomial.length() && isdigit(polynomial[end])) 
				end += 1;

			int length = end - begin + 1;

			power_str = polynomial.substr(begin, length);
			current_power = atoi(power_str.c_str());
		} 
		else {
			//there's no power sign => the power is only 1
			current_power = 1;
		}

		factors[current_power] += current_factor;

        current_index = polynomial.find(x, current_index + 1);
        possible = current_index != -1;
    }

	//getting the result for each unique monomial
	for (auto it = factors.begin(); it != factors.end(); ++it) {
		auto current_derivative = monomial_derivative((*it).second, (*it).first);

		if (current_derivative[0] != minus_sign && it != factors.begin()) 
			result += "+";
		result += current_derivative;
	}
    return result;
}


void test(std::ostream& out = std::cout) {
	std::vector<std::string> input = {
		std::string("x^2+x"),
		std::string("2*x^100+100*x^2"),
		std::string("x^10000+x+1"),
		std::string("-x^2-x^3"),
		std::string("x+x+x+x+x+x+x+x+x+x")
	};

	std::vector<std::string> output = {
		"2*x+1",
		"200*x^99+200*x",
		"10000*x^9999+1",
		"-3*x^2-2*x",
		"10"
	};

	for (size_t test_index = 0; test_index < input.size(); ++test_index) {
		auto current = derivative(input[test_index]);
		bool test_passed = current == output[test_index];

		out << "Test #" << test_index + 1 << std::endl;
		out << "Input: " << input[test_index] << std::endl;
		out << "Expected output: " << output[test_index] << std::endl;
		out << "Real output: " << current << std::endl;

		if (test_passed)
			out << "THE TEST HAS BEEN PASSED";
		else
			out << "THE TEST HAS NOT BEEN PASSED";

		out << std::endl << std::endl;
	}
}