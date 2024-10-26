#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <cstdint>
#include <iterator>
#include <list>
#include <memory>
#include <utility>

namespace mystl {

template <typename ElementType>
struct LinkedListNode {
private:
	std::weak_ptr<LinkedListNode> _prev;
	std::weak_ptr<LinkedListNode> _next;
	ElementType _val;

public:
	LinkedListNode() = default;
	explicit LinkedListNode(ElementType val);

	LinkedListNode(const LinkedListNode& ano_node) = default;
	LinkedListNode& operator =(const LinkedListNode& ano_node);

	LinkedListNode(LinkedListNode&& ano_node) noexcept;
	LinkedListNode& operator =(LinkedListNode&& ano_node) noexcept;

	~LinkedListNode() = default;
};

template <typename ElementType>
using Node = LinkedListNode<ElementType>;



template <typename ElementType>
struct DoublyLinkedList {
private:
	class Iterator : public std::iterator<std::bidirectional_iterator_tag, ElementType> {
	private:
		std::shared_ptr<Node<ElementType>> _current;

	public:
		Iterator() = default;
		explicit Iterator(std::shared_ptr<Node<ElementType>> pt) : _current{pt} {}

		Iterator(const Iterator& ano_iter) : _current{ano_iter._current} {}
		Iterator& operator=(const Iterator& ano_iter);

		Iterator(Iterator&& ano_iter) noexcept;
		Iterator& operator=(Iterator&& ano_iter) noexcept;

		~Iterator() = default;

	public:
		ElementType& operator*() { return _current->_val; }
		auto operator->() { return _current; }

		Iterator& operator++();
		Iterator& operator--();

		bool operator!=(const Iterator& ano_iter) const { return _current != ano_iter._current; }
		bool operator==(const Iterator& ano_iter) const { return _current == ano_iter._current; }
	};

private:
	uint64_t _size;
	std::shared_ptr<Node<ElementType>> _head;
	std::shared_ptr<Node<ElementType>> _tail;

public:
	DoublyLinkedList() = default;
	explicit DoublyLinkedList(const uint64_t size);
	DoublyLinkedList(const uint64_t size, ElementType val);
	DoublyLinkedList(const Iterator& begin, const Iterator& end);
	DoublyLinkedList(std::initializer_list<DoublyLinkedList<ElementType>> list);

	DoublyLinkedList(const DoublyLinkedList& ano_list);
	DoublyLinkedList& operator=(const DoublyLinkedList& ano_list);

	DoublyLinkedList(DoublyLinkedList&& ano_list) noexcept;
	DoublyLinkedList& operator=(DoublyLinkedList&& ano_list) noexcept;

	~DoublyLinkedList();

public:
	Iterator begin() const { return Iterator(_head); }
	Iterator end() const { return Iterator(_tail); }

	void push_front(ElementType val);
	void push_back(ElementType val);
	void insert(ElementType val);
};

template <typename ElementType>
using list = DoublyLinkedList<ElementType>;

}










#endif //DOUBLYLINKEDLIST_H