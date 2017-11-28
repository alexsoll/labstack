#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class T>
class TStack {
	T* arr;
	int size;
	int maxsize;

public:
	TStack(int _size = 200) {
		if (_size < 0)
			throw _size;
		arr = new T[_size];
		maxsize = _size;
		size = 0;
	}

	~TStack() {
		delete[] arr;
	}

	TStack (const TStack& ts) {
		size = ts.size;
		maxsize = ts.maxsize;
		arr = new T[maxsize];
		for (int i = 0; i < size; i++)
			arr[i] = ts.arr[i];
	}

	TStack& operator=(const TStack& ts) {
		if (this != &ts) {
			if (maxsize != ts.maxsize) {
				delete[] arr;
				maxsize = ts.maxsize;
			}
			size = ts.size;
			arr = new T[maxsize];
			for (int i = 0; i < size; i++)
				arr[i] = ts.arr[i];
		}
		return *this;
	}

	int isfull() {
		if (size == maxsize)
			return 1;
		else
			return 0;
	}

	int isempty() {
		if (size == 0)
			return 1;
		else 
			return 0;
	}

	T top() {
		if(isempty())
			throw -1;
		else
			return arr[size - 1];
	}

	T pop() {
		if (isempty()) 
			throw -1;
		size--;
		return arr[size];
	}

	void push(const T& el) {
		if (isfull()) throw -1;
		arr[size] = el;
		size++;
	}

	void clear() {
		size = 0;
	}

	int getsize() {
		return size;
	}

	int getmaxsize() {
		return maxsize;
	}

	/*T operator[](int n) {
		if (n < 0 || n >= maxsize)
			throw n;
		return arr[n];
	}*/

	bool operator==(const TStack& st) const {
		if (maxsize != st.maxsize)
			return 0;
		if (size != st.size)
			return 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] != st.arr[i])
				return 0;
		}
		return 1;
	}

	bool operator!=(const TStack& st) const {
		return !(*this == st);
	} 

};