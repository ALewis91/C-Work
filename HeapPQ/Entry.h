#pragma once
#include <string>
class Entry 
{				
private:						// private data
	int _key;						// key
	std::string _value;					// value
public:		
	Entry(const int& k, const std::string &v)	// constructor
	{
		_key = k;
		_value = v;
	}
	const int key() const { return _key; }		// get key
	const std::string value() const { return _value; }	// get value
	void setKey(const int& k) { _key = k; }		// set key
	void setValue(const std::string& v) { _value = v; }	// set value

};
