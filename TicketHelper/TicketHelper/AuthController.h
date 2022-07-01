#pragma once
#include <string>
#include "json.hpp"
#include <fstream>
#include "Admin.h"
#include "Visitor.h"
using json = nlohmann::json;

public class AuthController
{
public:
	Admin admin;
	bool Authorization(std::string login, std::string password)
	{
		json jAccounts;

		std::string fileName = "adminAccounts.json";
		ifstream reader;
		reader.open(fileName);
		reader >> jAccounts;
		int iter = 0;
		for (json::iterator i = jAccounts.begin(); i != jAccounts.end(); ++i, iter++) {
			if (jAccounts[iter]["Login"] == login && jAccounts[iter]["Password"] == password)
			{
				admin.login = jAccounts[iter]["Login"];
				admin.name = jAccounts[iter]["Name"];
				admin.password = jAccounts[iter]["Password"];
				reader.close();
				return true;
			}
		}
		reader.close();
		return false;

		
	}
};
