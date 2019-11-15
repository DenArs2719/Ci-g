#include "laba.h"

Ciag::Ciag(int n,int min,int max)
{
    this->n = n;
    this->min = min;
    this->max = max;

    if(n>0)
    {
        arr = new int[n];

        for(int i=0;i<n;i++)
        {
            arr[i] = min+rand() % max;
        }
    }
    else if(n == 0)
    {
        arr = nullptr;
    }
    else
    {
        cerr<<"nie poprawna liczba elementow "<<endl;
        n = 0;
        max = 0;
        min = 0;
        arr = nullptr;
    }
}

Ciag::Ciag(const Ciag& c)
{
    this->n = c.n;
    this->max = c.max;
    this->min = c.min;

    if(n>0)
    {
        this->arr = new int[this->n];

        for(int i=0; i<this->n; i++)
        {
            this->arr[i] = c.arr[i];
        }
    }
    else if(this->n == 0)
    {
        this->arr = nullptr;
    }
    else
    {
        cerr<<"nie poprawna liczba elementow "<<endl;
        this->n = 0;
        this->max = 0;
        this->min = 0;
        this->arr = nullptr;
    }
}

Ciag& Ciag::operator=(const Ciag& c)
{
    if(this == &c)
    {
        return *this;
    }

    if(arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
    }

    this->n = c.n;
    this->min = c.min;
    this->max = c.max;
    this->arr = new int[this->n];

    for(int i=0;i<this->n;i++)
    {
        this->arr[i] = c.arr[i];
    }

    return *this;

}


Ciag::~Ciag()
{
    cout<<"Usuwanie ciagu "<<*this<<endl;
    if(arr != nullptr)
    {
        delete [] arr;
        arr = nullptr; /// �������� ������
    }
}

Ciag& Ciag::operator++() ///& ���������� ��������
{

    int *nowy = new int [this->n + 1];

    for(int i=0;i<this->n;i++)
    {
        nowy[i] = this->arr[i];
    }

    nowy[this->n] = rand() % (max - min  +  1) + min;

    if(arr!=nullptr)
    {
        delete [] arr;
        arr = nullptr;
    }

    this->n++;
    arr = nowy;

    return* this;
}

Ciag Ciag::operator++(int)
{
    Ciag kopia = *this;

    ++(*this);

    return kopia;
}

int& Ciag::operator[](int index)
{
    if(index > n - 1)
    {
       throw logic_error("index jest wiekszy niz dlugosc tablicy");
    }

    return arr[index];
}

void Ciag::aktualizuj()
{
    for(int i=0;i<this->n;i++)
    {
        if(min > arr[i])
        {
           min = arr[i];
        }
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
}


ostream& operator<<(ostream& out, const Ciag &c)
{
    out<<"(";

    for(int i=0;i<c.n;i++)
    {
        out<<c.arr[i]<<(i == c.n-1 ?"":",");
    }
    out<<")";

    return out;
}

