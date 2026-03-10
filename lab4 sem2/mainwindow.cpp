#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::on_resetButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_resetButton_clicked()
{
    ui->authorLineEdit->clear();
    ui->titleLineEdit->clear();
    ui->codeLineEdit->clear();
    ui->fillingLineEdit->clear();
    ui->typeComboBox->setCurrentIndex(0);
    ui->electronicComboBox->setCurrentIndex(0);
    ui->detectiveCheckBox->setChecked(false);
    ui->fantasyCheckBox->setChecked(false);
    ui->novelCheckBox->setChecked(false);
}

bool MainWindow::validateFields(QString& errorField)
{

    QRegularExpression authorRe("^[А-Я][а-я]+\\s[А-Я][а-я]+$");
    if (!authorRe.match(ui->authorLineEdit->text()).hasMatch()) { errorField = "Автор"; return false; }

    QRegularExpression titleRe("^\".*\"$");
    if (!titleRe.match(ui->titleLineEdit->text()).hasMatch()) { errorField = "Название"; return false; }

    QRegularExpression codeRe("^\\d{3}-\\d{4}$");
    if (!codeRe.match(ui->codeLineEdit->text()).hasMatch()) { errorField = "Код"; return false; }

    QRegularExpression fillingRe("^(\\d+)/(\\d+)$");
    QRegularExpressionMatch match = fillingRe.match(ui->fillingLineEdit->text());
    if (!match.hasMatch()) { errorField = "Наполнение"; return false; }
    int first = match.captured(1).toInt();
    int second = match.captured(2).toInt();
    if (second >= first) { errorField = "Наполнение"; return false; }

    return true;
}

void MainWindow::on_saveButton_clicked()
{
    QString errorField;
    if (!validateFields(errorField)) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в поле: " + errorField);
        return;
    }

    QStringList genres;
    if (ui->detectiveCheckBox->isChecked()) genres << "Детектив";
    if (ui->fantasyCheckBox->isChecked()) genres << "Фантастика";
    if (ui->novelCheckBox->isChecked()) genres << "Роман";

    Book b(
        ui->authorLineEdit->text(),
        ui->titleLineEdit->text(),
        ui->codeLineEdit->text(),
        ui->fillingLineEdit->text(),
        ui->typeComboBox->currentText(),
        ui->electronicComboBox->currentText(),
        genres
    );

    b.saveToFile("result.txt");
    QMessageBox::information(this, "Успех", "Данные успешно сохранены!");
}
