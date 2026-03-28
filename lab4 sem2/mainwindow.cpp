#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// СБРОС
void MainWindow::on_pushButtonReset_clicked()
{
    ui->lineEditAuthor->clear();
    ui->lineEditTitle->clear();
    ui->lineEditCode->clear();
    ui->lineEditContent->clear();

    ui->radioPaper->setChecked(false);
    ui->radioElectronic->setChecked(false);

    ui->checkDetective->setChecked(false);
    ui->checkFantasy->setChecked(false);
    ui->checkNovel->setChecked(false);
}

// СОХРАНЕНИЕ
void MainWindow::on_pushButtonSave_clicked()
{
    QString author = ui->lineEditAuthor->text().trimmed();
    QString title = ui->lineEditTitle->text().trimmed();
    QString code = ui->lineEditCode->text().trimmed();
    QString content = ui->lineEditContent->text().trimmed();

    // Проверка пустоты
    if (author.isEmpty() || title.isEmpty() || code.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля (кроме жанра) обязательны!");
        return;
    }

    // Автор: Клоц АН
    QRegularExpression regAuthor("^[А-ЯЁ][а-яё]+\\s[А-ЯЁ]{1,2}$");
    if (!regAuthor.match(author).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Автор: Пример 'Клоц АН'");
        return;
    }

    // Название: "Выбор"
    QRegularExpression regTitle("^\".+\"$");
    if (!regTitle.match(title).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Название должно быть в кавычках!");
        return;
    }

    // Код: 123-1234
    QRegularExpression regCode("^\\d{3}-\\d{4,5}$");
    if (!regCode.match(code).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Код: формат 123-1234");
        return;
    }

    // Наполнение: 102/5 (второе < первого)
    QRegularExpression regContent("^(\\d+)/(\\d+)$");
    QRegularExpressionMatch match = regContent.match(content);

    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Наполнение: формат 10/2");
        return;
    }

    int first = match.captured(1).toInt();
    int second = match.captured(2).toInt();

    if (second >= first) {
        QMessageBox::warning(this, "Ошибка", "Второе число должно быть меньше первого!");
        return;
    }

    // Тип
    if (!ui->radioPaper->isChecked() && !ui->radioElectronic->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите тип издания!");
        return;
    }

    QString type = ui->radioPaper->isChecked() ? "Бумажное" : "Электронное";

    // Жанры (необязательные)
    QStringList genresList;
    if (ui->checkDetective->isChecked()) genresList << "Детектив";
    if (ui->checkFantasy->isChecked()) genresList << "Фантастика";
    if (ui->checkNovel->isChecked()) genresList << "Роман";

    QString genres = genresList.join(", ");

    Book book(author, title, code, content, type, genres);

    if (book.saveToFile("..\\..\\result.txt")) {
        QMessageBox::information(this, "Успех", "Сохранено!");
    } else {
        QMessageBox::critical(this, "Ошибка", "Ошибка записи файла!");
    }
}
