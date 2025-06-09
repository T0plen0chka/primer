#include "task1_caesar.h"
#include "ui_task1_caesar.h"
#include <QMessageBox>

Task1_Caesar::Task1_Caesar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task1_Caesar)
{
    ui->setupUi(this);
    setFixedSize(600, 450); // Фиксированный размер окна
}

Task1_Caesar::~Task1_Caesar()
{
    delete ui;
}

QString Task1_Caesar::caesarCipher(const QString &text, int shift, bool encrypt)
{
    QString result;
    for (QChar ch : text) {
        if (ch.isLetter()) {
            QChar base = ch.isLower() ? 'a' : 'A';
            int offset = ch.unicode() - base.unicode();
            if (encrypt) {
                offset = (offset + shift) % 26;
            } else {
                offset = (offset - shift + 26) % 26;
            }
            result.append(QChar(base.unicode() + offset));
        } else {
            result.append(ch);
        }
    }
    return result;
}

void Task1_Caesar::on_pushButton_encrypt_clicked()
{
    QString text = ui->plainTextEdit_input->toPlainText();
    int shift = ui->spinBox_shift->value();

    if (text.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите текст для шифрования");
        return;
    }

    QString encrypted = caesarCipher(text, shift, true);
    ui->plainTextEdit_output->setPlainText(encrypted);
}

void Task1_Caesar::on_pushButton_decrypt_clicked()
{
    QString text = ui->plainTextEdit_input->toPlainText();
    int shift = ui->spinBox_shift->value();

    if (text.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите текст для дешифрования");
        return;
    }

    QString decrypted = caesarCipher(text, shift, false);
    ui->plainTextEdit_output->setPlainText(decrypted);
}

void Task1_Caesar::on_pushButton_back_clicked()
{
    emit backToMainWindow();
    this->close();
}
