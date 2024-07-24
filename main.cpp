#include "form.h"
#include <QApplication>

// Функція main. З неї починається робота програми
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // form - головне вікно, в яке ми заповнюємо дані
    Form form;
    form.setMinimumSize(560, 305);
    form.setMaximumSize(560, 305);
    form.setWindowTitle("Автор: Кравченко М. ПБ-12");
    form.show();

    return a.exec();
}
