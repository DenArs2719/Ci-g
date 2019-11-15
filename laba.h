#ifndef LABA_H
#define LABA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ciag
{
    int n;
    int *arr;
    int max;
    int min;

public:
    Ciag(int n = 0,int min = 0,int max = 0);
    Ciag(const Ciag& c);
    virtual ~Ciag();

    Ciag& operator=(const Ciag& c);
    Ciag& operator++(); /// ++x;
    Ciag operator++(int); /// x++;
    int& operator[](int index);

    void aktualizuj();
    friend ostream& operator<<(ostream& out,const Ciag &c);
};
#endif // LABA_H
