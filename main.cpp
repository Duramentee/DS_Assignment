#include <gtest/gtest.h>
#include "./DoublyLinkedList/DoublyLinkedList.hpp"

using namespace mystl;

// 单元测试类
class DoublyLinkedListTest : public ::testing::Test {
protected:
    // 在每个测试前初始化的操作
    void SetUp() override {
    }

    // 在每个测试后清理的操作
    void TearDown() override {
    }
};

// 测试构造函数（正常情况）
TEST_F(DoublyLinkedListTest, ConstructionHappyPath) {
    DoublyLinkedList<int> list{3, 10}; // 创建一个包含3个10的链表
    EXPECT_EQ(list.size(), 3); // 期望大小为3
    EXPECT_EQ(list.front(), 10); // 期望头部元素为10
    EXPECT_EQ(list.back(), 10);  // 期望尾部元素为10
}

// 测试构造函数（边界情况：空链表）
TEST_F(DoublyLinkedListTest, ConstructionEmptyList) {
    DoublyLinkedList<int> list; // 创建一个空链表
    EXPECT_TRUE(list.empty()); // 期望链表为空
    EXPECT_EQ(list.size(), 0); // 期望大小为0
}

// 测试添加元素（正常情况：添加到前面）
TEST_F(DoublyLinkedListTest, PushFront) {
    DoublyLinkedList<int> list;
    list.push_front(20); // 添加元素20到前面
    EXPECT_EQ(list.front(), 20); // 期望头部元素为20
    EXPECT_EQ(list.size(), 1); // 期望大小为1
}

// 测试添加元素（正常情况：添加到后面）
TEST_F(DoublyLinkedListTest, PushBack) {
    DoublyLinkedList<int> list;
    list.push_back(30); // 添加元素30到后面
    EXPECT_EQ(list.back(), 30); // 期望尾部元素为30
    EXPECT_EQ(list.size(), 1); // 期望大小为1
}

// 测试弹出元素（正常情况：从后面弹出）
TEST_F(DoublyLinkedListTest, PopBack) {
    DoublyLinkedList<int> list{2, 10}; // 创建包含两个10的链表
    list.pop_back(); // 从尾部弹出一个元素
    EXPECT_EQ(list.size(), 1); // 期望大小为1
    EXPECT_EQ(list.back(), 10); // 期望尾部元素为10
}

// 测试弹出元素（正常情况：从前面弹出）
TEST_F(DoublyLinkedListTest, PopFront) {
    DoublyLinkedList<int> list{2, 20}; // 创建包含两个20的链表
    list.pop_front(); // 从头部弹出一个元素
    EXPECT_EQ(list.size(), 1); // 期望大小为1
    EXPECT_EQ(list.front(), 20); // 期望头部元素为20
}

// 测试弹出元素（边界情况：从空链表弹出）
TEST_F(DoublyLinkedListTest, PopFromEmptyList) {
    DoublyLinkedList<int> list; // 创建一个空链表
    EXPECT_THROW(list.pop_back(), std::out_of_range); // 期望抛出异常
    EXPECT_THROW(list.pop_front(), std::out_of_range); // 期望抛出异常
}

// 测试清空链表
TEST_F(DoublyLinkedListTest, ClearList) {
    DoublyLinkedList<int> list{5, 30}; // 创建包含5个30的链表
    list.clear(); // 清空链表
    EXPECT_TRUE(list.empty()); // 期望链表为空
    EXPECT_EQ(list.size(), 0); // 期望大小为0
}

// 测试插入元素
TEST_F(DoublyLinkedListTest, Insert) {
    DoublyLinkedList<int> list{3, 40}; // 创建包含3个40的链表
    auto it = list.begin(); // 获取迭代器
    list.insert(it, 50); // 在头部插入50
    EXPECT_EQ(list.front(), 50); // 期望头部元素为50
    EXPECT_EQ(list.size(), 4); // 期望大小为4
}

// 测试拷贝构造函数
TEST_F(DoublyLinkedListTest, CopyConstructor) {
    DoublyLinkedList<int> original{3, 60}; // 创建原始链表
    DoublyLinkedList<int> copy = original; // 拷贝构造
    EXPECT_EQ(copy.size(), original.size()); // 期望大小相等
    EXPECT_EQ(copy.front(), original.front()); // 期望头部元素相等
}

// 测试移动构造函数
TEST_F(DoublyLinkedListTest, MoveConstructor) {
    DoublyLinkedList<int> original{3, 70}; // 创建原始链表
    DoublyLinkedList<int> moved = std::move(original); // 移动构造
    EXPECT_TRUE(original.empty()); // 原始链表应为空
    EXPECT_EQ(moved.size(), 3); // 移动后链表大小应为3
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // 初始化 Google Test
    return RUN_ALL_TESTS(); // 运行所有测试
}
