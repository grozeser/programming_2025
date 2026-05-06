#ifndef PROGRAM1WINDOW_H
#define PROGRAM1WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Program1Window; }
QT_END_NAMESPACE

class Program1Window : public QMainWindow {
    Q_OBJECT
public:
    Program1Window(QWidget *parent = nullptr);
    ~Program1Window();

private slots:
    void saveJson();
    void loadTxt();

private:
    Ui::Program1Window *ui; // Указатель на ваш дизайн из редактора
};

#endif
