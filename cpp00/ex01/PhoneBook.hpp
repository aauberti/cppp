/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aauberti <aauberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:32:35 by aauberti          #+#    #+#             */
/*   Updated: 2025/02/25 11:41:55 by aauberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;
    void displayContactList() const;
    void displayContact(int index) const;
    
public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContact() const;
};