#pragma once
#include "RegForm.h"
public class Admin
{
	
	std::string name;
	std::string login;
	std::string password;
	Admin(String^ _name, String^ _login, String^ _password)
	{
		name = _name;
		login = _login;
		password = _password;
	}
};
