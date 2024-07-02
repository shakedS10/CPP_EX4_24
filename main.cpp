//214695108 shakedshvartz2004@gmail.com
#include <QApplication>
#include "mainwindow.hpp"
#include "tree.hpp"
#include "node.hpp"
#include "complex.hpp"
#include <string>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Node<std::string>* root_node = new Node<std::string>("Root");
    Tree<std::string> tree(root_node);

    Node<std::string>* node1 = new Node<std::string>("Node1");
    Node<std::string>* node2 = new Node<std::string>("Node2");
    Node<std::string>* node3 = new Node<std::string>("Node3");
    Node<std::string>* node4 = new Node<std::string>("Node4");
    Node<std::string>* node5 = new Node<std::string>("Node5");
    Node<std::string>* node6 = new Node<std::string>("Node6");
    Node<std::string>* node7 = new Node<std::string>("Node7");
    Node<std::string>* node8 = new Node<std::string>("Node8");
    Node<std::string>* node9 = new Node<std::string>("Node9");


    tree.add_sub_node(root_node, node1);
    tree.add_sub_node(root_node, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node2, node6);
    tree.add_sub_node(node5, node7);
    // tree.add_sub_node(node4, node8);
    // tree.add_sub_node(node4, node9);



    // Node<double>* root_node = new Node<double>(1.1);
    // Tree<double> tree(root_node);

    // Node<double>* node1 = new Node<double>(1.2);
    // Node<double>* node2 = new Node<double>(1.3);
    // Node<double>* node3 = new Node<double>(1.4);
    // Node<double>* node4 = new Node<double>(1.5);
    // Node<double>* node5 = new Node<double>(1.6);
    // Node<double>* node6 = new Node<double>(1.7);


    // tree.add_sub_node(root_node, node1);
    // tree.add_sub_node(root_node, node2);
    // tree.add_sub_node(node1, node3);
    // tree.add_sub_node(node1, node4);
    // tree.add_sub_node(node2, node5);
    // tree.add_sub_node(node2, node6);


    // Node<Complex>* root_node = new Node<Complex>(Complex(1.1, 1.1));
    // Tree<Complex> tree(root_node);

    // Node<Complex>* node1 = new Node<Complex>(Complex(1.2, 1.2));
    // Node<Complex>* node2 = new Node<Complex>(Complex(1.3, 1.3));
    // Node<Complex>* node3 = new Node<Complex>(Complex(1.4, 1.4));
    // Node<Complex>* node4 = new Node<Complex>(Complex(1.5, 1.5));
    // Node<Complex>* node5 = new Node<Complex>(Complex(1.6, 1.6));

    // tree.add_sub_node(root_node, node1);
    // tree.add_sub_node(root_node, node2);
    // tree.add_sub_node(node1, node3);
    // tree.add_sub_node(node1, node4);
    // tree.add_sub_node(node2, node5);

    // cout << "Pre-order:" << endl;
    // for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
    //     cout << (*node)->getData() << " ";
    // } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    // cout << endl;
    // cout << "Post-order:" << endl;
    // for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
    //     cout << (*node)->getData() << " ";
    // } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    // cout << endl;
    // cout << "In-order:" << endl;
    // for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
    //     cout << (*node)->getData() << " ";
    // } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    // cout << endl;
    // cout << "BFS scan:" << endl;
    // for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
    //     cout << (*node)->getData() << " ";
    // } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    // cout << endl;
    // cout << "DFS scan:" << endl;

    // for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
    //     cout << (*node)->getData() << " ";
    // } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    // cout << endl;

    // cout << "Heap:" << endl;

    // for(auto node = tree.myHeap(); node != tree.end_myHeap(); ++node) {
    //     cout << (*node)->getData() << " ";
    // }
    // cout << endl;
    Tree<string>* ts = tree.convert_to_string_tree();
    if(ts == nullptr)
        cout << "hello"<<endl;


    // Create the MainWindow instance
    MainWindow w(ts);
    w.resize(1600, 900);  // Set the initial size of the MainWindow
    w.show();

    return a.exec();
}
