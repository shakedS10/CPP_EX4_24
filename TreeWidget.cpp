//214695108 shakedshvartz2004@gmail.com
#include "TreeWidget.hpp"
#include "qboxlayout.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QString>
#include <QResizeEvent>

TreeWidget::TreeWidget(Tree<string> *tree, QWidget* parent)
    : QWidget(parent), tree(tree) {
    // Initialize the QGraphicsScene and QGraphicsView
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    // Set the minimum size to make the tree widget larger
    view->setMinimumSize(1200, 800);

    // Draw the tree
    drawTree(tree->get_root(), scene);
}

void TreeWidget::drawTree(Node<std::string>* node, QGraphicsScene* scene, QGraphicsItem* parentItem, int level, int xOffset) {
    if (!node) return;

    // Create a text item for the node's data
    QGraphicsTextItem* textItem = new QGraphicsTextItem(QString::fromStdString(node->toString()));
    textItem->setPos(xOffset, level * verticalSpacing);  // Adjust positioning for better view
    textItem->setTextWidth(nodeWidth);  // Set the width for text wrapping
    textItem->setDefaultTextColor(Qt::cyan);
    textItem->setFont(QFont("Arial", 12));  // Set font size to make the text larger
    scene->addItem(textItem);

    // Draw lines to children
    if (parentItem) {
        QGraphicsLineItem* lineItem = new QGraphicsLineItem(parentItem->x() + nodeWidth / 2, parentItem->y() + nodeHeight, xOffset + nodeWidth / 2, textItem->y());
        lineItem->setPen(QPen(Qt::white, 2));  // Make the line thicker
        scene->addItem(lineItem);
    }

    // Draw children recursively
    if (!node->getKids().empty()) {
        // Compute the horizontal spacing for the current level
        int spacing = std::max(minHorizontalSpacing, int(initialHorizontalSpacing * std::pow(spacingDecayFactor, level)));
        // Compute the total width needed for child nodes
        //int childCount = node->getKids().size();
        int totalChildWidth = /*(childCount - 1) */ spacing;
        //totalChildWidth = totalChildWidth / (childCount-1);
        int startX = xOffset - totalChildWidth / 2;

        for (auto kid : node->getKids()) {
            drawTree(kid, scene, textItem, level + 1, startX);
            startX += spacing;
        }
    }
}
