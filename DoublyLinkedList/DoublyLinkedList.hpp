#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <cstdint>
#include <memory>
#include <utility>

namespace mystl {
template <typename ElementType>
struct DoublyLinkedList {
private:
	struct LinkedListNode {
		std::shared_ptr<LinkedListNode> _prev;
		std::shared_ptr<LinkedListNode> _next;
		ElementType _val;

		LinkedListNode() = default;
		explicit LinkedListNode(ElementType val);

		LinkedListNode(const LinkedListNode& ano_node) = default;
		LinkedListNode& operator =(const LinkedListNode& ano_node);

		LinkedListNode(LinkedListNode&& ano_node) noexcept;
		LinkedListNode& operator =(LinkedListNode&& ano_node) noexcept;

		~LinkedListNode() = default;
	};

public:
	using Node = LinkedListNode;

private:
	class Iterator {
	public:
		std::shared_ptr<Node> _current;

	public:
		Iterator() = default;
		explicit Iterator(std::shared_ptr<Node> pt) : _current{pt} {}

		Iterator(const Iterator& ano_iter) = default;
		Iterator& operator=(const Iterator& ano_iter);

		Iterator(Iterator&& ano_iter) noexcept;
		Iterator& operator=(Iterator&& ano_iter) noexcept;

		~Iterator() = default;

	public:
		ElementType& operator*() { return _current->_val; }
		auto operator->() { return _current; }

		Iterator operator++();
		Iterator operator--();

		bool operator!=(const Iterator& ano_iter) const { return _current != ano_iter._current; }
		bool operator==(const Iterator& ano_iter) const { return _current == ano_iter._current; }
	};

private:
	uint64_t _size;
	std::shared_ptr<Node> _sentinel;

public:
	DoublyLinkedList() = default;
	explicit DoublyLinkedList(uint64_t size);
	DoublyLinkedList(uint64_t size, ElementType val);
	DoublyLinkedList(const Iterator& begin, const Iterator& end);
	DoublyLinkedList(std::initializer_list<ElementType> list);

	DoublyLinkedList(const DoublyLinkedList& ano_list);
	DoublyLinkedList& operator=(const DoublyLinkedList& ano_list);

	DoublyLinkedList(DoublyLinkedList&& ano_list) noexcept;
	DoublyLinkedList& operator=(DoublyLinkedList&& ano_list) noexcept;

	~DoublyLinkedList() = default;

public:
	Iterator begin() const { return Iterator(_sentinel->_next); }
	Iterator end() const { return Iterator(_sentinel); }
	ElementType front() const { return _sentinel->_next->_val; }
	ElementType back() const { return _sentinel->_prev->_val; }
	[[nodiscard]] uint64_t size() const { return _size; }
	[[nodiscard]] bool empty() const { return _size == 0; }

	void push_front(const ElementType& val);
	void push_back(const ElementType& val);
	void insert(Iterator it, const ElementType& val);

	void pop_back();
	void pop_front();

	void clear();
};

template <typename ElementType>
using list = DoublyLinkedList<ElementType>;

template <typename ElementType>
using Node = typename DoublyLinkedList<ElementType>::template LinkedListNode<ElementType>;

template <typename ElementType>
DoublyLinkedList<ElementType>::LinkedListNode::LinkedListNode(ElementType val) :
	_prev{std::shared_ptr<LinkedListNode>()},
	_next{std::shared_ptr<LinkedListNode>()},
	_val{val} {}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::LinkedListNode&
DoublyLinkedList<ElementType>::LinkedListNode::operator=(const LinkedListNode& ano_node) {
	if (this != &ano_node) {
		_prev = ano_node._prev;
		_next = ano_node._next;
		_val = ano_node._val;
	}
	return *this;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::LinkedListNode::LinkedListNode(LinkedListNode&& ano_node) noexcept :
	_prev{std::move(ano_node._prev)}, _next{std::move(ano_node._next)}, _val{std::move(ano_node._val)} {}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::LinkedListNode&
DoublyLinkedList<ElementType>::LinkedListNode::operator=(LinkedListNode&& ano_node) noexcept {
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
DoublyLinkedList<
	ElementType>::Iterator::Iterator(Iterator&& ano_iter) noexcept : _current{std::move(ano_iter._current)} {}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::Iterator& DoublyLinkedList<ElementType>::Iterator::operator=(
	Iterator&& ano_iter) noexcept {
	if (this != &ano_iter) {
		_current = std::move(ano_iter._current);
	}
	return *this;
}

template <typename ElementType>
typename DoublyLinkedList<ElementType>::Iterator DoublyLinkedList<ElementType>::Iterator::operator++() {
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
typename DoublyLinkedList<ElementType>::Iterator DoublyLinkedList<ElementType>::Iterator::operator--() {
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
DoublyLinkedList<ElementType>::DoublyLinkedList(uint64_t size) : _size{size}, _sentinel{std::make_shared<Node>()} {
	if (size > 0) {
		auto current = _sentinel;
		for (uint64_t i = 0; i < size; ++i) {
			auto new_node = std::make_shared<Node>();
			current->_next = new_node;
			new_node->_prev = current;
			current = new_node;
		}
		current->_next = _sentinel;
		_sentinel->_prev = current;
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(uint64_t size, ElementType val) :
	_size{size}, _sentinel{std::make_shared<Node>()} {
	if (size > 0) {
		auto current = _sentinel;
		for (uint64_t i = 0; i < size; ++i) {
			auto new_node = std::make_shared<Node>(val);
			current->_next = new_node;
			new_node->_prev = current;
			current = new_node;
		}
		current->_next = _sentinel;
		_sentinel->_prev = current;
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const Iterator& begin, const Iterator& end) :
	_size{0}, _sentinel{std::make_shared<Node>()} {
	for (auto it = begin; it != end; ++it) {
		push_back(*it);
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(std::initializer_list<ElementType> list) :
	_size{0}, _sentinel{nullptr} {
	for (const auto& value : list) {
		push_back(value);
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList& ano_list) :
	_size{ano_list._size}, _sentinel{nullptr} {
	for (auto it = ano_list.begin(); it != ano_list.end(); ++it) {
		push_back(it->_val);
		++_size;
	}
}

template <typename ElementType>
DoublyLinkedList<ElementType>& DoublyLinkedList<ElementType>::operator=(const DoublyLinkedList& ano_list) {
	if (this != &ano_list) {
		this->clear();

		for (auto it = ano_list.begin(); it != ano_list.end(); ++it) {
			push_back(*it);
		}

		_size = ano_list._size;
	}
	return *this;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(DoublyLinkedList&& ano_list) noexcept
	: _size(ano_list._size), _sentinel(std::move(ano_list._sentinel)) {
	ano_list._size = 0;
	ano_list._sentinel = nullptr;
}

template <typename ElementType>
DoublyLinkedList<ElementType>& DoublyLinkedList<ElementType>::operator=(DoublyLinkedList&& ano_list) noexcept {
	if (this != &ano_list) {
		clear();

		_size = ano_list._size;
		_sentinel = std::move(ano_list._sentinel);

		ano_list._size = 0;
		ano_list._sentinel = nullptr;
	}
	return *this;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::push_front(const ElementType& val) {
	auto new_node = std::make_shared<Node>(val); // 创建新节点

	// 更新新节点的指针
	new_node->_next = _sentinel->_next;
	new_node->_prev = _sentinel;

	// 如果链表非空，更新原始链表的第一个节点的前驱指针
	if (_sentinel->_next) {
		_sentinel->_next->_prev = new_node;
	}

	// 更新 sentinel 的后继指针和链表大小
	_sentinel->_next = new_node;
	_size++;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::push_back(const ElementType& val) {
	auto new_node = std::make_shared<Node>(val); // 创建新节点

	// 更新新节点的指针
	new_node->_prev = _sentinel->_prev;
	new_node->_next = _sentinel;

	// 如果链表非空，更新原始链表的最后一个节点的后继指针
	if (_sentinel->_prev) {
		_sentinel->_prev->_next = new_node;
	}

	// 更新 sentinel 的前驱指针和链表大小
	_sentinel->_prev = new_node;
	_size++;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::insert(Iterator it, const ElementType& val) {
	// 创建新节点
	auto new_node = std::make_shared<Node>(val);

	// 更新新节点的指针
	new_node->_prev = it._current->_prev;
	new_node->_next = it._current;

	// 更新前驱节点的后继指针
	if (it._current->_prev) {
		it._current->_prev->_next = new_node;
	}

	// 更新当前节点的前驱指针
	it._current->_prev = new_node;

	// 如果插入位置在链表的开头，更新 sentinel 的后继指针
	if (it == begin()) {
		_sentinel->_next = new_node;
	}

	// 增加链表大小
	_size++;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::pop_back() {
	if (empty()) {
		throw std::out_of_range("Cannot pop from an empty list.");
	}

	auto to_remove = _sentinel->_prev; // 获取最后一个节点

	// 更新 sentinel 的前驱指针
	_sentinel->_prev = to_remove->_prev;

	// 更新最后一个节点的前驱节点的后继指针
	if (to_remove->_prev) {
		to_remove->_prev->_next = _sentinel;
	} else {
		_sentinel->_next = _sentinel; // 如果移除的是唯一节点，更新 sentinel 的后继指针
	}

	// 减少链表大小
	_size--;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::pop_front() {
	if (empty()) {
		throw std::out_of_range("Cannot pop from an empty list.");
	}

	auto to_remove = _sentinel->_next; // 获取第一个节点

	// 更新 sentinel 的后继指针
	_sentinel->_next = to_remove->_next;

	// 更新第一个节点的后继节点的前驱指针
	if (to_remove->_next) {
		to_remove->_next->_prev = _sentinel;
	} else {
		_sentinel->_prev = _sentinel; // 如果移除的是唯一节点，更新 sentinel 的前驱指针
	}

	// 减少链表大小
	_size--;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::clear() {
	auto current = _sentinel->_next; // 从第一个节点开始
	while (current != _sentinel) { // 直到到达 sentinel
		auto next_node = current->_next; // 暂存下一个节点
		current.reset(); // 释放当前节点
		current = next_node; // 移动到下一个节点
	}
	_sentinel->_next = _sentinel; // 重置 sentinel 的后继指针
	_sentinel->_prev = _sentinel; // 重置 sentinel 的前驱指针
	_size = 0; // 重置大小
}
}


#endif //DOUBLYLINKEDLIST_HPP
