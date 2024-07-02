#include "mainwindow.hpp"
#include <QSplitter>
#include <QVBoxLayout>
#include <QString>

MainWindow::MainWindow(Tree<std::string>* tree, QWidget* parent)
    : QMainWindow(parent), tree(tree) {
    initializeUI();
}

MainWindow::~MainWindow() {}

void MainWindow::initializeUI() {
    auto* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    auto* splitter = new QSplitter(Qt::Horizontal, centralWidget);

    treeWidget = new TreeWidget(tree, splitter);

    setWindowTitle("Tree Visualizer");

}
