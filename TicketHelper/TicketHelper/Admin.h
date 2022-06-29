#pragma once
#include <string>
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;
public class Admin
{
public:
	std::string name;
	std::string login;
	std::string password;
	Admin(std::string _name, std::string _login, std::string _password)
	{
		name = _name;
		login = _login;
		password = _password;
		
	}

};


