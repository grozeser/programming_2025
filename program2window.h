#ifndef PROGRAM2WINDOW_H
#define PROGRAM2WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Program2Window; }
QT_END_NAMESPACE

class Program2Window : public QMainWindow {
    Q_OBJECT
public:
    Program2Window(QWidget *parent = nullptr);
    ~Program2Window();
private slots:
    void on_btnLoad_clicked();
private:
    Ui::Program2Window *ui;
};

#endif
