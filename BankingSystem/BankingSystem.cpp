#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>



static const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char* p_alphabet = alphabet;

class bank
{
protected:
	double balance = 0;
	std::vector <std::string> clients_numbers_vector;


public:
	std::string generate_numbers(const char* pointer_to_alphabet)
	{
		std::string client_number = "";
		std::random_device rd;
		std::mt19937 gen(rd());
		for (int i = 0; i < 9; i++)
		{

			std::uniform_int_distribution<> distrib(0, 36);
			unsigned short number = distrib(gen);
			client_number += pointer_to_alphabet[number];
		}

		return client_number;
	};
};


//IMPLEMENT UUID AS CLIENT NUMBER

class client : bank
{
private:
	std::string client_number;
	std::string pin;
public:
	double balance;
	bool debt;
	bool PIN_verification(const std::string* pin)
	{
		if (pin->size() != 4)
		{
			return false;
		}
		return std::all_of(pin->begin(), pin->end(), ::isdigit);
	};
	client()
	{
		balance = 0;
		debt = 0;
		do
		{
			client_number = generate_numbers(p_alphabet);


		} while (std::find(clients_numbers_vector.begin(), clients_numbers_vector.end(), client_number) != clients_numbers_vector.end());
		do
		{	
			std::cin.clear();
			std::cout << "Type in Your PIN of choice: ";
			std::cin >> pin;
		} while(!PIN_verification(&pin));
		std::cout << "PIN accepted!"<<std::endl;


		


	}
};
int main()
{
	//client a;
	/*std::cout << p_alphabet << std::endl;*/
	client a;

}

