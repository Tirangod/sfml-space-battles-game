#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    void parseString(string str);
public:
    Date(string str);
    Date(int day, int month, int year);

    void printMessage(string message);
    
    Date& operator ++(int i);
    Date& operator +(Date date0);
    Date& operator =(string value);
    bool operator >(Date& date);
    int operator [](int i);
    operator string();

    int getDay();
    int getMonth();
    int getYear();
};

#endif