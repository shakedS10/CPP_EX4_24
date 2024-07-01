#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "node.hpp"

using namespace std;

template <typename T>
class Tree;


template <typename T>
class pre_order_iterator {
    private:
        Node<T>* current;
        std::vector<Node<T>*> stack = std::vector<Node<T>*>();

    public:
        pre_order_iterator(Node<T>* root) {
            current = root;
            stack.push_back(root);
        }

        Node<T>* operator*() {
            return current;
        }

        pre_order_iterator<T>& operator++() {
            if (stack.size() == 0) {
                current = nullptr;
                return *this;
            }
            current = stack.back();
            stack.pop_back();
            for (int i = current->getKids().size() - 1; i >= 0; i--) {
                stack.push_back(current->getKids()[i]);
            }
            if(stack.size() == 0) {
                current = nullptr;
                return *this;
            }
            current = stack.back();
            return *this;
        }

        bool operator!=(const pre_order_iterator<T>& other) {
            return current != other.current;
        }

        
};

template <typename T>
class post_order_iterator {
    private:
        std::vector<Node<T>*> stack = std::vector<Node<T>*>();
        int index = -1;
    public:
        post_order_iterator(Node<T>* root) {
            if(root != nullptr){
                post_order_helper(root);
                index = 0;
            }
        }

        Node<T>* operator*() {
            return stack[index];
        }

        post_order_iterator<T>& operator++() {
            index++;
            if(index >= stack.size()) {
                index = -1;
            }
            return *this;
        }

        bool operator!=(const post_order_iterator<T>& other) {
            return index != other.index;
        }

        void post_order_helper(Node<T>* root) {
            if(root == nullptr) {
                return ;
            }

            for (int i = 0; i < root->getKids().size(); i++) {
                post_order_helper(root->getKids()[i]);
            }
            stack.push_back(root);
        }
};

template <typename T>
class in_order_iterator {
    private:
        int counter = -1;
        std::vector<Node<T>*> stack = std::vector<Node<T>*>();
        
        

    public:
        in_order_iterator(Node<T>* root) {
            if(root != nullptr) {
                in_order_helper(root);
                counter = 0;
            }
        }

        Node<T>* operator*() {
            return stack[counter];
        }

        in_order_iterator<T>& operator++() {
            counter++;
            if(counter >= stack.size()) {
                counter = -1;
            }
            return *this;
        }

        bool operator!=(const in_order_iterator<T>& other) {
            return counter != other.counter;
        }

        void in_order_helper(Node<T>* root) {
            if(root == nullptr) {
                return ;
            }

            if(root->getKids().size() == 0) {
                stack.push_back(root);
                return;
            }
            if(root->getKids().size() == 1) {
                in_order_helper(root->getKids()[0]);
                stack.push_back(root);
                return;
            }
            in_order_helper(root->getKids()[0]);
            stack.push_back(root);
            in_order_helper(root->getKids()[1]);

            //     in_order_helper(root->getKids()[0]);
            // stack.push_back(root);
            // in_order_helper(root->getKids()[1]);
        }
};

template <typename T>
class bfs_scan_iterator {
    private:
        Node<T>* current;
        std::vector<Node<T>*> queue = std::vector<Node<T>*>();

    public:
        bfs_scan_iterator(Node<T>* root) {
            current = root;
            queue.push_back(root);
        }

        Node<T>* operator*() {
            return current;
        }

        bfs_scan_iterator<T>& operator++() {
            if (queue.size() == 0) {
                current = nullptr;
                return *this;
            }
            current = queue.front();
            queue.erase(queue.begin());
            for (int i = 0; i < current->getKids().size(); i++) {
                queue.push_back(current->getKids()[i]);
            }
            if(queue.size()>0) {
                current = queue.front();
                return *this;
            }
            current = nullptr;
            return *this;
        }

        bool operator!=(const bfs_scan_iterator<T>& other) {
            return current != other.current;
        }
};


template <typename T>
class dfs_scan_iterator {
    private:
        Node<T>* current;
        std::vector<Node<T>*> stack = std::vector<Node<T>*>();

    public:
        dfs_scan_iterator(Node<T>* root) {
            current = root;
            stack.push_back(root);
        }

        Node<T>* operator*() {
            return current;
        }

        dfs_scan_iterator<T>& operator++() {
            if (stack.size() == 0) {
                current = nullptr;
                return *this;
            }
            current = stack.back();
            stack.pop_back();
            for (int i = current->getKids().size() - 1; i >= 0; i--) {
                stack.push_back(current->getKids()[i]);
            }
            if(stack.size()>0) {
                current = stack.back();
                return *this;
            }
            current = nullptr;
            return *this;
        }

        bool operator!=(const dfs_scan_iterator<T>& other) {
            return current != other.current;
        }
};



template <typename T>
class my_heap_iterator{

    private:
        int counter = -1;
        std::vector<Node<T>*> stack = std::vector<Node<T>*>();

    public:
        my_heap_iterator(Tree<T>* root) {
            
            if(root != nullptr) {
                for(auto node = root->begin_bfs_scan(); node != root->end_bfs_scan(); ++node) {
                    stack.push_back(*node);
                }
                counter = 0;
                std::make_heap(stack.begin(), stack.end(), [](Node<T>* a, Node<T>* b) {return a->getData() > b->getData();});
            }
        }

        Node<T>* operator*() {
            return stack[counter];
        }

        my_heap_iterator<T>& operator++() {
            counter++;
            if(counter >= stack.size()) {
                counter = -1;
            }
            return *this;
        }

        bool operator!=(const my_heap_iterator<T>& other) {
            return counter != other.counter;
        }

};

template <typename T>
class Tree {
    private:
        Node<T>* root;

    public:
        Tree(Node<T>* root = nullptr) {
            this->root = root;
        }

        ~Tree() {
            delete root;
        }

        void add_root(Node<T>* node) {
            root = node;
        }

        void add_sub_node(Node<T>* parent, Node<T>* child) {
            parent->addKid(child);
        }

        Node<T>* get_root() {
            return root;
        }

        pre_order_iterator<T> begin_pre_order() {
            return pre_order_iterator<T>(root);
        }

        pre_order_iterator<T> end_pre_order() {
            return pre_order_iterator<T>(nullptr);
        }

        post_order_iterator<T> begin_post_order() {
            return post_order_iterator<T>(root);
        }

        post_order_iterator<T> end_post_order() {
            return post_order_iterator<T>(nullptr);
        }

        in_order_iterator<T> begin_in_order() {
            return in_order_iterator<T>(root);
        }

        in_order_iterator<T> end_in_order() {
            return in_order_iterator<T>(nullptr);
        }

        bfs_scan_iterator<T> begin_bfs_scan() {
            return bfs_scan_iterator<T>(root);
        }

        bfs_scan_iterator<T> end_bfs_scan() {
            return bfs_scan_iterator<T>(nullptr);
        }

        dfs_scan_iterator<T> begin_dfs_scan() {
            return dfs_scan_iterator<T>(root);
        }

        dfs_scan_iterator<T> end_dfs_scan() {
            return dfs_scan_iterator<T>(nullptr);
        }

        my_heap_iterator<T> myHeap() {
            return my_heap_iterator<T>(this);
        }

        my_heap_iterator<T> end_myHeap() {
            return my_heap_iterator<T>(nullptr);
        }


};



