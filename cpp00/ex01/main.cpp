/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aauberti <aauberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:32:29 by aauberti          #+#    #+#             */
/*   Updated: 2025/02/24 19:19:20 by aauberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            return ("");
    } while (input.empty());
    return (input);
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "EXIT")
            break;
        else if (command == "ADD") {
            Contact newContact;
            std::string firstName = getInput("Enter first name: ");
            if (firstName.empty())
                break;
            std::string lastName = getInput("Enter last name: ");
            if (lastName.empty())
                break;
            std::string nickname = getInput("Enter nickname: ");
            if (nickname.empty())
                break;
            std::string phoneNumber;
            do {
                phoneNumber = getInput("Enter phone number: ");
                if (phoneNumber.empty())
                    break;
                if (!Contact::isValidPhoneNumber(phoneNumber))
                    std::cout << "Invalid phone number! Please use only digits and spaces" << std::endl;
            } while (!Contact::isValidPhoneNumber(phoneNumber));
            std::string darkestSecret = getInput("Enter darkest secret: ");
            if (darkestSecret.empty())
                break;
            newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        }
    }
    return (0);
}


