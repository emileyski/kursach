#pragma once
#include <string>
#include "json.hpp"
#include <fstream>
#include <list>
#include "Admin.h"
#include "Visitor.h"

using json = nlohmann::json;

public class RegController
{
public:
	std::string json_write(Admin admin)
	{
		std::string fileName = "adminAccounts.json";
		std::ifstream reader;
		std::ofstream writer;
		

		json jAccount;
		json jAccounts;

		jAccount["Name"] = admin.name;
		jAccount["Login"] = admin.login;
		jAccount["Password"] = admin.password;

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
	std::string json_write(Visitor visitor)
	{
		std::string fileName = "visitorAccounts.json";
		std::ifstream reader;
		std::ofstream writer;


		json jAccount;
		json jAccounts;

		jAccount["Name"] = visitor.name;
		jAccount["Login"] = visitor.login;
		jAccount["Password"] = visitor.password;

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
