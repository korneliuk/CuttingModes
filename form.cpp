#include "form.h"
#include "material.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setVerticalSpacing(12);
    grid->setHorizontalSpacing(10);

    QStringList list = {"", "1) Steel1: 12X18H9T", "2) Steel2: 20X23H18",
                        "3) Copper", "4) Duralumin D12", "5) Cast iron gray"};
    materials = new QComboBox();
    materials->addItems(list);
    grid->addWidget(materials, 0,1,1,1);

    // При виборі матеріалу, його назва буде присвоюватись змінній chosenMaterial
    connect(materials, &QComboBox::currentTextChanged, this, &Form::setChosenMaterial);

    lab1 = new QLabel("Типи матеріалів:", this);
    grid->addWidget(lab1, 0,0,1,1);
    lab1->setAlignment(Qt::AlignRight | Qt::AlignTop);

    lab2 = new QLabel("Твердість матеріалу (HB):", this);
    grid->addWidget(lab2, 1,0,1,1);
    lab2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    edit1 = new QLineEdit(this);
    grid->addWidget(edit1, 1,1,1,1);

    lab3 = new QLabel("Тип операції:", this);
    grid->addWidget(lab3, 2,0,1,1);
    lab3->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QHBoxLayout *hbox = new QHBoxLayout();

    drilling = new QPushButton("Свердління", this);
    drilling->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    countersinking  = new QPushButton("Зенкерування", this);
    countersinking ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    reaming = new QPushButton("Розсверлювання", this);
    reaming->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    deployment = new QPushButton("Розгортування", this);
    deployment->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    hbox->addWidget(drilling);
    hbox->addWidget(countersinking);
    hbox->addWidget(reaming);
    hbox->addWidget(deployment);

    grid->addLayout(hbox, 2,1,3,1);

    lab4 = new QLabel("Квалітет точності:", this);
    grid->addWidget(lab4, 5,0,1,1);
    lab4->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    edit2 = new QLineEdit(this);
    grid->addWidget(edit2, 5,1,1,1);

    lab5 = new QLabel("Введіть L(мм):", this);
    grid->addWidget(lab5, 6,0,1,1);
    lab5->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    edit3 = new QLineEdit(this);
    grid->addWidget(edit3, 6,1,1,1);

    lab6 = new QLabel("Введіть D1(мм):", this);
    grid->addWidget(lab6, 7,0,1,1);
    lab6->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    edit4 = new QLineEdit(this);
    grid->addWidget(edit4, 7,1,1,1);

    lab7 = new QLabel("Введіть D2(мм):", this);
    grid->addWidget(lab7, 8,0,1,1);
    lab7->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    edit5 = new QLineEdit(this);
    grid->addWidget(edit5, 8,1,1,1);

    calculate = new QPushButton("Обрахунок", this);
    calculate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    grid->addWidget(calculate, 9,0,1,2);

    // Натискаючи на певну кнопку з видом обробки, вибраний режим буде зберігатися в окремій змінній
    connect(drilling, &QPushButton::clicked, this, &Form::on_drillingPushButton_clicked);
    connect(countersinking, &QPushButton::clicked, this, &Form::on_countersinkingPushButton_clicked);
    connect(reaming, &QPushButton::clicked, this, &Form::on_reamingPushButton_clicked);
    connect(deployment, &QPushButton::clicked, this, &Form::on_deploymentPushButton_clicked);

    /* При натисканні на кнопку "Обрахувати", ми зчитуємо введені дані зі стрічок,
    перевіряємо введені дані, проводимо обрахунки */
    connect(calculate, &QPushButton::clicked, this, [this](){
        on_lineEdit_textEdited();
        on_lineEdit2_textEdited();
        on_lineEdit3_textEdited();
        on_lineEdit4_textEdited();
        on_lineEdit5_textEdited();
        on_calculatePushButton_clicked();
    });

    setLayout(grid);
}

// Наступні слоти (фактично методи) зчитують введені дані зі стрічок вводу
void Form::on_lineEdit_textEdited()
{
    QString materialHardness_s = edit1->text();
    bool ok;
    materialHardness = materialHardness_s.toDouble(&ok);
    if (ok) {
        qDebug() << "Конвертоване значення:" << materialHardness;
    } else {
        qDebug() << "Помилка конвертації";
    }
}
void Form::on_lineEdit2_textEdited()
{
    QString accuracyQualifi_s = edit2->text();
    bool ok;
    accuracyQualifi = accuracyQualifi_s.toDouble(&ok);
    if (ok) {
        qDebug() << "Конвертоване значення:" << accuracyQualifi;
    } else {
        qDebug() << "Помилка конвертації";
    }
}
void Form::on_lineEdit3_textEdited()
{
    QString L_s = edit3->text();
    bool ok;
    L = L_s.toDouble(&ok);
    if (ok) {
        qDebug() << "Конвертоване значення:" << L;
    } else {
        qDebug() << "Помилка конвертації";
    }
}
void Form::on_lineEdit4_textEdited()
{
    QString D1_s = edit4->text();
    bool ok;
    D1 = D1_s.toDouble(&ok);
    if (ok) {
        qDebug() << "Конвертоване значення:" << D1;
    } else {
        qDebug() << "Помилка конвертації";
    }
}
void Form::on_lineEdit5_textEdited()
{
    QString D2_s = edit5->text();
    bool ok;
    D2 = D2_s.toDouble(&ok);
    if (ok) {
        qDebug() << "Конвертоване значення:" << D2;
    } else {
        qDebug() << "Помилка конвертації";
    }
}

// Наступні слоти встановлюють значення, який режим обробки був обраний
void Form::on_drillingPushButton_clicked()
{
    drilling_isClicked = true;
    countersinking_isClicked = reaming_isClicked =
        deployment_isClicked = false;
}
void Form::on_countersinkingPushButton_clicked()
{
    countersinking_isClicked = true;
    drilling_isClicked = reaming_isClicked =
        deployment_isClicked = false;
}
void Form::on_reamingPushButton_clicked()
{
    reaming_isClicked = true;
    drilling_isClicked = countersinking_isClicked =
        deployment_isClicked = false;
}
void Form::on_deploymentPushButton_clicked()
{
    deployment_isClicked = true;
    drilling_isClicked = countersinking_isClicked =
        reaming_isClicked = false;
}

/* При натисканні на кнопку "Обрахувати",
відбувається перевірка введених даних, та подальші обчислення */
void Form::on_calculatePushButton_clicked()
{
    // Валідація введених даних
    if(chosenMaterial=="1) Steel1: 12X18H9T" || chosenMaterial=="1) Steel1: 12X18H9T")
    {
        if(materialHardness < 160 || materialHardness > 240)
        {
            edit1->setText("");
            return;
        }
    }
    else if(chosenMaterial == "3) Copper" || chosenMaterial == "4) Duralumin D12")
    {
        if(materialHardness <= 170)
        {
            edit1->setText("");
            return;
        }
    }
    else if (chosenMaterial == "5) Cast iron gray")
    {
        if(materialHardness > 170)
        {
            edit1->setText("");
            return;
        }
    }

    if(drilling_isClicked)
    {
        if(accuracyQualifi < 5 || accuracyQualifi > 9)
        {
            edit2->setText("");
            return;
        }
    }
    if(countersinking_isClicked || reaming_isClicked || deployment_isClicked)
    {
        if(accuracyQualifi < 7 || accuracyQualifi > 14)
        {
            edit2->setText("");
            return;
        }
    }
    if(L > (10 * D2))
    {
        edit3->setText("");
        return;
    }
    if(D1<0 || D1 > D2)
    {
        edit4->setText("");
        return;
    }
    if(D2 < 0)
    {
        edit5->setText("");
        return;
    }

    Material material(getChosenMaterial());

    // Обрахунки, якщо обрано режим Свердління
    if(drilling_isClicked)
    {
        material.setModeType(Material::Drilling);
        material.setValues();

        material.setToolDiameter(D2);
        qDebug()<<"Tool diameter: "<<material.getToolDiameter();

        material.set_t((D2 - D1) / 2.0);
        qDebug()<<"t:"<<material.get_t();

        double S_t = QRandomGenerator::global()->generateDouble();
        S_t = material.getMin()+S_t*(material.getMax()-material.getMin());
        S_t = std::round(S_t * 100.0) / 100.0;
        qDebug()<<"S_t:"<<S_t;

        if(L <= 3.0 * D2)
            material.setK_ls(1.0);
        else if(L <= 7.0 * D2)
            material.setK_ls(0.8);
        else if(L <= 10.0 * D2)
            material.setK_ls(0.75);

        qDebug()<<"K_ls:"<<material.getK_ls();

        material.setK_s(material.getK_ls() * material.getK_os() *
                        material.getK_is() * material.getK_js());
        qDebug()<<"K_s:"<<material.getK_s();

        material.setS(S_t * material.getK_s());
        qDebug()<<"S:"<<material.getS();

        if(L <= 3.0 * D2)
            material.setK_lv(1.0);
        else if(L <= 4.0 * D2)
            material.setK_lv(0.85);
        else if(L <= 5.0 * D2)
            material.setK_lv(0.75);
        else if(L <= 6.0 * D2)
            material.setK_lv(0.7);
        else if(L <= 7.0 * D2)
            material.setK_lv(0.6);

        qDebug()<<"K_lv:"<<material.getK_lv();

        material.setK_v(material.getK_mv() * material.getK_iv() *
                        material.getK_lv() * material.getK_nv());
        qDebug()<<"K_v: "<<material.getK_v();

        double tempV = material.getCv()*std::pow(D2, material.getQ());
        tempV = tempV/(std::pow(material.getT(), material.getM())*std::pow(material.getS(), material.getY()));
        tempV = tempV * material.getK_v();
        material.setV(tempV);

        qDebug()<<"v: "<<material.getV();

        double tempN = (1000.0 * material.getV())/(3.14 * D2);
        material.setN(tempN);

        qDebug()<<"n: "<<material.getN();
    }
    /* Обрахунки, якщо обрано режим Зенкерування */
    else if(countersinking_isClicked)
    {
        material.setModeType(Material::Countersinking);
        material.setValues();

        material.setToolDiameter(D2);
        qDebug()<<"Tool diameter: "<<material.getToolDiameter();

        material.set_t((D2 - D1) / 2.0);
        qDebug()<<"t:"<<material.get_t();

        double S_t = QRandomGenerator::global()->generateDouble();
        S_t = material.getMin()+S_t*(material.getMax()-material.getMin());
        S_t = std::round(S_t * 100.0) / 100.0;
        qDebug()<<"S_t:"<<S_t;

        if(L <= 3.0 * D2)
            material.setK_ls(1.0);
        else if(L <= 7.0 * D2)
            material.setK_ls(0.8);
        else if(L <= 10.0 * D2)
            material.setK_ls(0.75);

        qDebug()<<"K_ls:"<<material.getK_ls();

        material.setK_s(material.getK_ls() * material.getK_os() *
                        material.getK_is() * material.getK_js());
        qDebug()<<"K_s:"<<material.getK_s();

        material.setS(S_t * material.getK_s());
        qDebug()<<"S:"<<material.getS();

        qDebug()<<"K_lv:"<<material.getK_lv();

        material.setK_v(material.getK_mv() * material.getK_iv() *
                        material.getK_lv() * material.getK_nv());
        qDebug()<<"K_v: "<<material.getK_v();

        double tempV = material.getCv()*std::pow(D2, material.getQ());
        tempV = tempV/(std::pow(material.getT(), material.getM())*std::pow(material.getS(), material.getY())*
                         std::pow(material.get_t(), material.getX()));
        tempV = tempV * material.getK_v();
        material.setV(tempV);

        qDebug()<<"v: "<<material.getV();

        double tempN = (1000.0 * material.getV())/(3.14 * D2);
        material.setN(tempN);

        qDebug()<<"n: "<<material.getN();
    }
    // Обрахунки, якщо обрано режим Розсвердлювання
    else if(reaming_isClicked)
    {
        material.setModeType(Material::Reaming);
        material.setValues();

        material.setToolDiameter(D2);
        qDebug()<<"Tool diameter: "<<material.getToolDiameter();

        material.set_t((D2 - D1) / 2.0);
        qDebug()<<"t:"<<material.get_t();

        double S_t = QRandomGenerator::global()->generateDouble();
        S_t = material.getMin()+S_t*(material.getMax()-material.getMin());
        S_t = std::round(S_t * 100.0) / 100.0;
        qDebug()<<"S_t:"<<S_t;

        if(L <= 3.0 * D2)
            material.setK_ls(1.0);
        else if(L <= 7.0 * D2)
            material.setK_ls(0.8);
        else if(L <= 10.0 * D2)
            material.setK_ls(0.75);

        qDebug()<<"K_ls:"<<material.getK_ls();

        material.setK_s(material.getK_ls() * material.getK_os() *
                        material.getK_is() * material.getK_js());
        qDebug()<<"K_s:"<<material.getK_s();

        material.setS(S_t * material.getK_s());
        qDebug()<<"S:"<<material.getS();

        qDebug()<<"K_lv:"<<material.getK_lv();

        material.setK_v(material.getK_mv() * material.getK_iv() *
                        material.getK_lv() * material.getK_nv());
        qDebug()<<"K_v: "<<material.getK_v();

        double tempV = material.getCv()*std::pow(D2, material.getQ());
        tempV = tempV/(std::pow(material.getT(), material.getM())*std::pow(material.getS(), material.getY())*
                         std::pow(material.get_t(), material.getX()));
        tempV = tempV * material.getK_v();
        material.setV(tempV);

        qDebug()<<"v: "<<material.getV();

        double tempN = (1000.0 * material.getV())/(3.14 * D2);
        material.setN(tempN);

        qDebug()<<"n: "<<material.getN();
    }
    // Обрахунки, якщо обрано режим Розгортквання
    else if(deployment_isClicked)
    {
        material.setModeType(Material::Deployment);
        material.setValues();

        material.setToolDiameter(D2);
        qDebug()<<"Tool diameter: "<<material.getToolDiameter();

        material.set_t((D2 - D1) / 2.0);
        qDebug()<<"t:"<<material.get_t();

        double S_t = QRandomGenerator::global()->generateDouble();
        S_t = material.getMin()+S_t*(material.getMax()-material.getMin());
        S_t = std::round(S_t * 100.0) / 100.0;
        qDebug()<<"S_t:"<<S_t;

        if(L <= 3.0 * D2)
            material.setK_ls(1.0);
        else if(L <= 7.0 * D2)
            material.setK_ls(0.8);
        else if(L <= 10.0 * D2)
            material.setK_ls(0.75);

        qDebug()<<"K_ls:"<<material.getK_ls();

        material.setK_s(material.getK_ls() * material.getK_os() *
                        material.getK_is() * material.getK_js());
        qDebug()<<"K_s:"<<material.getK_s();

        material.setS(S_t * material.getK_s());
        qDebug()<<"S:"<<material.getS();

        qDebug()<<"K_lv:"<<material.getK_lv();

        material.setK_v(material.getK_mv() * material.getK_iv() *
                        material.getK_lv() * material.getK_nv());
        qDebug()<<"K_v: "<<material.getK_v();

        double tempV = material.getCv()*std::pow(D2, material.getQ());
        tempV = tempV/(std::pow(material.getT(), material.getM())*std::pow(material.getS(), material.getY())*
                         std::pow(material.get_t(), material.getX()));
        tempV = tempV * material.getK_v();
        material.setV(tempV);

        qDebug()<<"v: "<<material.getV();

        double tempN = (1000.0 * material.getV())/(3.14 * D2);
        material.setN(tempN);

        qDebug()<<"n: "<<material.getN();
    }

    // Створюємо вікно з результатами обрахувань
    results = new Results(0, material.get_t(),
                    material.getS(), material.getV(), material.getN());
    results->setMinimumSize(450, 75);
    results->setMaximumSize(450, 75);
    results->show();
}

void Form::setChosenMaterial()
{
    QTextStream out(stdout);
    chosenMaterial = materials->currentText();
    out<<chosenMaterial<<Qt::endl;
}

const QString Form::getChosenMaterial()
{
    return chosenMaterial;
}
