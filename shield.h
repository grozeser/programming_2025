#ifndef SHIELD_H
#define SHIELD_H

#include <QString>
#include <QJsonObject>
#include <QJsonValue>

class Shield {
public:
    QString name;
    QString description;
    QString protection; // Храним как строку для поддержки любого ввода
    QString type;

    Shield() {}

    QJsonObject toJson() const {
        QJsonObject obj;
        obj["name"] = name;
        obj["description"] = description;
        obj["protection"] = protection;
        obj["type"] = type;
        return obj;
    }

    static Shield fromJson(const QJsonObject& obj) {
        Shield s;
        s.name = obj["name"].toString();
        s.description = obj["description"].toString();
        // Считываем значение как строку, даже если в JSON оно записано как число
        if (obj["protection"].isDouble())
            s.protection = QString::number(obj["protection"].toDouble());
        else
            s.protection = obj["protection"].toString();
        s.type = obj["type"].toString();
        return s;
    }

    // Индивидуальные проверки для валидации и покраски ячеек
    bool isNameValid() const { return !name.isEmpty(); }
    bool isDescValid() const { return !description.isEmpty(); }
    bool isTypeValid() const { return !type.isEmpty(); }
    bool isProtValid() const {
        bool ok;
        double val = protection.toDouble(&ok);
        return ok && val > 0; // Валидно, если это число и оно больше нуля
    }

    bool isValid() const {
        return isNameValid() && isDescValid() && isTypeValid() && isProtValid();
    }
};

#endif
