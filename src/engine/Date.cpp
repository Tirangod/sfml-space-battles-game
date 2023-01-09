#include <engine/Date.hpp>

Date::Date(string str) {
    parseString(str);
}

Date::Date(int day, int month, int year) 
{
    if (day > 0 && day < 32)
        this->day = day;
    else
        this->day = 1;//throw "Day has to be in range from 1 to 31";
    
    if (month > 0 && month < 13)
        this->month = month;
    else
        this->month = 1;//throw "Month has to be in range from 1 to 12";

    this->year = year;
}

void Date::parseString(string str) {
    string buffer;
    buffer.reserve(str.length());
    int n = 0;
    char ch;

    for (int i = 0; i < str.length(); i++) {
        ch = str[i];

        if (ch != '.') {
            buffer.append(&ch);
        } else {
            if (n == 0)
                day = atoi(buffer.c_str());
            else if (n == 1) 
                month = atoi(buffer.c_str());
            
            buffer.clear();
            n++;
        }

        if (i == str.length() - 1) 
            year = atoi(buffer.c_str());
    }
}
void Date::printMessage(string message) {
    cout << (string)*this << ": " << message << endl;
}
    
Date& Date::operator ++(int i) {
    day += i;

    if (day > 31) {
        day = 1;
        month += i;
    }

    if (month > 12) {
        month = 1;
        year += i;
    }
}
Date& Date::operator +(Date date0) {
    Date _new(day + date0.getDay(), month + date0.getMonth(), year + date0.getYear());
    this->day = _new.day;
    this->month = _new.month;
    this->year = _new.year;
    return *this;
}
Date& Date::operator =(string value) {
    parseString(value);
    return *this;
}
bool Date::operator >(Date& date) {
    return year > date.year || month > date.month || day > date.day;
}
int Date::operator [](int i) {
    if (i == 0)
        return day;
    else if (i == 1)
        return month;
    else if (i == 2)
        return year;
    else 
        throw "Out of bounds";
}
Date::operator string() {
    return (to_string(day) + "." + to_string(month) + "." + to_string(year));
}

int Date::getDay() {
    return day;
}
int Date::getMonth() {
    return month;
}
int Date::getYear() {
    return year;
}