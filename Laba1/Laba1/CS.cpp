#include "CSclass.h"
#include "Functions.h"
using namespace std;

int CompressorStation::maxId = 0;

//CompressorStation::CompressorStation()
//{
//    id = 0;
//    Name = "None";
//    AmountOfWorkshops = 0;
//    WorkshopsInWork = 0;
//    EfficiencyLevel = 0;
//}

ifstream& operator >> (ifstream& fin, CompressorStation& s)
{
    fin >> s.id;
    s.maxId = s.id;
    fin >> ws;
    getline(fin, s.name);
    fin >> s.totalWorkshops;
    fin >> s.operatingWorkshops;
    fin >> s.efficiency;

    return fin;
}

ofstream& operator << (ofstream& fout, const CompressorStation& s)
{
    if (s.name != "None")
    {
        fout << s.id << endl
            << s.name << endl
            << s.totalWorkshops << endl
            << s.operatingWorkshops << endl
            << s.efficiency << endl;
    }
    return fout;
}

istream& operator >> (istream& in, CompressorStation& s)
{
    s.id = ++s.maxId;
    cout << "Enter compressor station name: ";
    INPUT_LINE(in, s.name);

    cout << "Enter amount of compressor station workshops: ";
    s.totalWorkshops = GetCorrectNumber(1, 90);

    cout << "Enter amount of working compressor station workshops: ";
    s.operatingWorkshops = GetCorrectNumber(0, s.totalWorkshops);

    cout << "Enter effeciency level of compressor station: ";
    s.efficiency = GetCorrectNumber(0, 100);

    return in;
}

ostream& operator << (ostream& out, const CompressorStation& s)
{
    out << "ID: " << s.id << endl
        << "Compressor station name: " << s.name << endl
        << "Amount of compressor station workshops: " << s.totalWorkshops << endl
        << "Amount of working compressor station workshops: " << s.operatingWorkshops << endl
        << "Effeciency level of compressor station: " << s.efficiency << "%" << endl
        << "\n";
    return out;
}


void CompressorStation::EditWorkingWorkshops(const char sign)
{
    if (sign == '+' && operatingWorkshops + 1 <= totalWorkshops)
        operatingWorkshops += 1;
    else if (sign == '-' && operatingWorkshops - 1 >= 0)
        operatingWorkshops -= 1;
}

//int CompressorStation::GetId()
//{
//    return id;
//}
//
//string CompressorStation::GetName()
//{
//    return name;
//}
//
//int CompressorStation::GetWorkhops()
//{
//    return totalWorkshops;
//}
//
//int CompressorStation::GetWorkingWorkhops()
//{
//    return operatingWorkshops;
//}
//
//int CompressorStation::GetPercent()
//{
//    return (totalWorkshops - operatingWorkshops) * 100 / (totalWorkshops);
//}