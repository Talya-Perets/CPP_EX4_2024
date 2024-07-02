//talyape123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"

TEST_CASE("Tree Basic Functionality") {
    Tree<int, 3> tree;  // Tree with max 3 children per node

    SUBCASE("Adding root") {
        Node<int> root(1);
        tree.add_root(&root);
        CHECK(tree.getRoot()->get_value() == 1);
    }

    SUBCASE("Adding children") {
        Node<int> root(1);
        tree.add_root(&root);
        Node<int> child1(2);
        Node<int> child2(3);
        Node<int> child3(4);
        tree.add_sub_node(&root, &child1);
        tree.add_sub_node(&root, &child2);
        tree.add_sub_node(&root, &child3);

        CHECK(root.get_childrens().size() == 3);
        CHECK(root.get_childrens()[0]->get_value() == 2);
        CHECK(root.get_childrens()[1]->get_value() == 3);
        CHECK(root.get_childrens()[2]->get_value() == 4);
    }

    SUBCASE("Adding too many children") {
        Node<int> root(1);
        tree.add_root(&root);

        Node<int> child1(2);
        Node<int> child2(3);
        Node<int> child3(4);
        Node<int> child4(5);

        tree.add_sub_node(&root, &child1);
        tree.add_sub_node(&root, &child2);
        tree.add_sub_node(&root, &child3);

        CHECK_THROWS_AS(tree.add_sub_node(&root, &child4), std::runtime_error);
    }

    SUBCASE("Removing children") {
        Node<int> root(1);
        tree.add_root(&root);

        Node<int> child1(2);
        Node<int> child2(3);

        tree.add_sub_node(&root, &child1);
        tree.add_sub_node(&root, &child2);

        CHECK(root.get_childrens().size() == 2);

        root.remove_children();

        CHECK(root.get_childrens().size() == 0);
    }
}

TEST_CASE("Binary Tree Iterators whith char") {
    Tree<char, 2> binary_tree;  // Binary tree with max 2 children per node

    // Add root node
    Node<char> root('A');
    binary_tree.add_root(&root);

    // Add nodes
    Node<char> nodeB('B');
    Node<char> nodeC('C');
    Node<char> nodeD('D');
    Node<char> nodeE('E');
    Node<char> nodeF('F');
    Node<char> nodeG('G');
    Node<char> nodeH('H');

    binary_tree.add_sub_node(&root, &nodeB);
    binary_tree.add_sub_node(&root, &nodeC);
    binary_tree.add_sub_node(&nodeB, &nodeD);
    binary_tree.add_sub_node(&nodeB, &nodeE);
    binary_tree.add_sub_node(&nodeC, &nodeF);
    binary_tree.add_sub_node(&nodeC, &nodeG);
    binary_tree.add_sub_node(&nodeE, &nodeH);

    SUBCASE("Pre-Order Iterator") {
        std::vector<char> expected = {'A', 'B', 'D', 'E', 'H', 'C', 'F', 'G'};
        std::vector<char> result;

        for (auto it = binary_tree.begin_pre_order(); it != binary_tree.end_pre_order(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("Post-Order Iterator") {
        std::vector<char> expected = {'D', 'H', 'E', 'B', 'F', 'G', 'C', 'A'};
        std::vector<char> result;

        for (auto it = binary_tree.begin_post_order(); it != binary_tree.end_post_order(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("In-Order Iterator") {
        std::vector<char> expected = {'D', 'B', 'H', 'E', 'A', 'F', 'C', 'G'};
        std::vector<char> result;

        for (auto it = binary_tree.begin_in_order(); it != binary_tree.end_in_order(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS Iterator") {
        std::vector<char> expected = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        std::vector<char> result;

        for (auto it = binary_tree.begin_bfs_scan(); it != binary_tree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS Iterator") {
        std::vector<char> expected = {'A', 'B', 'D', 'E', 'H', 'C', 'F', 'G'};
        std::vector<char> result;

        for (auto it = binary_tree.begin_dfs_scan(); it != binary_tree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    // Optionally add more subcases for other iterators or functionalities
}

TEST_CASE(" Tree whith K=4 Iterators with double data type") {
    Tree<double, 4> binary_tree;  // Binary tree with max 4 children per node

    // Define the binary tree once for the entire test case
    Node<double> root(1.0);
    binary_tree.add_root(&root);

    // Add nodes
    Node<double> node2(2.0);
    Node<double> node3(3.0);
    Node<double> node4(4.0);
    Node<double> node5(5.0);
    Node<double> node6(6.0);
    Node<double> node7(7.0);
    Node<double> node8(8.0);
    Node<double> node9(9.0);
    Node<double> node10(10.0);
    Node<double> node11(11.0);
    Node<double> node12(12.0);

    binary_tree.add_sub_node(&root, &node2);
    binary_tree.add_sub_node(&root, &node3);
    binary_tree.add_sub_node(&root, &node4);
    binary_tree.add_sub_node(&root, &node5);
    binary_tree.add_sub_node(&node2, &node6);
    binary_tree.add_sub_node(&node2, &node7);
    binary_tree.add_sub_node(&node3, &node8);
    binary_tree.add_sub_node(&node3, &node9);
    binary_tree.add_sub_node(&node4, &node10);
    binary_tree.add_sub_node(&node4, &node11);
    binary_tree.add_sub_node(&node5, &node12);

    SUBCASE("Pre-Order Iterator") {
        std::vector<double> expected = {1.0, 2.0, 6.0, 7.0, 3.0, 8.0, 9.0, 4.0, 10.0, 11.0, 5.0, 12.0};
        std::vector<double> result;

        for (auto it = binary_tree.begin_pre_order(); it != binary_tree.end_pre_order(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("Post-Order Iterator") {
        std::vector<double> expected = {1.0, 2.0, 6.0, 7.0, 3.0, 8.0, 9.0, 4.0, 10.0, 11.0, 5.0, 12.0};
        std::vector<double> result;

        for (auto it = binary_tree.begin_post_order(); it != binary_tree.end_post_order(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("In-Order Iterator") {
        std::vector<double> expected = {1.0, 2.0, 6.0, 7.0, 3.0, 8.0, 9.0, 4.0, 10.0, 11.0, 5.0, 12.0};
        std::vector<double> result;

        for (auto it = binary_tree.begin_in_order(); it != binary_tree.end_in_order(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS Iterator") {
        std::vector<double> expected = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
        std::vector<double> result;

        for (auto it = binary_tree.begin_bfs_scan(); it != binary_tree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS Iterator") {
        std::vector<double> expected = {1.0, 2.0, 6.0, 7.0, 3.0, 8.0, 9.0, 4.0, 10.0, 11.0, 5.0, 12.0};
        std::vector<double> result;

        for (auto it = binary_tree.begin_dfs_scan(); it != binary_tree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    // Optionally add more subcases for other iterators or functionalities
}

TEST_CASE("binary tree") {
    Node<int> root(1);
    Node<int> n2(2);
    Node<int> n3(3);
    Node<int> n4(4);
    Node<int> n5(5);
    Node<int> n6(6);
    Node<int> n7(7);

    Tree<int, 2> tree;
    tree.add_root(&root);

    tree.add_sub_node(&root, &n2);
    tree.add_sub_node(&root, &n3);
    tree.add_sub_node(&n2, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n3, &n6);
    tree.add_sub_node(&n6, &n7);

    /*
    tree should look like this:
              1
           /      \
          2       3
         / \     /
        4   5   6 
               /
              7
    */

    SUBCASE("in order traversal") {
        int expected[] = {4, 2, 5, 1, 7, 6, 3};
        int i = 0;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it, ++i) {
            CHECK((it)->get_value() == expected[i]);
        }
    }

    SUBCASE("pre order traversal") {
        int expected[] = {1, 2, 4, 5, 3, 6, 7};
        int i = 0;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it, ++i) {
            CHECK((it)->get_value() == expected[i]);
        }
    }

    SUBCASE("post order traversal") {
        int expected[] = {4, 5, 2, 7, 6, 3, 1};
        int i = 0;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it, ++i) {
            CHECK((it)->get_value() == expected[i]);
        }
    }

    SUBCASE("bfs traversal") {
        int expected[] = {1, 2, 3, 4, 5, 6, 7};
        int i = 0;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it, ++i) {
            CHECK((it)->get_value() == expected[i]);
        }
    }

}