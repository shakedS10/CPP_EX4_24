/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main() {
    Node<double>* root_node = new Node<double>(1.1);
    Tree<double> tree(root_node);

    Node<double>* node1 = new Node<double>(1.2);
    Node<double>* node2 = new Node<double>(1.3);
    Node<double>* node3 = new Node<double>(1.4);
    Node<double>* node4 = new Node<double>(1.5);
    Node<double>* node5 = new Node<double>(1.6);
    
    tree.add_sub_node(root_node, node1);
    tree.add_sub_node(root_node, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);


    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    
    cout << "Pre-order:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << (*node)->getData() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Post-order:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << (*node)->getData() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In-order:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << (*node)->getData() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "BFS scan:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << (*node)->getData() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS scan:" << endl;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << (*node)->getData() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Heap:" << endl;

    for(auto node = tree.myHeap(); node != tree.end_myHeap(); ++node) {
        cout << (*node)->getData() << endl;
    }


    return 0;
}
