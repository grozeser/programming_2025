#include "program1window.h"
#include "ui_program1window.h"
#include "Shield.h"
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

Program1Window::Program1Window(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Program1Window) {
    ui->setupUi(this);

    // Принудительно задаем черный цвет текста через StyleSheet
    QString btnStyle = "background-color: rgb(255, 85, 127); color: black; font-weight: bold; border-radius: 3px;";
    ui->btnSaveJson->setStyleSheet(btnStyle);
    ui->btnLoadTxt->setStyleSheet(btnStyle);

    connect(ui->btnSaveJson, &QPushButton::clicked, this, &Program1Window::saveJson);
    connect(ui->btnLoadTxt, &QPushButton::clicked, this, &Program1Window::loadTxt);
}

Program1Window::~Program1Window() { delete ui; }

void Program1Window::saveJson() {
    Shield s;
    s.name = ui->nameEdit->text().trimmed();
    s.description = ui->descEdit->text().trimmed();
    s.type = ui->typeEdit->text().trimmed();
    // Поле protEdit должно быть типом QLineEdit в дизайнере[cite: 1]
    s.protection = ui->protEdit->text().trimmed();

    QString path = QFileDialog::getSaveFileName(this, "Сохранить", "data.json", "*.json");
    if (path.isEmpty()) return;

    QJsonArray arr;
    QFile f(path);
    if (f.exists() && f.open(QIODevice::ReadOnly)) {
        arr = QJsonDocument::fromJson(f.readAll()).array();
        f.close();
    }

    arr.append(s.toJson());
    if (f.open(QIODevice::WriteOnly)) {
        f.write(QJsonDocument(arr).toJson());
        f.close();
        QMessageBox::information(this, "Успех", "Данные сохранены.");
    }
}

void Program1Window::loadTxt() {
    QString path = QFileDialog::getOpenFileName(this, "Открыть TXT", "", "*.txt");
    if (path.isEmpty()) return;

    QFile f(path);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while (!f.atEnd()) {
            QString line = f.readLine();
            auto parts = line.split('=');
            if (parts.size() < 2) continue;
            QString k = parts[0].trimmed();
            QString v = parts[1].trimmed();
            if (k == "name") ui->nameEdit->setText(v);
            if (k == "description") ui->descEdit->setText(v);
            if (k == "type") ui->typeEdit->setText(v);
            if (k == "protection") ui->protEdit->setText(v);
        }
        f.close();
    }
}
