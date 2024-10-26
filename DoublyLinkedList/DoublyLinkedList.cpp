#include "./DoublyLinkedList.h"

namespace mystl {
template <typename ElementType>
LinkedListNode<ElementType>::LinkedListNode(ElementType val) : _prev{nullptr}, _next{nullptr}, _val{val} {}

template <typename ElementType>
LinkedListNode<ElementType>&
LinkedListNode<ElementType>::operator=(const LinkedListNode& ano_node) {
	if (this != &ano_node) {
		_prev = ano_node._prev;
		_next = ano_node._next;
		_val = ano_node._val;
	}
	return *this;
}

template <typename ElementType>
LinkedListNode<ElementType>::LinkedListNode(LinkedListNode&& ano_node) noexcept :
	_prev{std::move(ano_node._prev)}, _next{std::move(ano_node._next)}, _val{std::move(ano_node._val)} {}


template <typename ElementType>
LinkedListNode<ElementType>&
LinkedListNode<ElementType>::operator=(LinkedListNode&& ano_node) noexcept {
	if (this != &ano_node) {
		_prev = std::move(ano_node._prev);
		_next = std::move(ano_node._next);
		_val = std::move(ano_node._val);
	}
	return *this;
}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::Iterator&
DoublyLinkedList<ElementType>::Iterator::operator=(const Iterator& ano_iter) {
	if (this != &ano_iter) {
		_current = ano_iter._current;
	}
	return *this;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::Iterator::Iterator(Iterator&& ano_iter) noexcept {
	_current = std::move(ano_iter._current);
}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::Iterator& DoublyLinkedList<ElementType>::Iterator::operator=(
	Iterator&& ano_iter) noexcept {
	if (this != &ano_iter) {
		_current = std::move(ano_iter._current);
	}
	return *this;
}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::Iterator& DoublyLinkedList<ElementType>::Iterator::operator++() {
	if (_current) {
		if (_current->_next) {
			_current = _current->_next;
		}
		else {
			return Iterator(nullptr);
		}
	}
	return *this;
}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::Iterator& DoublyLinkedList<ElementType>::Iterator::operator--() {
	if (_current) {
		if (_current->_prev) {
			_current = _current->_prev;
		}
		else {
			return Iterator(nullptr);
		}
	}
	return *this;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const uint64_t size) : _size{size} {
	if (size > 0) {
		_head = std::make_shared<Node<ElementType>>(ElementType());
		auto current = _head;

		for (uint64_t i = 1; i < size; ++i) {
			auto new_node = std::make_shared<Node<ElementType>>(ElementType());

			current->next = new_node;
			new_node->_prev = current;
			current = new_node;
		}

		_tail = current;
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const uint64_t size, ElementType val) : _size{size} {
	if (size > 0) {
		_head = std::make_shared<Node<ElementType>>(ElementType(val));
		auto current = _head;

		for (uint64_t i = 1; i < size; ++i) {
			auto new_node = std::make_shared<Node<ElementType>>(ElementType(val));

			current->next = new_node;
			new_node->_prev = current;
			current = new_node;
		}

		_tail = current;
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const Iterator& begin, const Iterator& end) :
	_size{0}, _head{nullptr}, _tail{nullptr} {
	for (auto it = begin; it != end; ++it) {
		auto new_node = std::make_shared<Node<ElementType>>(*it);

		_head = new_node;
		_tail = new_node;
		++_size;
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(std::initializer_list<DoublyLinkedList<ElementType>> list) {

}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList& ano_list) : _size{ano_list._size} {

}

template <typename ElementType>
DoublyLinkedList<ElementType>&
DoublyLinkedList<ElementType>::operator=(const DoublyLinkedList& ano_list) : _size{ano_list._size} {
	if (this != &ano_list) {

	}
	return *this;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(DoublyLinkedList&& ano_list) noexcept {
	if (this != &ano_list) {

	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>&
DoublyLinkedList<ElementType>::operator=(DoublyLinkedList&& ano_list) noexcept {
	if (this != &ano_list) {

	}
	return *this;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList() {

}

template <typename ElementType>
void DoublyLinkedList<ElementType>::push_front(ElementType val) {
	auto new_node = std::make_shared<Node<ElementType>>(val);

	if (_head) {
		_head->_prev = new_node;
		new_node->_next = _head;
	} else {
		_tail = new_node;
	}

	_head = new_node;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::push_back(ElementType val) {
	auto new_node = std::make_shared<Node<ElementType>>(val);

	if (_head) {
		_tail->_next = new_node;
		new_node->_prev = _tail;
	} else {
		_head = new_node;
	}

	_tail = new_node;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::insert(ElementType val) {

}





}
