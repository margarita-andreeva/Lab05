// LinkedList.cpp:
//    Содержит реализации методов LinkedList и некоторых функций.
//    Наибольшая часть лабораторной работы связана с этим файлом.

#include <iostream>     // std::ostream
#include <stdexcept>    // std::out_of_range
#include <string>       // std::to_string()
#include <utility>      // std::swap()

#include "LinkedList.h"

using std::swap;  // Чтобы использовать swap() без std::

int LinkedList::findmax() {
    Node* ptr = head->next;

    int index = 1;
    int max_at = 0;
    Data max = head->value;

    while(ptr != nullptr) {
        if(ptr->value > max)
        {
            max_at = index;
            max = ptr->value;
        }
        index++;
        ptr = ptr->next;
    }
    return max_at;
}

void LinkedList::sort() {
   LinkedList sorted;
   while(size() > 0) {
    int maxn = findmax();
    sorted.push_front(value_at(maxn));
    remove_at(maxn);
   }
   *this = sorted;
}

void LinkedList::reverse() {
    LinkedList reversed;
    while(size() > 0) {
        reversed.push_front(value_at(0));
        pop_front();
    }

    *this = reversed;
}

LinkedList& LinkedList::operator=(LinkedList rhs)
{
	/*clear();

	Node *ptr = rhs.head;

	while (ptr != nullptr) {
        push_back(ptr->value);
        ptr = ptr->next;
	}*/
	swap(this->head, rhs.head);

	return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& rhs)
{
	swap(this->head, rhs.head);
	return *this;
}

bool LinkedList::operator==(const LinkedList& other) const
{
    if (this == &other)
        return true;
    size_t s1 = size();
    size_t s2 = other.size();

    if (s1 != s2)
        return false;

    Node *p1 = this->head;
    Node *p2 = other.head;

    while(p1 != nullptr) {
        if (p1->value != p2->value)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

	return true;
}

bool LinkedList::operator!=(const LinkedList& other) const
{
	// TODO
	return !(*this == other);
}

void LinkedList::erase(const Node* node)
{
    if (node == head) {
            head = head->next;
            delete node;
            return;
    }

	Node *ptr = head;

	while (ptr->next != node)
        ptr = ptr->next;

    ptr->next = node->next;
    delete node;
}

void LinkedList::pop_back()
{
	size_t s = size();
	if (s == 0)
        return;
    erase(node_at(s - 1));
}

void LinkedList::pop_front()
{
	size_t s = size();
	if (s == 0)
        return;
    erase(node_at(0));
}

LinkedList::Node* LinkedList::insert_after(LinkedList::Node* after)
{
    Node *new_node = new Node;

    if (head == nullptr) {
            head = new_node;
            head->next = nullptr;
            return head;
        }

    if (after == nullptr) {
        // poslednee mesto
        Node *ptr = head;
        while(ptr->next != nullptr)
            ptr = ptr->next;
        after = ptr;
    }

    new_node->next = after->next;
    after->next = new_node;

	return new_node;
}


LinkedList::Node* LinkedList::insert_before(LinkedList::Node* before)
{
    Node *new_node = new Node;
	if (before == nullptr || before == head) {
        new_node->next = head;
        head = new_node;
	} else {
	    // nayti element pered before

	    Node *ptr = head;
        while(ptr->next != before)
            ptr = ptr->next;

	    new_node->next = ptr->next;
	    ptr->next = new_node;
	}
	return new_node;
}

void LinkedList::push_back(const Data& value)
{
    if(head == nullptr) {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = nullptr;
        head = new_node;
    } else {

        Node *ptr = head;

        while (ptr->next != nullptr)
            ptr = ptr->next;

        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = nullptr;
        ptr->next = new_node;
    }
}

void LinkedList::push_front(const Data& value)
{
	Node *new_node = new Node;
	new_node->value = value;
	new_node->next = head;
	head = new_node;
}

void LinkedList::clear()
{
    while (head != nullptr) {
        erase(head);
    }

}

void swap(LinkedList& left, LinkedList& right)
{
	// TODO
	// HINT: Функция std::swap() меняет значения простых типов.

	std::swap(left.head, right.head);
}


LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(const std::initializer_list<Data> values) :
	LinkedList()
{
	// По std::initializer_list<T> возможен диапазонный for.
	for (const Data& value : values) {
		push_back(value);
	}
}

LinkedList::LinkedList(const LinkedList& source) :
    LinkedList()
{
	Node *ptr = source.head;

	while (ptr != nullptr) {
        push_back(ptr->value);
        ptr = ptr->next;
	}
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
	clear();
}

size_t LinkedList::size() const
{
	Node *ptr = head;
	size_t len = 0;

	while (ptr != nullptr) {
        len++;
        ptr = ptr->next;
	}

	return len;
}

Data& LinkedList::value_at(size_t index)
{
	Node *p = node_at(index);

	if (p == nullptr) {
        throw std::out_of_range("linked list index out of range");
	}
	else
        return p->value;
}

void LinkedList::remove_at(size_t index)
{
	Node *p = node_at(index);
	if (p == nullptr)
        throw std::out_of_range("remove_at: out of range");
    erase(p);

}


void LinkedList::insert_before(size_t index, const Data& value)
{
    size_t sz = size();
    if (size() <= index || index < 0)
        throw std::out_of_range("insert_before: out of range");

	Node *p = node_at(index);
    Node *new_node = insert_before(p);
    new_node->value = value;
}

void LinkedList::insert_after(size_t index, const Data& value)
{
    size_t sz = size();
    if (size() <= index || index < 0)
        throw std::out_of_range("insert_before: out of range");

	Node *p = node_at(index);
    Node *new_node = insert_after(p);
    new_node->value = value;
}

LinkedList::Node* LinkedList::node_at(size_t index)
{
    Node *ptr = head;
	size_t i = 0;

	while (i < index && ptr != nullptr) {
        i++;
        ptr = ptr->next;
	}

	return ptr;
}

std::ostream& operator<<(std::ostream& output, const LinkedList& xs)
{
    LinkedList::Node *ptr = xs.head;
    output << "[";

	while (ptr != nullptr) {
        output << ptr->value;
        if (ptr->next != nullptr)
            output << ", ";
        ptr = ptr->next;
	}

	output << "]";

	return output;
}
