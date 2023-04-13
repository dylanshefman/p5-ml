// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"


TEST(empty_true) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
}

TEST(empty_false) {
    BinarySearchTree<int> tree;
    tree.insert(4);
    ASSERT_FALSE(tree.empty());
}

TEST(height_empty) {
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.height(), 0u);
}

TEST(height_1_elt) {
    BinarySearchTree<int> tree;
    tree.insert(44);
    ASSERT_EQUAL(tree.height(), 1u);
}

TEST(height_stick) {
    BinarySearchTree<int> tree;
    for (int i = 0; i < 10; i++) {
        tree.insert(i);
    }
    ASSERT_EQUAL(tree.height(), 10u);
}

TEST(height_complex) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(5);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);
    ASSERT_EQUAL(tree.height(), 5u);
}

TEST(size_empty) {
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.size(), 0u);
}

TEST(size_stick) {
    BinarySearchTree<int> tree;
    for (int i = 0; i < 10; i++) {
        tree.insert(i);
    }
    ASSERT_EQUAL(tree.size(), 10u);
}

TEST(size_symmetrical) {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(8);
    tree.insert(12);
    tree.insert(7);
    tree.insert(9);
    tree.insert(11);
    tree.insert(13);
    ASSERT_EQUAL(tree.size(), 7u);
}

TEST(traverse_inorder_empty) {
    std::ostringstream os;
    BinarySearchTree<int> tree;
    tree.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "");
}

TEST(traverse_inorder_5) {
    std::ostringstream os;
    BinarySearchTree<int> tree;
    for (int i = 4; i >= 0; i--) {
        tree.insert(i);
    }
    std::string expected = "0 1 2 3 4 ";
    tree.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), expected);
}

TEST(traverse_preorder_empty) {
    std::ostringstream os;
    BinarySearchTree<int> tree;
    tree.traverse_preorder(os);
    ASSERT_EQUAL(os.str(), "");
}

TEST(traverse_preorder_7) {
    std::ostringstream os;
    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    std::string expected = "4 2 1 3 6 5 7 ";
    tree.traverse_preorder(os);
    ASSERT_EQUAL(os.str(), expected);
}

TEST_MAIN()
