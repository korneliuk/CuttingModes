#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QLabel>
#include <QTextLine>
#include <QGridLayout>

// Клас вікна, з обрахованими результатами
class Results : public QWidget
{
public:
    Results(QWidget *parent = 0, const double &t = 0.0,
            const double &S = 0.0, const double &v = 0.0, const double &n = 0.0);

private:
    /* Змінні з написами перед результатами обчислень
     * (на логіку програми не впливають) */
    QLabel *tLab, *sLab,
        *vLab, *nLab;

    // Змінні з результатами обчислень
    QLabel *widget1, *widget2,
        *widget3, *widget4;
};

#endif // RESULTS_H
