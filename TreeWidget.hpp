//214695108 shakedshvartz2004@gmail.com
#ifndef TREEWIDGET_HPP
#define TREEWIDGET_HPP

#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QWidget>
#include "tree.hpp"

class TreeWidget : public QWidget {
    Q_OBJECT

public:
    explicit TreeWidget(Tree<string>* tree, QWidget* parent = nullptr);
    void drawTree(Node<std::string>* node, QGraphicsScene* scene, QGraphicsItem* parentItem = nullptr, int level = 0, int xOffset = 0);
    

private:
    Tree<std::string>* tree;
    QGraphicsScene* scene;
    QGraphicsView* view;

    // Node size and spacing
    const int nodeWidth = 80;  // Width of each node
    const int nodeHeight = 40;  // Height of each node
    const int verticalSpacing = 80;  // Vertical distance between levels
    const int initialHorizontalSpacing = 250;  // Initial horizontal distance between sibling nodes
    const double spacingDecayFactor = 0.7;  // Factor by which spacing decreases each level
    const int minHorizontalSpacing = 50;  // Minimum horizontal spacing between nodes
};

#endif // TREEWIDGET_HPP
