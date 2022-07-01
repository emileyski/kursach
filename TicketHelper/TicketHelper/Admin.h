#pragma once
#include <string>
using namespace std;
public class Admin
{
public:
	string name, login, password;
	Admin()
	{

	}
	Admin(std::string _name, std::string _login, std::string _password)
	{
		name = _name;
		login = _login;
		password = _password;
		
	}

};


