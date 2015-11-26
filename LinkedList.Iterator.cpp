// LinkedList.Iterator.cpp:
//    Содержит реализации методов класса LinkedList::Iterator и свзанных
//    с итераторами методов LinkedList.

#include <iostream>     // std::ostream
#include <stdexcept>    // std::out_of_range
#include <string>       // std::to_string()
#include <utility>      // std::swap()

#include "LinkedList.h"


LinkedList::Iterator LinkedList::begin() const
{
	// TODO
}


LinkedList::Iterator LinkedList::end() const
{
	// TODO
}


LinkedList::Iterator::Iterator(LinkedList::Node* node)
	: node_{node}
{
}


LinkedList::Iterator& LinkedList::Iterator::operator++()
{
	// TODO
	return *this;
}


LinkedList::Iterator& LinkedList::Iterator::operator--()
{
	// TODO
	return *this;
}


bool LinkedList::Iterator::operator!=(const LinkedList::Iterator& other) const
{
	// TODO
}


Data& LinkedList::Iterator::operator*()
{
	// TODO
}


Data& LinkedList::Iterator::operator->()
{
	// (*this) дает ссылку на итератор, к которому применяется стрелка.
	// Далее этот итератор разыменовывается, то есть вызывается operator*().
	return *(*this);
}


const Data& LinkedList::Iterator::operator*() const
{
	// TODO
}


const Data& LinkedList::Iterator::operator->() const
{
	return *(*this);
}
