#include "stack.h"
#include <iostream>

template <typename T>
void stack<T>::push(T el)
{
    gector<T>::push_back(el);
}
