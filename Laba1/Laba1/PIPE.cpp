#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>

class Pipe
{
private:
    /*static int currentMaxId;
    int id = 0;*/
    std::string name = "None";
    int length = 0;
    int diameter = 0;
    bool isUnderRepair = false;

public:
    // can add explicit in front, 
    Pipe() = default;

    // Getters (inline)
    int GetId() const { return id; }
    std::string GetName() const { return name; }
    bool GetStatement() const { return isUnderRepair; }

    // Modifiers
    void EditPipeInRepair();

    // Friend function declarations for file and console I/O
    friend std::ifstream& operator>>(std::ifstream& fin, Pipe& p);
    friend std::ofstream& operator<<(std::ofstream& fout, const Pipe& p);
    friend std::istream& operator>>(std::istream& in, Pipe& p);
    friend std::ostream& operator<<(std::ostream& out, const Pipe& p);
};
