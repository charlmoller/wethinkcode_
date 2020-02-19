/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:33:12 by ashulha           #+#    #+#             */
/*   Updated: 2017/07/13 15:54:56 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>

class Array {
private:
	unsigned int _size;
	T* _array;

public:
	Array(void): _size(1), _array(new T[0]) {}
	Array(unsigned int size): _size(size), _array(new T[size]) {}
	Array(Array const & a) {*this = a;}

	unsigned int	size(void) {return _size;}

	~Array(void) {delete[] _array; return;}

	Array&			operator=(Array const & a) {
		_size = a.size();
		delete [] _array;
		if (_size > 0) _array = new T[_size];
		else _array = new T();
		for(unsigned int i = 0; i < _size; i++)
			_array[i] = a[i];
		return (*this);
	}
	T&				operator[](unsigned int index) {
		if (index >= _size) throw Array::WrongIndex();
		return _array[index];
	}

	class WrongIndex: public std::exception {
		virtual const char* what() const throw() {
			return "No index in array.";
		}
	};

};

#endif
