#include "ConsoleIO.h"

double ConsoleIO::GetValue(istream& is)
{
    double value;
    while (true)
    {
        if (is >> value)
        {
            if (is.peek() == '\n')
            {
                is.ignore();
                break;
            }
        }
        else
        {
            cout << "Невірне введення! Очікується дійсне число. Повторити:" << endl;
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

string ConsoleIO::GetText(istream& is)
{
    string text;
    while (true)
    {
        getline(is, text);
        if (!text.empty() && text.find_first_not_of(' ') != string::npos)
        {
            break;
        }
        cout << "Невірне введення! Очікується текстова інформація. Повторіть введення: " << endl;
    }
    return text;
}