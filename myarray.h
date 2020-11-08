/***************************************************
  Copyright (c) 2017 Luis Llamas
  (www.luisllamas.es)

  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _MYARRAY_H_
#define _MYARRAY_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

template<typename T>
class MyArray {
  public:
    MyArray(size_t capacity);

    ~MyArray();

    size_t getSize();

    T &operator[](const size_t index);

    T &get_actual_value();

    void add(T item);

    void next_index();

    void print();

    void clear();

    bool isEmpty();
    //T* ToArray();

  private:
    T *_items;
    size_t _num_elements = 0;
    size_t _capacity = 0;
    size_t _actual_index = 0;
};

template<typename T>
MyArray<T>::MyArray(size_t capacity) {
  _capacity = capacity;
  _items = new T[_capacity];
}

template<typename T>
MyArray<T>::~MyArray() {
  delete[] _items;
}

template<typename T>
size_t MyArray<T>::getSize() {
  return _num_elements;
}

template<typename T>
T &MyArray<T>::operator[](const size_t index) {
  return _items[index];
}

template<typename T>
T &MyArray<T>::get_actual_value() {
  return _items[_actual_index];
}

template<typename T>
void MyArray<T>::add(T item) {
  ++_num_elements;
  _items[_num_elements - 1] = item;
}

template<typename T>
void MyArray<T>::next_index() {
  _actual_index = (_actual_index + 1) % _capacity;
}


template<typename T>
void MyArray<T>::print() {
  for (int i = 0; i < _capacity; i++) {
    Serial.print(" ###### => ");
    Serial.println(_items[i]);
  }
}


template<typename T>
void MyArray<T>::clear() {
  _num_elements = 0;
}

template<typename T>
bool MyArray<T>::isEmpty() {
  return (_num_elements == 0);
}

/*template <typename T>
  T* MyArray<T>::ToArray() {
  T* items = new T[_num_elements];
  memmove(items, _items, _num_elements * sizeof(T));
  return items;
  }*/


#endif
