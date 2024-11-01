#pragma once
#include <iostream>


void ClearCinBuffer() {
    std::cout << "Invalid input\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}