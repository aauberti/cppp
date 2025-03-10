#ifndef SCALARCONVERTER_HPP
# define SCALARCOVERTER_HPP

# include <string>

class ScalarConverter {
	private:
		static void convert(std::string& str);
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		
		ScalarConverter& operator=(const ScalarConverter& other);
	};

#endif