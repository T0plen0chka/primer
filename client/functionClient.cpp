#include "functionClient.h"
#include <QMessageBox>

// Разделитель для данных
const QString DELIMITER = "|";

// Формат запроса: "OPERATION|PARAM1|PARAM2|..."
bool is_auth(const QString& login, const QString& password) {
    QString request = "AUTH" + DELIMITER + login + DELIMITER + password;
    QString response = Singleton_client::getInstance()->doRequest(request.toUtf8());

    return response == "SUCCESS";
}

bool is_reg(const QString& email, const QString& login, const QString& password) {
    QString request = "REG" + DELIMITER + email + DELIMITER + login + DELIMITER + password;
    QString response = Singleton_client::getInstance()->doRequest(request.toUtf8());

    return response == "SUCCESS";
}

// Локальное шифрование (без сервера)
QString encryptCaesar(const QString& text, int shift) {
    QString result;
    for (QChar ch : text) {
        if (ch.isLetter()) {
            QChar base = ch.isLower() ? 'a' : 'A';
            int offset = (ch.unicode() - base.unicode() + shift) % 26;
            result.append(QChar(base.unicode() + offset));
        } else {
            result.append(ch);
        }
    }
    return result;
}

QString decryptCaesar(const QString& text, int shift) {
    return encryptCaesar(text, 26 - (shift % 26));
}

// Отправка на сервер
bool sendCaesarRequest(const QString& operation, const QString& text, int shift) {
    QString request = operation + DELIMITER + QString::number(shift) + DELIMITER + text;
    QString response = Singleton_client::getInstance()->doRequest(request.toUtf8());

    return response.startsWith("SUCCESS");
}
