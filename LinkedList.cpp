#include <cstdio>
#include <iostream>
#include <cstdint>

template <typename ElementType>
struct LinkedListNode {
private:
	ElementType _val{0};
	LinkedListNode* _prev{nullptr};
	LinkedListNode* _next{nullptr};

public:
	LinkedListNode() = default;
	explicit LinkedListNode(ElementType val);
};

template <typename ElementType>
using Node = LinkedListNode<ElementType>;

template <typename ElementType>
struct LinkedList {
private:
	Node<ElementType>* _head{nullptr};
	Node<ElementType>* _tail{nullptr};
	uint64_t _size{0};

public:
	explicit LinkedList() = default;
};

template <typename ElementType>
using list = LinkedList<ElementType>;

