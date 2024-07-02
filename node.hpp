//214695108 shakedshvartz2004@gmail.com
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>



using namespace std;

template <typename T>
class Node {
    private:
        T data;
        vector<Node<T>*> kids = vector<Node<T>*>();


    public:
        Node(T data) {
            this->data = data;
            kids = vector<Node<T>*>();
        }

        ~Node() {
            for (int i = 0; i < kids.size(); i++) {
                delete kids[i];
            }
        }

        // ~Node() {
        //     for (int i = 0; i < kids.size(); i++) {
        //         delete kids[i];
        //     }
        //     delete this;
        // }

        void addKid(Node<T>* kid) {
            kids.push_back(kid);
        }

        void removeKid(Node<T>* kid) {
            for (int i = 0; i < kids.size(); i++) {
                if (kids[i] == kid) {
                    kids.erase(kids.begin() + i);
                    return;
                }
            }
        }

        void setData(T data) {
            this->data = data;
        }

        T& getData() {
            return data;
        }

        vector<Node<T>*> getKids() {
            return kids;
        }

        void print() {
            cout << data << endl;
            for (int i = 0; i < kids.size(); i++) {
                kids[i]->print();
            }
        }


        std::string toString() const {
            std::ostringstream oss;
            oss << data;
            return oss.str();
        }



};

