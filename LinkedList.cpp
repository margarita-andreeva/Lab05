#include <iostream>     // std::ostream
#include <stdexcept>	// std::out_of_range
#include <string>		// std::to_string()
#include <utility>		// std::swap()

#include "LinkedList.h"

LinkedList& LinkedList::operator=(LinkedList rhs)
{
	// TODO
	return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& rhs)
{
	// TODO
	return *this;
}

bool LinkedList::operator==(const LinkedList& other) const
{
	// TODO
	return false;
}

bool LinkedList::operator!=(const LinkedList& other) const
{
	// TODO
	return !(*this == other);
}

void LinkedList::erase(const Node* node)
{
	// TODO
}

void LinkedList::pop_back()
{
	// TODO
}

void LinkedList::pop_front()
{
	// TODO
}

LinkedList::Node* LinkedList::insert_after(LinkedList::Node* after)
{
	// TODO
	return nullptr;
}


LinkedList::Node* LinkedList::insert_before(LinkedList::Node* before)
{
	// TODO
	return nullptr;
}

void LinkedList::push_back(const Data& value)
{
	// TODO
}

void LinkedList::push_front(const Data& value)
{
	// TODO
}

void swap(LinkedList& left, LinkedList& right)
{
	// TODO
	// HINT: Функция std::swap() меняет значения простых типов.
}


LinkedList::LinkedList()
{
	// TODO
}


LinkedList::LinkedList(const std::initializer_list<Data> values) :
	LinkedList()
{
	// По std::initializer_list<T> возможен диапазонный for.
	for (const Data& value : values) {
		push_back(value);
	}
}

LinkedList::LinkedList(const LinkedList& source)
{
	// TODO

	// HINT:
	// Здесь нельзя воспользоваться диапазонным for, потому что на данном
	// этапе задания у списка не реализованы итераторы, begin() и end().
}

LinkedList::LinkedList(LinkedList&& source)
	: LinkedList()
{
	swap(*this, source);
}

LinkedList::~LinkedList()
{
	// TODO
}

size_t LinkedList::size() const
{
	// TODO
}

Data& LinkedList::value_at(size_t index)
{
	// TODO
}

void LinkedList::remove_at(size_t index)
{
	// TODO
}


void LinkedList::insert_before(size_t index, const Data& value)
{
	// TODO
}

void LinkedList::insert_after(size_t index, const Data& value)
{
	// TODO
}

LinkedList::Node* LinkedList::node_at(size_t index)
{
	// TODO
}

std::ostream& operator<<(std::ostream& output, const LinkedList& xs)
{
	// TODO
	return output;
}
