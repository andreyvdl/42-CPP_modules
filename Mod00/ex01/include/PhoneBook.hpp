/**
 * @file PhoneBook.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Header contains the class PhoneBook.
 * @version 1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		static size_t _nbrOfContactsAdded;
	
	public:
		/**
		 * @brief Construct a new PhoneBook object.
		 */
		PhoneBook(void);

		/**
		 * @brief Destroy a PhoneBook object.
		 */
		~PhoneBook(void);

		/**
		 * @brief Get the Contact object in the given index.
		 * 
		 * @param idx The index position of the Contact object.
		 * @return The Contact object in the given index.
		 */
		Contact* getContact(unsigned short int idx) const;

		/**
		 * @brief Add a new info of the Contact to the PhoneBook.
		 */
		void addContact(void);

		/**
		 * @brief Print all Contacts and prompts the user to choose one.
		 */
		void searchContact(void);
};

#endif
