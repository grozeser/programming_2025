#include "program2window.h"
#include "ui_program2window.h"
#include "Shield.h"
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <algorithm>
#include <QMessageBox>

Program2Window::Program2Window(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Program2Window) {
    ui->setupUi(this);
}

Program2Window::~Program2Window() { delete ui; }

void Program2Window::on_btnLoad_clicked() {
    QString path = QFileDialog::getOpenFileName(this, "Загрузить JSON", "", "*.json");
    if (path.isEmpty()) return;

    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) return;
    QJsonArray sourceArr = QJsonDocument::fromJson(f.readAll()).array();
    f.close();

    QList<Shield> okList, badList;
    for (const QJsonValue& v : sourceArr) {
        Shield s = Shield::fromJson(v.toObject());
        if (s.isValid()) okList.append(s);
        else badList.append(s);
    }

    // Сортировка корректных данных в памяти (Я -> А)[cite: 1]
    std::sort(okList.begin(), okList.end(), [](const Shield &a, const Shield &b) {
        return a.name > b.name;
    });

    // Вывод в Таблицу 1
    ui->tableCorrect->setRowCount(okList.size());
    ui->tableCorrect->setColumnCount(4);
    QJsonArray okJson;
    for (int i = 0; i < okList.size(); ++i) {
        ui->tableCorrect->setItem(i, 0, new QTableWidgetItem(okList[i].name));
        ui->tableCorrect->setItem(i, 1, new QTableWidgetItem(okList[i].description));
        ui->tableCorrect->setItem(i, 2, new QTableWidgetItem(okList[i].protection));
        ui->tableCorrect->setItem(i, 3, new QTableWidgetItem(okList[i].type));
        okJson.append(okList[i].toJson());
    }

    // Вывод в Таблицу 2 с точечной покраской ошибок[cite: 1]
    ui->tableError->setRowCount(badList.size());
    ui->tableError->setColumnCount(4);
    QJsonArray badJson;
    for (int i = 0; i < badList.size(); ++i) {
        const Shield& s = badList[i];
        QTableWidgetItem *itName = new QTableWidgetItem(s.name);
        QTableWidgetItem *itDesc = new QTableWidgetItem(s.description);
        QTableWidgetItem *itProt = new QTableWidgetItem(s.protection);
        QTableWidgetItem *itType = new QTableWidgetItem(s.type);

        // Покраска фона ячеек при наличии ошибок[cite: 1]
        if (!s.isNameValid()) itName->setBackground(Qt::red);
        if (!s.isDescValid()) itDesc->setBackground(Qt::red);
        if (!s.isTypeValid()) itType->setBackground(Qt::red);
        if (!s.isProtValid()) itProt->setBackground(Qt::red); // Красим, если в "Коэффициент" ввели текст[cite: 1]

        ui->tableError->setItem(i, 0, itName);
        ui->tableError->setItem(i, 1, itDesc);
        ui->tableError->setItem(i, 2, itProt);
        ui->tableError->setItem(i, 3, itType);
        badJson.append(s.toJson());
    }

    // Автоматическое сохранение в два файла[cite: 1]
    QFile fOk("correct_data.json");
    if (fOk.open(QIODevice::WriteOnly)) fOk.write(QJsonDocument(okJson).toJson());

    QFile fBad("broken_data.json");
    if (fBad.open(QIODevice::WriteOnly)) fBad.write(QJsonDocument(badJson).toJson());

    QMessageBox::information(this, "Готово", "Данные разделены и автоматически сохранены.");
}
