#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <unordered_map>

class CompressorStation
{
private:
	static int maxId;
	int id = 0;
	std::string name;
	int totalWorkshops = 0;
	int operatingWorkshops = 0;
	int efficiency = 0;

public:
	//inline 
	int GetId() const { return id; }
	std::string GetName() const { return name; }
	int GetWorkhops() const { return totalWorkshops; }
	int GetWorkingWorkhops() const { return operatingWorkshops; }
	int GetPercent() const {
		return (totalWorkshops > 0) ? (totalWorkshops - operatingWorkshops) * 100 / totalWorkshops : 0;
	}

	void EditWorkingWorkshops(const char sign);


	friend std::ifstream& operator >> (std::ifstream& fin, CompressorStation& s);
	friend std::ofstream& operator << (std::ofstream& fout, const CompressorStation& s);

	friend std::istream& operator >> (std::istream& in, CompressorStation& s);
	friend std::ostream& operator << (std::ostream& out, const CompressorStation& s);

};
