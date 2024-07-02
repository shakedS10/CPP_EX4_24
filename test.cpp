//214695108 shakedshvartz2004@gmail.com
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


TEST_CASE("test complex"){
    Node<Complex>* root_node = new Node<Complex>(Complex(1.1, 1.1));
    Tree<Complex> tree(root_node);

    Node<Complex>* node1 = new Node<Complex>(Complex(1.2, 1.2));
    Node<Complex>* node2 = new Node<Complex>(Complex(1.3, 1.3));
    Node<Complex>* node3 = new Node<Complex>(Complex(1.4, 1.4));
    Node<Complex>* node4 = new Node<Complex>(Complex(1.5, 1.5));
    Node<Complex>* node5 = new Node<Complex>(Complex(1.6, 1.6));


    tree.add_sub_node(root_node, node1);
    tree.add_sub_node(root_node, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);

    auto it = tree.begin_pre_order();
    CHECK((*it)->getData().getReal() == 1.1);
    CHECK((*it)->getData().getImag() == 1.1);
    ++it;
    CHECK((*it)->getData().getReal() == 1.2);
    CHECK((*it)->getData().getImag() == 1.2);
    ++it;
    CHECK((*it)->getData().getReal() == 1.4);
    CHECK((*it)->getData().getImag() == 1.4);
    ++it;


    auto it2 = tree.begin_post_order();
    CHECK((*it2)->getData().getReal() == 1.4);
    CHECK((*it2)->getData().getImag() == 1.4);
    ++it2;
    CHECK((*it2)->getData().getReal() == 1.5);
    CHECK((*it2)->getData().getImag() == 1.5);
    ++it2;
    CHECK((*it2)->getData().getReal() == 1.2);
    CHECK((*it2)->getData().getImag() == 1.2);

}


TEST_CASE("test string"){
    Node<std::string>* root_node = new Node<std::string>("Root");
    Tree<std::string> tree(root_node);

    Node<std::string>* node1 = new Node<std::string>("Node1");
    Node<std::string>* node2 = new Node<std::string>("Node2");
    Node<std::string>* node3 = new Node<std::string>("Node3");
    Node<std::string>* node4 = new Node<std::string>("Node4");
    Node<std::string>* node5 = new Node<std::string>("Node5");
    Node<std::string>* node6 = new Node<std::string>("Node6");

    tree.add_sub_node(root_node, node1);
    tree.add_sub_node(root_node, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node2, node6);

    auto it = tree.begin_pre_order();
    CHECK((*it)->getData() == "Root");
    ++it;
    CHECK((*it)->getData() == "Node1");
    ++it;
    CHECK((*it)->getData() == "Node3");
    ++it;
    CHECK((*it)->getData() == "Node4");
    ++it;
    CHECK((*it)->getData() == "Node2");
    ++it;
    CHECK((*it)->getData() == "Node5");
    ++it;
    CHECK((*it)->getData() == "Node6");
    ++it;
}

TEST_CASE("test int"){
    Node<int>* root_node = new Node<int>(1);
    Tree<int> tree(root_node);

    Node<int>* node1 = new Node<int>(2);
    Node<int>* node2 = new Node<int>(3);
    Node<int>* node3 = new Node<int>(4);
    Node<int>* node4 = new Node<int>(5);
    Node<int>* node5 = new Node<int>(6);
    Node<int>* node6 = new Node<int>(7);

    tree.add_sub_node(root_node, node1);
    tree.add_sub_node(root_node, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node2, node6);

    auto it = tree.begin_pre_order();
    CHECK((*it)->getData() == 1);
    ++it;
    CHECK((*it)->getData() == 2);
    ++it;
    CHECK((*it)->getData() == 4);
    ++it;
    CHECK((*it)->getData() == 5);
    ++it;
    CHECK((*it)->getData() == 3);
    ++it;
    CHECK((*it)->getData() == 6);
    ++it;
    CHECK((*it)->getData() == 7);
    ++it;
}
