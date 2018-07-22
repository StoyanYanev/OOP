#pragma once

Bank bank("Fibank", "ul. Moskovska 19 Sofia");
int customerId;
std::string iban;

void DisplayMenu();
void GetInputFromMenu(int digit);

void DisplayMenu()
{
	std::cout << "*******************Menu*******************" << std::endl;
	std::cout << "1    " << "List customers" << std::endl;
	std::cout << "2    " << "Add new customer" << std::endl;
	std::cout << "3    " << "Delete customer" << std::endl;
	std::cout << "4    " << "List all accounts" << std::endl;
	std::cout << "5    " << "List customer accounts" << std::endl;
	std::cout << "6    " << "Add new account" << std::endl;
	std::cout << "7    " << "Delete account" << std::endl;
	std::cout << "8    " << "Withdraw from account" << std::endl;
	std::cout << "9    " << "Deposit to account" << std::endl;
	std::cout << "10    " << "Transfer" << std::endl;
	std::cout << "11    " << "Display info for the bank" << std::endl;
	std::cout << "12    " << "Quit" << std::endl;
	std::cout << "Your choice is: ";
}

void GetInputFromMenu(int digit)
{
	switch (digit)
	{
	case 1:
		bank.ListCustomers();
		break;
	case 2:
	{
		std::string name;
		std::string address;
		int id;

		std::cout << "Enter the id of the customer: ";
		std::cin >> id;
		std::cout << "Enter the name of the customer: ";
		std::cin >> name;
		std::cout << "Enter the address of the customer: ";
		std::cin >> address;

		bank.AddCustomer(id, name, address);
		break;
	}
	case 3:
	{
		std::cout << "Enter the id of the customer who you want to delete: ";
		std::cin >> customerId;
		bank.DeleteCustomer(customerId);
		break;
	}
	case 4:
		bank.ListAccounts();
		break;
	case 5:
	{
		std::cout << "Enter the id of the customer to see his accounts: ";
		std::cin >> customerId;
		bank.ListCustomerAccounts(customerId);
		break;
	}
	case 6:
	{
		int typeOfAccount;
		int ownerId;
		double amount;

		std::cout << "Choose type of account!" << std::endl;
		std::cout << "1. Current Account" << std::endl;
		std::cout << "2. Savings Account" << std::endl;
		std::cout << "3. Pivilege Account" << std::endl;
		std::cout << "Your choose is: ";
		std::cin >> typeOfAccount;

		if (typeOfAccount > 0 && typeOfAccount <= 3)
		{
			std::cout << "Enter the id of the owner: ";
			std::cin >> ownerId;
			std::cout << "Enter the iban of the owner: ";
			std::cin >> iban;
			std::cout << "Enter the amount of the owner: ";
			std::cin >> amount;
		}
		switch (typeOfAccount)
		{
		case 1:
			bank.AddAccount("current", iban, ownerId, amount);
			break;
		case 2:
			bank.AddAccount("savings", iban, ownerId, amount);
			break;
		case 3:
			bank.AddAccount("privilege", iban, ownerId, amount);
			break;
		default:
			std::cout << "Invalide input!";
			break;
		}
		break;
	}
	case 7:
	{
		std::cout << "Enter the iban of the owner who you want to delete: ";
		std::cin >> iban;
		bank.DeleteAccount(iban);
		break;
	}
	case 8:
	{
		std::cout << "Enter the iban of the account that you want to withdraw from: ";
		std::cin >> iban;
		double sum;
		std::cout << "Enter the sum that you want to withdraw: ";
		std::cin >> sum;
		bank.WithdrawFromAccount(iban, sum);
		break;
	}
	case 9:
	{
		std::cout << "Enter the iban of the account that you want to deposit to: ";
		std::cin >> iban;
		double sum;
		std::cout << "Enter the sum that you want to deposit: ";
		std::cin >> sum;
		bank.DepositToAccount(iban, sum);
		break;
	}
	case 10:
	{
		std::string fromIBAN;
		std::string toIBAN;
		double sum;

		std::cout << "Enter the iban of the account that you want to transfer from: ";
		std::cin >> fromIBAN;
		std::cout << "Enter the iban of the account that you want to transfer to: ";
		std::cin >> toIBAN;
		std::cout << "Enter the sum that you want to transfer: ";
		std::cin >> sum;
		bank.Transfer(fromIBAN, toIBAN, sum);
		break;
	}
	case 11:
		bank.Display();
		break;
	case 12:
		exit(0);
		break;
	default:
		std::cout << "Invalide input!";
		break;
	}
}