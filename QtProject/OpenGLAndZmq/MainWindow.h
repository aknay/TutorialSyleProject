#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "View3d.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void add3DView(View3D &view3D);

public slots:
    void onReceivedData(const QList<QByteArray>&);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
