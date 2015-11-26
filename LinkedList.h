// LinkedList.h:
//    Определяет класс связанного списка LinkedList.
//    Требует небольших доработок в местах, отмеченных `// TODO'.

#pragma once

#include <cstddef>           // size_t
#include <initializer_list>  // std::initializer_list<T>
#include <iosfwd>            // std::ostream

typedef double Data;

class LinkedList
{
	// Необязательно, нужно для "copy & swap", если вы помните, что это.
	friend void swap(LinkedList& left, LinkedList& right);

	// Полезно для отладки, обязательно.
	friend std::ostream& operator<<(std::ostream& output, const LinkedList& xs);

	// Объявление структуры Node (но определение --- ниже).
	struct Node;

public:
	LinkedList();
	LinkedList(const std::initializer_list<Data> values);

	LinkedList(const LinkedList& source);
	LinkedList& operator=(LinkedList rhs);

	LinkedList(LinkedList&& source);
	LinkedList& operator=(LinkedList&& source);

	virtual ~LinkedList();

public:
	size_t size() const;

	void push_back(const Data& value);
	void push_front(const Data& value);
	void pop_back();
	void pop_front();

	void clear();

	// При некорректном индексе должны возбужадать std::out_of_range.
	void remove_at(size_t index);
	void insert_before(size_t index, const Data& value);
	void insert_after(size_t index, const Data& value);
	Data& value_at(size_t index);

	bool operator==(const LinkedList& other) const;
	bool operator!=(const LinkedList& other) const;

public:
	// Итераторы имеют доступ к членам связанного списка.
	friend class Iterator;

	// Итератор связанного списка.
	class Iterator
	{
	public:
		const Data& operator*() const;
		      Data& operator*();
		const Data& operator->() const;
		      Data& operator->();

		bool operator!=(const Iterator& other) const;

		Iterator& operator++();
		Iterator& operator--();

		Iterator(const Iterator&) = default;
		Iterator(Iterator&&) = default;

	public:
		// См. старое описание работы, последний пункт.
		typedef  std::bidirectional_iterator_tag  iterator_category;
		typedef  size_t                           difference_type;
		typedef  Data                             value_type;
		typedef  Data*                            pointer;
		typedef  Data&                            reference;

	private:
		// Внешнему коду не разрешается создавать итераторы без LinkedList.
		Iterator(LinkedList::Node* node);

		// Связанному списку разрешен доступ ко всем членам итератора
		// (в частности, связанный список может их создавать).
		friend class LinkedList;

	private:
		// Узел, на котором "находится" итератор.
		LinkedList::Node* node_;
	};

public:
	Iterator begin() const;
	Iterator end() const;

private:
	struct Node
	{
		// TODO: нужно самостоятельно определить структуру узла Node.
	};

private:
	// Возвращает указатель на узел с заданным индексом.
	Node* node_at(size_t index);

	// Создают и добавляют в список узел до (после) указанного.
	// Если указанный --- nullptr, добавляют узел в начало (в конец).
	Node* insert_before(Node* before);
	Node* insert_after(Node* after);

	// Удаляет узел по указателю на него.
	void erase(const Node* node);

private:
	// TODO: нужно объявить данные-члены (поля) LinkedList.
};
