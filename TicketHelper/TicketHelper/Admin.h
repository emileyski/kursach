#pragma once
#include <string>
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;
public class Admin
{

	std::string name;
	std::string login;
	std::string password;
public:
	Admin(std::string _name, std::string _login, std::string _password)
	{
		name = _name;
		login = _login;
		password = _password;
		json_write(login);
	}
	std::string json_write(std::string accountLogin)
	{
		json j;
		j.push_back(name);
		j.push_back(login);
		j.push_back(password);
		json jj;
		jj[accountLogin] = j;

		std::ofstream writer;
		writer.open("adminAccounts.json");
		writer << jj.dump(3);
		writer.close();
		return jj.dump(3);
	}
};


