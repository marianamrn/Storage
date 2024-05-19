#ifndef CONSOLEIO_H
#define CONSOLEIO_H
#include <iostream>
#include <string>
#include <limits> 
#include <locale>

using namespace std; 

class ConsoleIO
{
public:
    static double GetValue(istream& is);
    static string GetText(istream& is);
};
#endif // CONSOLEIO_H
#pragma once
