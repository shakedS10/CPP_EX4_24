#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "TreeWidget.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(Tree<std::string>* tree, QWidget* parent = nullptr);
    ~MainWindow();

private:
    Tree<std::string>* tree;
    TreeWidget* treeWidget;

    void initializeUI();
};

#endif // MAINWINDOW_H
