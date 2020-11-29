#pragma once

#include<vector>

using namespace std;

template<class T>
class Ring
{
public:
	class iterator;

private:
	int size;
	int number_of_elem;
	int cycle_pos;
	vector<T> buffer;

	iterator iterator_begin;
	iterator iterator_end;
public:
	Ring(int size) :size{ size }, number_of_elem{ 0 }, cycle_pos{ 0 }, iterator_begin{}
	{
		// Nu e nevoie pentru ca daca fac resize(size) atunci vectorul va avea size elemente
		// Apoi cand fac push_back(elem) el va adauga dupa elemente deja prezente
		// Deci daca am buffer.resize(3)  si apoi facu push_back la trei elemente: one, two, three vectorul
		// va avea elemente: "" "" "" "one" "two" "three"
		//buffer.resize(size);
		iterator_end.set_it_pos(size);
		iterator_begin.it_buffer = &buffer;
	}

	void add(T element)
	{
		if (number_of_elem == size)
		{
			buffer[cycle_pos] = element;
			++cycle_pos;
			if (cycle_pos == number_of_elem)
			{
				cycle_pos = 0;
			}
		}
		else
		{
			buffer.push_back(element);
			++number_of_elem;
		}
	}

	int get_size() const { return size; }
	T get_element(int pos) const
	{
		return buffer[pos];
	}


	iterator& begin()
	{
		return iterator_begin;
	}

	iterator& end()
	{
		return iterator_end;
	}
};

template<class T>
class Ring<T>::iterator
{
	int it_pos;
public:
	vector<T>* it_buffer;

	iterator() : it_pos(0) {}

	iterator(iterator& other)
	{
		it_pos = other.it_pos;
		it_buffer = other.it_buffer;
	}

	T& operator*()
	{
		return (*it_buffer)[it_pos];
	}

	iterator& operator++()
	{
		++it_pos;
		return *this;
	}

	bool operator!=(iterator& other)
	{
		return it_pos != other.it_pos;
	}

	iterator& operator=(const iterator& other)
	{
		it_pos = other.it_pos;
		it_buffer = other.it_buffer;
		return *this;
	}

	int get_it_pos() const
	{
		return it_pos;
	}
	void set_it_pos(int value)
	{
		it_pos = value;
	}

};
