<<<<<<< HEAD
=======
# ifndef ARRAYLIST_H
# define ARRAYLIST_H
#include <iostream>

template <typename T>
class ArrayList
{
public:
    ArrayList();

    // Copy constructor
    ArrayList(const ArrayList<T>& c);

    // Move constructor
    ArrayList (ArrayList<T>&& c) ;

/*
* Constructor with initialization of " initialized "
elements
*/
    ArrayList(int initialized);

    virtual ~ ArrayList() ;

/*
* Copy assignment operator
*/
    ArrayList<T>& operator =(const ArrayList<T>& a);

/*
* Move assignment operator
*/
    ArrayList<T>& operator =(ArrayList<T>&& a);


/*
* Add element to dynamic array
*/
    void add (const T& element);

/*
* Inserts the element at placement " idx " in array and moves the remaining
* items by one place , restoring the old element at " idx".
* check whether it is needed to extend the storage .
* move all elements from _size to idx ( reverse ) one element to the right in the array
* set _elems [ idx ] equal to the element to be inserted
*/
    void add(int idx, const T& element);
/*
* Get a const reference to the element at idx
*/
    T &operator [](int idx) const;

/*
* Get a reference to the element at idx
*/
    T &operator [](int idx);

/*
* Removes the element at placement " idx " by moving all the remaining elements
* by one place to the left in the array
*/
    void remove(int idx);

/*
* Returns the number of elements stored
*/
    int size() const;
/*
* Returns the number of items currently reserved in memory
*/
    int reserved() const;

/*
* Returns true if number of elements in array is zero
*/
    bool isEmpty() const;

/*
* Trims the storage array to the exact number of elements
* stored .
*/
    void trimToSize();

/*
* Sorts the array using insertion sort (or another algorithm )
*/
    void sort();

/*
* Returns a new ArrayList with elements from " fromIdx " index to " toIdx "
*/
    ArrayList<T> subArrayList(int fromIdx, int toIdx) const;

/*
* Returns a new C++ style array ( copy created with new ) with all elements
*/
    T* toArray();

private:
/*
* extendStorage ():
* create new array with size 2* _reserved
* copy old data to the new array
* delete old array
* update pointer _elems to point to the new array
* ( Since this method is private , the method will only be used internally ,
* but the functionality is needed ).
*/
    void extendStorage();

/*
* Member variables
*/
    int _reserved ; // The current capacity of " _elems " array
    int _size ; // The number of elements stored
    T* _elems ; // Array for storing the elements
};

// No-arg constructor
template<class T>
ArrayList<T>::ArrayList()
{

    _size = 1;
    _reserved = 1;

    _size = 0;
    _reserved = 0;
    _elems = new T[_reserved];

}
// Copy constructor
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& c)
{
    _size = c._size;
    _reserved = c._reserved;
    _elems = new T[_reserved];

    for (int i = 0; i < _size; ++i)
    {
        _elems[i] = c._elems[i];
    }
}

// Move constructor
template<class T>
ArrayList<T>::ArrayList(ArrayList<T> &&c)
{
    _size = c._size;
    _elems = c._elems;
    _reserved = c._reserved;
    c._size = 0;
    c._elems = nullptr;
    c._reserved = 0;
}

// Constructor with initialization of " initialized " elements
template<class T>
ArrayList<T>::ArrayList(int initialized)
{
    _reserved = initialized;
    _size = 0;
    _elems = new T[_reserved];
}

// Deconstructor
template<class T>
ArrayList<T>::~ArrayList()
{
    delete [] _elems;
}

// Copy assignment operator
template<class T>
ArrayList<T>& ArrayList<T>::operator =(const ArrayList<T>& a)
{
    delete [] _elems;

    _size = a._size;
    _elems = new T[_reserved];
    _reserved = a._reserved;

    for (int i = 0; i < _size; ++i)
    {
        _elems[i] = a._elems[i];
    }

    return *this;
}

// Move assignment operator
template<class T>
ArrayList<T>& ArrayList<T>::operator =(ArrayList<T>&& a)
{
    T* tempElems = _elems;
    int tempSize = _size;
    int tempRes = _reserved;

    _elems = a._elems;
    _size = a._size;
    _reserved = a._reserved;

    a._size = tempSize;
    a._elems = tempElems;
    a._reserved = tempRes;

    return *this;
}

// Get a const reference to the element at idx
template<class T>
T& ArrayList<T>::operator [](int idx) const
{
    return _elems[idx];
}

// Get a reference to the element at idx
template<class T>
T& ArrayList<T>::operator [](int idx)
{
    return _elems[idx];
}

// Returns the number of elements stored
template<class T>
int ArrayList<T>::size() const
{
    return _size;
}

// Returns the number of items currently reserved in memory
template<class T>
int ArrayList<T>::reserved() const
{
    return _reserved;
}

// Returns true if number of elements in array is zero
template<class T>
bool ArrayList<T>::isEmpty() const
{
    if(_elems = 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Trims the storage array to the exact number of elements stored.
template<class T>
void ArrayList<T>::trimToSize()
{
    ArrayList<T> tempArray(_size);
    for (int i = 0; i < _size; ++i)
    {
        tempArray._elems[i] = _elems[i];
        tempArray._size++;
    }
    delete [] _elems;
    tempArray._reserved = tempArray._size;
    *this = tempArray;

}


// Sorts the array using insertion sort (or another algorithm )

template<class T>
void ArrayList<T>::sort()
{

    for(int i = 1; i < _size; ++i)
    {
       int index = _elems[i];
       int j = i;
       while (j > 0 && _elems[j-1] > index)
       {
           _elems[j] = _elems[j-1];
           j--;
       }
       _elems[j] = index;
    }
}

// Removes the element at placement " idx " by moving all the remaining elements by one place to the left in the array
template<class T>
void ArrayList<T>::remove(int idx)
{
    ArrayList<T> tempArray(_reserved-1);

    for(int i = 0;i <= _size;++i)
    {
        if(i < idx)
        {
            tempArray._elems[i] = _elems[i];
        }
        else if(i >= idx)
        {
            tempArray._elems[i] = _elems[i+1];
        }
        tempArray._size++;
    }
    tempArray._size--;
    *this = tempArray;
}

// Returns a new ArrayList with elements from " fromIdx " index to " toIdx "
template<class T>
ArrayList<T> ArrayList<T>::subArrayList(int fromIdx, int toIdx) const
{
    ArrayList<T> resArray(toIdx-fromIdx);
    int j = 0;
    for (int i = fromIdx;i < toIdx;++i)
    {
        resArray._elems[j] = _elems[i];
        j++;
        resArray._size++;
    }
    return resArray;
}

//Returns a new C++ style array ( copy created with new ) with all elements
template<class T>
T* ArrayList<T>::toArray()
{
    T *res = new T[_size];

    for(int i = 0; i < _size; i++)
    {
        res[i] = _elems[i];
    }
    return res;
}

/*
* extendStorage ():
* create new array with size 2* _reserved
* copy old data to the new array
* delete old array
* update pointer _elems to point to the new array
* ( Since this method is private , the method will only be used internally ,
* but the functionality is needed ).
*/
// Extends reserved elements
template<class T>
void ArrayList<T>::extendStorage()
{
    ArrayList<T> tempArray(_reserved*2);

    for(int i = 0;i < _size;++i)
    {
        tempArray._elems[i]=_elems[i];
    }
    delete [] _elems;
    _elems = tempArray._elems;
    _reserved = tempArray._reserved;
}

// Add element to dynamic array
template<class T>
void ArrayList<T>::add(const T& element)
{
    if (_size == _reserved)
    {
        extendStorage();
    }
    _elems[_size] = element;
    ++_size;


}

/*
* Inserts the element at placement " idx " in array and moves the remaining
* items by one place , restoring the old element at " idx".
* check whether it is needed to extend the storage .
* move all elements from _size to idx ( reverse ) one element to the right in the array
* set _elems [ idx ] equal to the element to be inserted
*/
template<class T>
void ArrayList<T>::add(int idx, const T& element)
{
    if (_size == _reserved)
    {
        extendStorage();
    }
    ArrayList<T> tempArray(_size+1);
    for(int i = 0; i < _size;++i)
    {
        if(i < idx)
        {
            tempArray._elems[i] = _elems[i];
        }
        else if(i == idx)
        {
            tempArray._elems[i] = element;
        }
        else
        {
            tempArray._elems[i] = _elems[i-1];
        }
        tempArray._size++;

    }
    *this = tempArray;
}









# endif // ARRAYLIST_H


>>>>>>> ad4ee33f89e742c9af54f4b52c59b7ad8bcc8c4d
