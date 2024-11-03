#include "PIPEclass.h"
#include "Functions.h"
using namespace std;

int Pipe::currentMaxId = 0;

ifstream& operator>>(ifstream& fin, Pipe& p) {
    fin >> p.id;
    if (p.id > Pipe::currentMaxId) {
        Pipe::currentMaxId = p.id; // Update maxId only if the current ID is larger
    }
    fin >> ws;
    getline(fin, p.name);
    fin >> p.length;
    fin >> p.diameter;
    fin >> p.isUnderRepair;

    return fin;
}

ofstream& operator<<(ofstream& fout, const Pipe& p) {
    if (p.name != "None") {
        fout << p.id << endl
            << p.name << endl
            << p.length << endl
            << p.diameter << endl
            << p.isUnderRepair << endl;
    }
    return fout;
}

istream& operator>>(istream& in, Pipe& p) {
    p.id = ++Pipe::currentMaxId;
    cout << "Enter pipe name: ";
    INPUT_LINE(in, p.name);

    cout << "Enter pipe length: ";
    p.length = GetCorrectNumber(100, 1500);

    cout << "Enter pipe diameter: ";
    p.diameter = GetCorrectNumber(200, 700);

    cout << "Is the pipe under repair? (1 - Yes, 0 - No): ";
    p.isUnderRepair = GetCorrectNumber(0, 1);

    return in;
}

ostream& operator<<(ostream& out, const Pipe& p) {
    out << "ID: " << p.id << endl
        << "Pipe name: " << p.name << endl
        << "Pipe length: " << p.length << endl
        << "Pipe diameter: " << p.diameter << endl
        << "State: " << (p.isUnderRepair ? "Under repair" : "Working") << endl;
    return out;
}

void Pipe::EditPipeInRepair() {
    isUnderRepair = !isUnderRepair;  // Toggle the InRepair state
}
