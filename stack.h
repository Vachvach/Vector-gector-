template <typename T>
class stack : private gector<T>
{
    public:
    //
    void push(T el);
    //
    void pop();
};

template <typename T>
void stack<T>::push(T el)
{
    gector<T>::push_back(el);
}

template <typename T>
void stack<T>::pop()
{
    gector<T>::pop_back();
}