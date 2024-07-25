#include "results.h"

/* Клас вікна з результатами обрахунків.
В конструкторі класу заносимо результати в позначки вікна */
Results::Results(QWidget *parent, const double &t,
                 const double &S, const double &v, const double &n)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setVerticalSpacing(10);
    grid->setHorizontalSpacing(10);

    tLab = new QLabel("Глибина різання (мм):", this);
    grid->addWidget(tLab, 0,0,1,1);
    tLab->setAlignment(Qt::AlignRight | Qt::AlignTop);

    widget1 = new QLabel(this);
    widget1->setNum(t);
    widget1->setFrameStyle(QFrame::Box | QFrame::Plain);
    grid->addWidget(widget1, 0,1,1,1);

    sLab = new QLabel("Подача (мм/об):", this);
    grid->addWidget(sLab, 1,0,1,1);
    sLab->setAlignment(Qt::AlignRight | Qt::AlignTop);

    widget2 = new QLabel(this);
    widget2->setNum(S);
    widget2->setFrameStyle(QFrame::Box | QFrame::Plain);
    grid->addWidget(widget2, 1,1,1,1);

    vLab = new QLabel("Швидкість різання (мм/хв):", this);
    grid->addWidget(vLab, 0,2,1,1);
    vLab->setAlignment(Qt::AlignRight | Qt::AlignTop);

    widget3 = new QLabel(this);
    widget3->setNum(v);
    widget3->setFrameStyle(QFrame::Box | QFrame::Plain);
    grid->addWidget(widget3, 0,3,1,1);

    nLab = new QLabel("Частота обертання (об/хв):", this);
    grid->addWidget(nLab, 1,2,1,1);
    nLab->setAlignment(Qt::AlignRight | Qt::AlignTop);

    widget4 = new QLabel(this);
    widget4->setNum(n);
    widget4->setFrameStyle(QFrame::Box | QFrame::Plain);
    grid->addWidget(widget4, 1,3,1,1);

    setLayout(grid);
}

