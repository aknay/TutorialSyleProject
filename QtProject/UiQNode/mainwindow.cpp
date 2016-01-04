#include "scenemodifier.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add3DView(View3D &view3D){
     ui->horizontalLayout->insertWidget(0,QWidget::createWindowContainer( &view3D ));
}



