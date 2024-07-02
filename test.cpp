#include "doctest.h"
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"




TEST_CASE("invalid iterators"){
    Node<Complex>* root_node = new Node<Complex>(Complex(1.1, 1.1));
    Tree<Complex> tree(root_node);

    Node<Complex>* node1 = new Node<Complex>(Complex(1.2, 1.2));
    Node<Complex>* node2 = new Node<Complex>(Complex(1.3, 1.3));
    Node<Complex>* node3 = new Node<Complex>(Complex(1.4, 1.4));
    Node<Complex>* node4 = new Node<Complex>(Complex(1.5, 1.5));
    Node<Complex>* node5 = new Node<Complex>(Complex(1.6, 1.6));
    Node<Complex>* node6 = new Node<Complex>(Complex(1.7, 1.7));

    tree.add_sub_node(root_node, node1);
    tree.add_sub_node(root_node, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node1, node6);


    CHECK_THROWS(tree.begin_pre_order());
    CHECK_THROWS(tree.begin_post_order());
    CHECK_THROWS(tree.begin_in_order());


}