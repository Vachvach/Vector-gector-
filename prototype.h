#ifndef gector_h
#define gector_h
#include <iostream>
#include <exception>
template <typename T>
class gector
{
private:
    int m_capacity;
    int m_size;
    T* m_arr;
public:
    gector();
    ~gector();
    gector(const gector<T>&);
    gector(gector<T>&&);
    gector& operator=(gector<T>&&);
    gector& operator=(const gector<T>&);
    template <typename E>
    gector<T>& operator=(gector<E>&);
    gector operator+(const gector<T>&);
    void pop_back();
    void push_back(T);
    void push_front(T);
    void erase(int);
    void insert(int, T);
    int size();
    int get_Msize();
    int get_Mcap();
    int get_p(int);
    T& operator[](int);
};
#endif //gector_h