/*
	Substitution Cipher

	A simple and very old method of sending secret messages is the substitute cipher.
	You might have used this cipher with your friends when you were a kid.
	Basiically, each letter of the alphabet gets replaced by another letter of the alphabet.
	For example, every 'a' gets replaced with an 'X', and every 'b' gets replaced with a 'Z', ect.

	Write a program that asks a user to enter a secret message.

	Encrypt this message using the substitution cipher and display the encrypted message.
	Then decrypt the encrypted message back to the original message.
*/

//

#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	std::string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	std::string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

	std::string message{};

	std::cout << "******************************" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "**          C1PH3R          **" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "\nWelcome to C1PH3R" << std::endl;
	std::cout << "Please enter the message you would like to encrypt: ";
	std::getline(std::cin, message);

	// --------------
	// --Encryption--
	// --------------
	for (size_t i{ 0 }; i < message.length(); i++)
	{
		int index_in_alphabet = alphabet.find(message.at(i));

		if (index_in_alphabet != std::string::npos)
		{
			std::string key_letter{};
			key_letter.insert(0, key, index_in_alphabet, 1);
			message.replace(i, 1, key_letter);
		}
	}

	std::cout << "\nEncrypting message..." << std::endl;
	std::cout << "\nYour encrypted message is: " << message << std::endl;

	// --------------
	// --Decryption--
	// --------------
	for (size_t i{ 0 }; i < message.length(); i++)
	{
		int index_in_key = key.find(message.at(i));

		if (index_in_key != std::string::npos)
		{
			std::string alphabet_letter{};
			alphabet_letter.insert(0, alphabet, index_in_key, 1);
			message.replace(i, 1, alphabet_letter);
		}
	}

	std::cout << "\nDecrypting message..." << std::endl;
	std::cout << "\nYour decrypted message is: " << message << std::endl;
}