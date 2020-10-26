//
// Created by Shaunak Kulkarni on 10/22/20.
//

#include <iomanip>
#include "DVD.h"

int DVD::getAvailable() const {
    return available;
}

void DVD::setAvailable(int available1) {
    DVD::available = available1;
}

int DVD::getRented() const {
    return rented;
}

bool DVD::operator==(const DVD &rhs) const {
    return title == rhs.title;
}

bool DVD::operator<(const DVD &rhs) const {
    return title < rhs.title;
}

DVD::DVD(int available, int rented, const string &title) : available(available), rented(rented), title(title) {}

bool DVD::operator>(const DVD &rhs) const {
    return rhs < *this;
}

bool DVD::operator<=(const DVD &rhs) const {
    return !(rhs < *this);
}

bool DVD::operator>=(const DVD &rhs) const {
    return !(*this < rhs);
}

bool DVD::operator!=(const DVD &rhs) const {
    return !(rhs == *this);
}

void DVD::setRented(int rented1) {
    DVD::rented = rented1;
}

const string &DVD::getTitle() const {
    return title;
}

void DVD::setTitle(const string &title1) {
    DVD::title = title1;
}

DVD::DVD() {
rented = 0;
available =0;

}

ostream &operator<<(ostream &os, const DVD &dvd) {
    os <<setw(35)<<left<< dvd.title.substr(1,dvd.title.length()-2)
       <<setw(5) <<right<< dvd.available
       <<setw(5) <<right<< dvd.rented;
    return os;
}

DVD::DVD(DVD *pDvd) {
    this->available = 0;
    this->rented = 0;
    this->title = "";
    this->setAvailable(pDvd->getAvailable());
    this->setTitle(pDvd->getTitle());
    this->setRented(pDvd->getRented());
}

DVD::DVD(string title) : title(title) {
    title = "";
    rented = 0;
    available =0;
}
