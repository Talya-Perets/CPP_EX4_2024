//talyape123@gmail.com

#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
using namespace std;


void printTree(Node<double>* node, int level = 0) {
    if (node == nullptr) return;

    // Print the current node
    cout << string(level, ' ') << node->get_value() << endl;

    // Print each child recursively
    for (size_t i = 0; i < node->get_childrens().size(); ++i) {
        printTree(node->get_childrens()[i], level + 1);
    }
}


int main()
{

    Node<double> root_node(1.1);
    Tree<double,2> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

tree.draw(800,600);

    cout << " root = " << tree.getRoot()->get_value() << endl;
    for (size_t i = 0; i < tree.getRoot()->get_childrens().size(); ++i) {
      cout<<"sun "<<i;
        cout<<tree.getRoot()->get_childrens()[i]->get_value()<<endl;
    }

   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */
cout<<"preOrde : "<<endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << (node)->get_value() << endl;
        
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

cout<<"postOrder : "<<endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << (node)->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1


cout<<"inOrder : "<<endl;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << (node)->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

cout<<"bfs : "<<endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << (node)->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    

    // cout << tree; // Should print the graph using GUI.
    Node<double> root(1.1);
    Node<double> n11(1.2);
    Node<double> n22(1.3);
    Node<double> n33(1.4);
    Node<double> n44(1.5);
    Node<double> n55(1.6);


    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(&root);
    three_ary_tree.add_sub_node(&root, &n11);
    three_ary_tree.add_sub_node(&root, &n22);
    three_ary_tree.add_sub_node(&root, &n33);
    three_ary_tree.add_sub_node(&n11, &n44);
    three_ary_tree.add_sub_node(&n22, &n55);
three_ary_tree.draw(800,600);
     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    Node<Complex> root_complex(Complex(1.1, 2.2));
    Tree<Complex, 2> treeComp; // Binary tree that contains Complex numbers.

    // Adding nodes to the tree
    treeComp.add_root(&root_complex);
    Node<Complex> nc1(Complex(2.2, 2.3));
    Node<Complex> nc2(Complex(2.3, 2.4));
    Node<Complex> nc3(Complex(2.4, 2.5));
    Node<Complex> nc4(Complex(2.5, 2.6));
    Node<Complex> nc5(Complex(2.6, 2.7));

    treeComp.add_sub_node(&root_complex, &nc1);
    treeComp.add_sub_node(&root_complex, &nc2);
    treeComp.add_sub_node(&nc1, &nc3);
    treeComp.add_sub_node(&nc1, &nc4);
    treeComp.add_sub_node(&nc2, &nc5);

    treeComp.draw(800, 600); // Displaying the tree with GUI

    // Printing root value
    cout << " root = " << treeComp.getRoot()->get_value() << endl;

    // Printing children of the root node
    for (size_t i = 0; i < treeComp.getRoot()->get_childrens().size(); ++i) {
        cout << "sub " << i << ": ";
        cout << treeComp.getRoot()->get_childrens()[i]->get_value() << endl;
    }

    // Traversing and printing tree using different iterators
    cout << "preOrder : " << endl;
    for (auto node = treeComp.begin_pre_order(); node != treeComp.end_pre_order(); ++node) {
        cout << (node)->get_value() << endl;
    }

    cout << "postOrder : " << endl;
    for (auto node = treeComp.begin_post_order(); node != treeComp.end_post_order(); ++node) {
        cout << (node)->get_value() << endl;
    }

    cout << "inOrder : " << endl;
    for (auto node = treeComp.begin_in_order(); node != treeComp.end_in_order(); ++node) {
        cout << (node)->get_value() << endl;
    }

    cout << "bfs : " << endl;
    for (auto node = treeComp.begin_bfs_scan(); node != treeComp.end_bfs_scan(); ++node) {
        cout << (node)->get_value() << endl;
    }
}
