#pragma once
#include <string>
#include <fstream>
#include "Theatre.h"
#include "json.hpp"

using json = nlohmann::json;
class Date
{
public:
	int day, month, year;
	Date()
	{

	}
	Date(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}
};

class Time
{
public:
	int hour, minute;
	Time()
	{

	}
	Time(int _hour, int _minute)
	{
		hour = _hour;
		minute = _minute;
	}
};

public class Event
{
public:
	Event(std::string _title, Date _date, Time _time)
	{
		title = _title;
		date = _date;
		time = _time;
		json_write_event();
	}
	std::string json_write_event()
	{
		const string fileName = "Events.json";

		std::ifstream reader;
		std::ofstream writer;

		json jEvents;
		json jEventInfo;

		jEventInfo["Title"] = title;

		jEventInfo["Date"].push_back(date.day);
		jEventInfo["Date"].push_back(date.month);
		jEventInfo["Date"].push_back(date.year);

		jEventInfo["Time"].push_back(time.hour);
		jEventInfo["Time"].push_back(time.minute);


		reader.open(fileName);

		if (reader)
		{
			reader >> jEvents;
			reader.close();
			jEvents.push_back(jEventInfo);


			writer.open(fileName);
			writer << jEvents.dump();
			writer.close();
		}
		else
		{
			jEvents.push_back(jEventInfo);


			writer.open(fileName);
			writer << jEvents.dump();
			writer.close();
		}

		return jEvents.dump();
	}
	Date date;

	Time time;

	std::string title;

	Theatre theatre;

};

