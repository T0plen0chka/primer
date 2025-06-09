#ifndef FUNCFORCLIENT_H
#define FUNCFORCLIENT_H

#include "singleton_client.h"
#include <QString>

// Авторизация
bool is_auth(const QString& login, const QString& password);

// Регистрация
bool is_reg(const QString& email, const QString& login, const QString& password);

// Шифр Цезаря
QString encryptCaesar(const QString& text, int shift);
QString decryptCaesar(const QString& text, int shift);
bool sendCaesarRequest(const QString& operation, const QString& text, int shift);

#endif // FUNCFORCLIENT_H
