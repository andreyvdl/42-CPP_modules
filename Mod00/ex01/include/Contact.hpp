/**
 * @file Contact.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Header contains the Contact class.
 * @version 1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
		std::wstring _firstName;
		std::wstring _lastName;
		std::wstring _nickname;
		std::wstring _phoneNumber;
		std::wstring _darkestSecret;
		static int  _constructorCalls;

	public:
		/**
		 * @brief Construct a new Contact object.
		 */
		Contact(void);
		/**
		 * @brief Destroy the Contact object.
		 */
		~Contact(void);

		/**
		 * @brief Set the _firstName member.
		 * 
		 * @param firstName the string to be place in _firstName.
		 */
		void setFirstName(std::wstring firstName);
		/**
		 * @brief Get the _firstName member.
		 * 
		 * @return _firstName.
		 */
		std::wstring getFirstName(void) const;

		/**
		 * @brief Set the _lastName member.
		 * 
		 * @param lastName the string to be place in _lastName.
		 */
		void setLastName(std::wstring lastName);
		/**
		 * @brief Get the _lastName member.
		 * 
		 * @return _lastName.
		 */
		std::wstring getLastName(void) const;

		/**
		 * @brief Set the _nickname member.
		 * 
		 * @param nickname the string to be place in _nickname.
		 */
		void setNickname(std::wstring nickname);
		/**
		 * @brief Get the _nickname member.
		 * 
		 * @return _nickname.
		 */
		std::wstring getNickname(void) const;

		/**
		 * @brief Set the _phoneNumber member.
		 * 
		 * @param phoneNumber the string to be place in _phoneNumber.
		 */
		void setPhoneNumber(std::wstring phoneNumber);
		/**
		 * @brief Get the _phoneNumber member.
		 * 
		 * @return _phoneNumber.
		 */
		std::wstring getPhoneNumber(void) const;

		/**
		 * @brief Set the _darkestSecret member.
		 * 
		 * @param darkestSecret the string to be place in _darkestSecret.
		 */
		void setDarkSecret(std::wstring darkestSecret);
		/**
		 * @brief Get the _darkestSecret member.
		 * 
		 * @return _darkestSecret.
		 */
		std::wstring getDarkSecret(void) const;
};

#endif
