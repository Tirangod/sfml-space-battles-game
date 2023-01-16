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
    Date& operator --(int i);
    Date& operator ++();
    Date& operator --();
    Date& operator +(Date date0);
    Date& operator =(string value);
    bool operator >(Date& date);
    bool operator <(Date& date);
    bool operator == (Date& another);
    bool operator != (Date& another);
    ostream& operator <<(ostream& out);
    istream& operator >>(istream& in);
    int operator [](int i);
    operator string();

    int getDay();
    int getMonth();
    int getYear();
};

#endif