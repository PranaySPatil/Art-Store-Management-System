#include "reportitem.h"

ReportItem::ReportItem(string paintingName, string artist, string subject, string date, int type, int p_price, int opt_price)
{
    this->artist = artist;
    this->paintingName = paintingName;
    this->subject = subject;
    this->date = date;
    this->type = type;
    this->p_price = p_price;
    this->opt_price = opt_price;
}
