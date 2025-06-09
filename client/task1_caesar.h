#ifndef TASK1_CAESAR_H
#define TASK1_CAESAR_H

#include <QWidget>

namespace Ui {
class Task1_Caesar;
}

class Task1_Caesar : public QWidget
{
    Q_OBJECT

public:
    explicit Task1_Caesar(QWidget *parent = nullptr);
    ~Task1_Caesar();

signals:
    void backToMainWindow();

private slots:
    void on_pushButton_encrypt_clicked();
    void on_pushButton_decrypt_clicked();
    void on_pushButton_back_clicked();

private:
    Ui::Task1_Caesar *ui;
    QString caesarCipher(const QString &text, int shift, bool encrypt);
};

#endif // TASK1_CAESAR_H
