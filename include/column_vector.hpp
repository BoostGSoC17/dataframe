/**Boost GSoC '17
  *column_vector version-1.0
  *convert all data to std::string
*/

#ifndef _COLUMN_VECTOR_HPP
#define _COLUMN_VECTOR_HPP

#include <iostream>
#include <string>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/lexical_cast.hpp>
using namespace boost::numeric::ublas;	

class column_vector {
public:

	/* constructors */
	/* default: no parameters */
	column_vector() {}
	
	/* paramters: name, ublas::vector<int> */ 
	column_vector(std::string name, vector <int> x) {
		name = name;
		column_data.resize(x.size());
		for(size_t i = 0; i < x.size(); i++)
			column_data(i) = boost::lexical_cast<std::string>(x(i));
		type = "int";
	}

	/* paramters: name, ublas::vector<double> */
	column_vector(std::string name, vector <double> x) {
		name = name;
		column_data.resize(x.size());
		for(size_t i = 0; i < x.size(); i++)
			column_data(i) = boost::lexical_cast<std::string>(x(i));
		type = "double";	
	}

	/* paramters: name, ublas::vector<string> */
	column_vector(std::string name, vector <std::string> x) {
		name = name;
		column_data.resize(x.size());
		for(size_t i = 0; i < x.size(); i++)
			column_data(i) = x(i);	
		type = "string";
	}

	size_t size() {
		return column_data.size();
	}
	std::string getname() {
		return name; 
	}

	void print_info() {
		std::cout << "Type: " << type << ' ' << "Name:" << name << '\n';
		std::cout << "Vector Values:" << '\n';
		for(auto x: column_data) std::cout << x << ' ';
		std::cout << '\n';
		return;
	}

private:
	std::string type, name;
	vector <std::string> column_data;	
};

#endif