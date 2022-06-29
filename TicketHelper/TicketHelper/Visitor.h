#pragma once
#include <string>
using namespace std;
public class Visitor
{
public:
	string name, login, password;

	Visitor(string _name, string _login, string _password)
	{
		name = _name;
		login = _login;
		password = _password;
	}
};
