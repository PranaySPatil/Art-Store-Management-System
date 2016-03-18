#ifndef REPORTITEM_H
#define REPORTITEM_H

#include <iostream>
#include <string>
using namespace std;
class ReportItem
{
public:
    ReportItem(string paintingName, string artist, string subject, string date, int type, int p_price, int opt_price);
    string paintingName, artist, subject, date;
    int type, p_price, opt_price;
};

#endif // REPORTITEM_H
