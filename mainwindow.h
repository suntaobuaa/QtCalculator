#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void showtext_1();
    void showtext_2();
    void showtext_3();
    void showtext_4();
    void showtext_5();
    void showtext_6();
    void showtext_7();
    void showtext_8();
    void showtext_9();
    void showtext_10();
    void showtext_11();
    void showtext_12();
    void showtext_13();
    void showtext_14();
    void showtext_15();
    void showtext_16();
    void showtext_17();
    void showtext_18();
    void showtext_19();

    void showwaring();


private:
    Ui::MainWindow *ui;
    QString shurubiaodashi;
    bool ifaftercalcu=false;
    void beforeshuru();


};

#endif // MAINWINDOW_H
