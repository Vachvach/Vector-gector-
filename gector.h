#include "prototype.h"
template <typename T>
template <typename E>
gector<T>& gector<T>::operator=(gector<E>& rhs)
{
    delete [] m_arr;
    this->m_capacity = rhs.get_Mcap();
    this->m_size = rhs.get_Msize();
    m_arr = new T [m_capacity];
    for(int i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhs.get_p(i);
    }
    return *this;
}

template <typename T>
int gector<T>::get_p(int x)
{
    return m_arr[x];
}

template <typename T>
int gector<T>::get_Msize()
{
    return m_size;
}

template <typename T>
int gector<T>::get_Mcap()
{
    return m_capacity;
}

template <typename T>
gector<T>::gector()
{
    m_capacity = 4;
    m_size = 0;
    m_arr = new T[m_capacity];
}
template <typename T>
gector<T>::~gector()
{
    delete [] m_arr;
    m_arr = nullptr;
}
template <typename T>
gector<T>::gector(const gector<T>& rhs)
{
    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    delete [] m_arr;
    m_arr = new T[rhs.m_capacity];  
    for (int i = 0; i < m_size; i++)
    {
        m_arr[i] = rhs.m_arr[i];
    }  
}
template <typename T>
gector<T>::gector(gector<T>&& ot)
{
    this->m_capacity = ot.m_capacity;
    this->m_size = ot.m_size;
    this->m_arr = ot.m_arr;
    ot.m_arr = nullptr;
    ot.m_capacity = 0;
    ot.m_size = 0;
}
template <typename T>
gector<T>& gector<T>::operator=(gector<T>&& r)
{
    this->m_capacity = r.m_capacity;
    this->m_size = r.m_size;
    delete [] this->m_arr;
    this->m_arr = r.m_arr;
    r.m_arr = nullptr;
    r.m_capacity = 0;
    r.m_size = 0;
    return *this;
}
template <typename T>
gector<T>& gector<T>::operator=(const gector<T>& oth)
{
    if(this == &oth)
    {
        return *this;
    }
    delete [] m_arr;
    m_capacity = oth.m_capacity;
    m_size = oth.m_size;
    m_arr = new T [m_capacity];
    for(int i = 0; i < m_size; ++i)
    {
        m_arr[i] = oth.m_arr[i];
    }
    return *this;
}
template <typename T>
gector<T> gector<T>::operator+(const gector<T>& oth)
{
    gector<T> v;
    v.m_capacity = this-> m_capacity + oth.m_capacity;
    v.m_size = this-> m_size + oth.m_size;
    v.m_arr = new T [m_capacity];
    for(int i = 0; i < this-> m_size; ++i)
    {
        v.m_arr[i] = this-> m_arr[i];
    }
    for(int i = 0; i < oth.m_size; ++i)
    {
        v.m_arr[i] = oth.m_arr[i];
    }
    return v;
}
template <typename T>
void gector<T>::pop_back()
{
        if(m_size != 0)
        {
            --m_size;
        }
}
template <typename T>
void gector<T>::push_back(T el)
    {
        if(m_size == m_capacity)
        {
            m_capacity *= 2;
            T* tmp = new T [m_capacity];
            for(int i = 0; i < m_size; ++i)
            {
                tmp[i] = m_arr[i];
            }
            delete [] m_arr;
            m_arr = tmp;
        }
        m_arr[m_size] = el;
        ++m_size;
    }
    template <typename T>
void gector<T>::push_front(T el)
    {
        if(m_size == m_capacity)
        {
            m_capacity *= 2;
        }
            int* tmp = new T[m_capacity];
            tmp[0] = el;
            for(int i = 0; i < m_size; ++i)
            {
                tmp[i+1] = m_arr[i];
            }
            delete [] m_arr;
            m_arr = tmp;
            ++m_size;
    }
template <typename T>
void gector<T>::erase(int  el)
    {   
        try
        {
            if(el > m_size)
            {
                throw (el);
            }
        }
        catch(T el)
        {
            std::cerr << "ERROR";
        }
        for(int i = 0; i < m_size; ++i)
        {
            if(el >= i)
            {
                m_arr[i] = m_arr[i + 1];
            }
        }
        --m_size;
    }

template <typename T>
void gector<T>::insert(int index, T el)
{
    try
    {
        if(m_arr[index] > m_arr[m_capacity])
        {
            throw index;
        }
        if(m_capacity == m_size)
        {
            m_capacity *=2;
        }
            T* tmp = new T [m_capacity];
        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        for(int i = m_size; i >= index; --i)
        {
            tmp[i] = m_arr[i-1];
        }
            delete[] m_arr;
            tmp[index] = el;
            m_arr = tmp;
            m_size+=1;
        } 
    catch(int index)
    {
        std::cerr << "Segment Dumped" << '\n';
    }
}

template <typename T>
T& gector<T>::operator[](int index)
    { 
        return m_arr[index];
    }


template <typename T>
int gector<T>::size()
{
    return m_size;
}
