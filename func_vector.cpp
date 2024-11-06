#include<bits/stdc++.h>
using namespace std;
template<class T>
class Vector {
private:
    T* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        T *newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    // Constructor
    Vector(int first_capacity = 2) {
        capacity = first_capacity;
        size = 0;
        data = new T[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Assignment operator
    Vector<T>& operator = (const Vector<T>& p) {
        if (this != &p) {
            delete[] data;
            this->size = p.size;
            this->capacity = p.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = p.data[i];
            }
        }
        return *this;
    }

    // Push back
    void pushBack(T value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    // Operator[]
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Pop back
    void popBack() {
        if (size == 0) {
            cout << "Your Vector is empty";
            return;
        }
        size--;
    }

    // Erase
    void Erase(int position) {
        for (int i = position; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Get
    int get(int position) const {
        if (position < 0 || position > size) {
            cout << "Don't get element!" << endl;
            return -1;
        }
        return data[position];
    }

    // Set
    void set(int position, T value) {
        if (position < 0 || position >= size) {
            cout << "Don't update your element!" << endl;
            return;
        }
        data[position] = value;
    }

    // Clear
    void clear() {
        size = 0;
    }

    // Is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get size
    int getsize() const {
        return size;
    }

    // Begin
    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    // End
    T* end() {
        return data + size;
    }

    const T* end() const {
        return data + size;
    }

    // Rbegin
    T* rbegin() {
        return data + size - 1;
    }

    const T* rbegin() const {
        return data + size - 1;
    }

    // Rend
    T* rend() {
        return data - 1;
    }

    const T* rend() const {
        return data - 1;
    }

    // Contains
    bool contains(T value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    // Insert
    void inSert(T value, int position) {
        if (position < 0 || position > size) {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > position; i--) {
            data[i] = data[i - 1];
        }
        data[position] = value;
        size++;
    }

    // Flex
    void flex() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
    }
};
