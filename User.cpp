#include "User.h" 

void User::registerUser(std::string userName, std::string password)
{
	userList.open("userList.txt", std::fstream::out | std::fstream::app);
	userList << userName << " ";
	userList << password;
	userList << "\n";
	userList.close();
}

void User::login(std::string inUserName, std::string inPassword)
{
	authenticate.open("userList.txt");

	if (authenticate)
	{
		while (std::getline(authenticate, userName, ' ') && (std::getline(authenticate, password)))
		{
			if (userName == inUserName && password == inPassword)
			{
				std::cout << "\n\nUser found\n\n";
				system("PAUSE");
				system("CLS");
				break;
			}
		}
		if (userName != inUserName || password != inPassword)
		{
			std::cout << "\nLogin failed\n\n";
			system("PAUSE");
			system("CLS");
		}
	}
}