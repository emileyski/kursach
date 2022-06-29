#pragma once
#include <string>
#include "json.hpp"
#include <fstream>
#include <list>
#include "Admin.h"
using json = nlohmann::json;

public class RegController
{
public:
	std::string json_write_admin(Admin account)
	{
		std::string fileName = "adminAccounts.json";
		std::ifstream reader;
		std::ofstream writer;
		

		json jAccount;
		json jAccounts;

		jAccount["Name"] = account.name;
		jAccount["Login"] = account.login;
		jAccount["Password"] = account.password;

		reader.open(fileName);

		if (reader)
		{
			reader.open(fileName);
			reader >> jAccounts;
			reader.close();
			jAccounts.push_back(jAccount);


			writer.open(fileName);
			writer << jAccounts.dump();
			writer.close();
		}
		else
		{
			jAccounts.push_back(jAccount);


			writer.open(fileName);
			writer << jAccounts.dump();
			writer.close();

			
		}
		return jAccounts.dump();
	}
};
