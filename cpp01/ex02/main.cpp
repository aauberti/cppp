/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aauberti <aauberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:50:10 by aauberti          #+#    #+#             */
/*   Updated: 2025/02/25 08:16:37 by aauberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "\nMemory address\n" << "Address str:       " << &str << "\n"
			<< "Address stringPTR: " << stringPTR << "\n"
			<< "Address stringREF: " << &stringREF << std::endl;

	std::cout << "\nValue\n" << "Value str =       " << str << "\n"
			<< "Value stringPTR = " << *stringPTR << "\n"
			<< "Value stringREF = " << stringREF << std::endl;
}
