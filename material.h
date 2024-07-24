#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>

class Material
{   
public:
    /* Перечислюємий тип даних, який позначає
     * які типи обробки можливі
    */
    enum modeType
    {
        Drilling,
        Countersinking,
        Reaming,
        Deployment
    };

    Material();
    Material(const QString &name);

    // Гетери і сетери. Необхідні для доступу до змінних
    double get_t();

    double getMin();
    double getMax();

    double getK_s();
    double getK_ls();
    double getK_js();
    double getK_os();
    double getK_is();

    double getCv();
    double getX();
    double getQ();
    double getY();
    double getM();
    double getS();
    double getToolDiameter();
    double getT();

    void set_t(const double &t);

    void setModeType(const Material::modeType &mode);
    void setValues();
    void setK_s(const double &K_s);
    void setK_ls(const double &K_ls);
    void setS(const double &S);
    void setToolDiameter(const double &D2);
    void setT();

    void setK_v(const double &K_v);
    void setK_lv(const double &K_lv);
    void setV(const double &v);
    void setN(const double &n);

    double getK_v();
    double getK_mv();
    double getK_iv();
    double getK_lv();
    double getK_nv();
    double getV();
    double getN();

private:
    double t;
    double min, max;
    double K_s, K_ls, K_js, K_os, K_is;
    double Cv, x, q, y, m,
        S, toolDiameter, T;

    double K_v, K_mv, K_iv, K_lv, K_nv;
    long double v, n;

    // Назва обраного нами матеріалу
    QString materialName;

    // Змінна, яка позначає обраний тип обробки
    modeType mode;
};

#endif // MATERIAL_H
