#include "Array.h"

Array::Array(int size): size(size)
{
    this->data = new int[size];
}

Array::~Array()
{
    delete[] this->data;
}
