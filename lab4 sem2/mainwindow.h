#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>

class Book {
public:
    QString author;
    QString title;
    QString code;
    QString content;
    QString type;
    QString genres;

    Book(QString a, QString t, QString c, QString cont, QString ty, QString g)
        : author(a), title(t), code(c), content(cont), type(ty), genres(g) {}

    bool saveToFile(QString filename) {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Автор: " << author << "\n";
            out << "Название: " << title << "\n";
            out << "Код: " << code << "\n";
            out << "Наполнение: " << content << "\n";
            out << "Тип: " << type << "\n";
            out << "Жанры: " << (genres.isEmpty() ? "Нет" : genres) << "\n";
            out << "----------------------\n";
            file.close();
            return true;
        }
        return false;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonReset_clicked();
    void on_pushButtonSave_clicked();

private:
    Ui::MainWindow *ui;
};
#endif
