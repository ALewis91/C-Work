#pragma once
#include <string>

class Entry
{
private:
	int ht;
	std::string _areaCode;
	int _population;
	std::string _areaName;
public:
	Entry(const int& ac, const int& p, const std::string &name)
	{
		_areaCode = ac;
		_population = p;
		_areaName = name;
	}
	Entry()
	{
		ht = 0;
		_areaCode = "";
		_population = 0;
		_areaName = "";
	}
	const int height() const { return ht; }
	void setHeight(int h) { ht = h; }
	const std::string areaCode() const { return _areaCode; }
	const int population() const { return _population; }
	const std::string areaName() const { return _areaName; }
	void setCode(const std::string& ac) { _areaCode = ac; }
	void setPopulation(const int p) { _population = p; }
	void setAreaName(const std::string& an) { _areaName = an; }
};
