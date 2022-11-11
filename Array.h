#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

#define DefaultLength 10

#ifndef _ARRAY_H_
#define _ARRAY_H_

/*The array class does not contain all the different functions and constructor as that of the array class in assignment 1.
This is mainly because some parts of the array class like Shrink, slice and reverse where causing errors while programing.
All the constructors and functions in this file are the same  as that of Assignment 1 and work with the stack class.*/
template <class T>
class Array {
private:
	T* data_;
	size_t cur_size_;
	size_t max_size_;
public:
	//default constructor
	Array() :data_(new T[DefaultLength]), cur_size_(DefaultLength), max_size_(DefaultLength){}

	/*Initializing constructor
	@param[in]  size   initial size
	*/
	Array(size_t size) : data_(new T[DefaultLength]), cur_size_(DefaultLength), max_size_(DefaultLength)
	{
		this->cur_size_ = size;
		this->max_size_ = size;
		this->data_ = new T[size];
	}

	//distructor
	~Array(void) 
	{
		delete[] this->data_;
	}

	/*Retrieve the max size of the array
	@return   max_size_   maximum size of the array
	*/
	size_t max_size(void) const
	{
		return this->max_size_;
	}

	/**
   * Set the character at the specified at an index.
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   */
	void set(T element, size_t pos) 
	{
		this->data_[pos] = element;   //since this is used for the stack class, the element will be set at the position of top. 
	}

	/**
   * Get the character at the specified index
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   */
	T get(size_t pos)
	{
		return this->data_[pos];  //returns the data at the required position. 
	}

	/*
	*Resizes the array to a new size in order to store more information
	*@parmin    size     new size of the array
	*/
	void resize(size_t size)
	{
		T* temparr = new T[size];  //creating a temp array to copy into later on
		//wanted to try using a pointer for loop but was getting an error for using T*. Ended up using a normal int pointer for copying the values. 
		for (int i = 0; i < this->cur_size_; i++) {
			temparr[i] = this->data_[i];
		}
		this->data_ = temparr;  //the data_ array now points to the new array with an increased size
		this->cur_size_ = size;  //updating the cur_size_ and max_size_
		this->max_size_ = size;
		delete[] temparr;  //deleting the old array in order to save on memory
	}
};

#endif
