//
// Created by Shaunak Kulkarni on 10/22/20.
//

#ifndef PROJECT3_DVD_H
#define PROJECT3_DVD_H


#include <string>
#include <ostream>
#include "Node.h"
#include "BSTree.h"
using namespace std;
class DVD {
public:
    DVD();

    DVD(DVD *pDvd);

    int available;
    int rented;
    string title;

    DVD(int available, int rented, const string &title);

    DVD(string title);

    int getAvailable() const;

    void setAvailable(int available1);

    int getRented() const;

    void setRented(int rented1);

    const string &getTitle() const;

    void setTitle(const string &title1);

    bool operator==(const DVD &rhs) const;

    bool operator!=(const DVD &rhs) const;

    bool operator<(const DVD &rhs) const;

    bool operator>(const DVD &rhs) const;

    bool operator<=(const DVD &rhs) const;

    bool operator>=(const DVD &rhs) const;

    friend ostream &operator<<(ostream &os, const DVD &dvd);
};


#endif //PROJECT3_DVD_H
