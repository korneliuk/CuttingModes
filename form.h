#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextBlock>
#include <QListWidget>
#include <QPushButton>
#include <QApplication>
#include <QComboBox>
#include <QRandomGenerator>

#include <windows.h>
#include "results.h"

// Клас головного вікна, в яке ми вводимо дані
class Form : public QWidget
{
public:
    Form(QWidget *parent = 0);
    void setChosenMaterial();
    const QString getChosenMaterial();

    /* Вказівник на зміну типу Results.
    Фактично це вікно з обрахованими результатами */
    Results *results;

private slots:
    // Слоти (фактично методи), які зчитують дані з рядків вводу
    void on_lineEdit_textEdited();
    void on_lineEdit2_textEdited();
    void on_lineEdit3_textEdited();
    void on_lineEdit4_textEdited();
    void on_lineEdit5_textEdited();

    // Слоти, які визначають, який режим обробки обрано
    void on_drillingPushButton_clicked();
    void on_countersinkingPushButton_clicked();
    void on_reamingPushButton_clicked();
    void on_deploymentPushButton_clicked();
    void on_calculatePushButton_clicked();

private:
    QComboBox *materials;

    /* Змінні, які зберігають в собі текст перед стрічками,
     * в які ми вводимо дані (не впливають на логіку програми)
    */
    QLabel *lab1, *lab2, *lab3,
        *lab4, *lab5, *lab6, *lab7;

    // Стрічки, в які ми вводимо дані
    QLineEdit *edit1, *edit2,
        *edit3, *edit4, *edit5;

    // Наступні змінні це кнопки режимів обробки
    QPushButton *drilling, *countersinking,
        *reaming, *deployment, *calculate;

    QString chosenMaterial;

    double materialHardness,
        accuracyQualifi, L, D1, D2;

    // Змінні, які позначають, який режим обробки обрано
    bool drilling_isClicked, countersinking_isClicked,
        deployment_isClicked, reaming_isClicked;
};

#endif // FORM_H
