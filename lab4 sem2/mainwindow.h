#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QStringList>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Book {
    QString author;
    QString title;
    QString code;
    QString filling;
    QString type;
    QString electronic;
    QStringList genres;

    Book(const QString& a, const QString& t, const QString& c, const QString& f,
         const QString& ty, const QString& e, const QStringList& g)
        : author(a), title(t), code(c), filling(f), type(ty), electronic(e), genres(g) {}

    void saveToFile(const QString& filename) {
        QFile file(filename);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Автор: " << author << "\n";
            out << "Название: " << title << "\n";
            out << "Код: " << code << "\n";
            out << "Наполнение: " << filling << "\n";
            out << "Тип издания: " << type << "\n";
            out << "Электронная версия: " << electronic << "\n";
            out << "Жанры: " << genres.join(", ") << "\n";
            out << "----------------------\n";
            file.close();
        }
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_resetButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;

    bool validateFields(QString& errorField);
};

#endif 
