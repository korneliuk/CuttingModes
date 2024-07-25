#include "material.h"
#include "qdebug.h"
#include <windows.h>

Material::Material(const QString &name)
{
    materialName = name;
}

double Material::get_t()
{
    return t;
}

double Material::getMin()
{
    return min;
}
double Material::getMax()
{
    return max;
}

double Material::getK_s()
{
    return K_s;
}
double Material::getK_ls()
{
    return K_ls;
}
double Material::getK_is()
{
    return K_is;
}
double Material::getK_os()
{
    return K_os;
}
double Material::getK_js()
{
    return K_js;
}
double Material::getS()
{
    return S;
}
double Material::getToolDiameter()
{
    return toolDiameter;
}

double Material::getK_v()
{
    return K_v;
}
double Material::getK_mv()
{
    return K_mv;
}
double Material::getK_iv()
{
    return K_iv;
}
double Material::getK_lv()
{
    return K_lv;
}
double Material::getK_nv()
{
    return K_nv;
}
double Material::getV()
{
    return v;
}
double Material::getN()
{
    return n;
}

double Material::getCv()
{
    return Cv;
}
double Material::getX()
{
    return x;
}
double Material::getQ()
{
    return q;
}
double Material::getY()
{
    return y;
}
double Material::getM()
{
    return m;
}
double Material::getT()
{
    return T;
}

void Material::set_t(const double &t)
{
    this->t = t;
}

void Material::setModeType(const Material::modeType &mode)
{
    this->mode = mode;
}

void Material::setK_v(const double &K_v)
{
    this->K_v = K_v;
}
void Material::setK_s(const double &K_s)
{
    this->K_s = K_s;
}

void Material::setK_ls(const double &K_ls)
{
    this->K_ls = K_ls;
}

void Material::setS(const double &S)
{
    this->S = S;
}

void Material::setToolDiameter(const double &D2)
{
    this->toolDiameter = D2;

    switch (mode)
    {
    case Drilling:
        if(materialName == "1) Steel1: 12X18H9T" || materialName == "2) Steel2: 20X23H18")
        {
            if(toolDiameter >= 2 && toolDiameter <= 4)
            {
                min = 0.08;
                max = 0.10;
            }
            else if(toolDiameter >= 4 && toolDiameter <= 6)
            {
                min = 0.10;
                max = 0.15;
            }
            else if(toolDiameter >= 6 && toolDiameter <= 8)
            {
                min = 0.15;
                max = 0.20;
            }
            else if(toolDiameter >= 8 && toolDiameter <= 10)
            {
                min = 0.20;
                max = 0.25;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 12)
            {
                min = 0.25;
                max = 0.28;
            }
            else if(toolDiameter >= 12 && toolDiameter <= 16)
            {
                min = 0.28;
                max = 0.33;
            }
            else if(toolDiameter >= 16 && toolDiameter <= 20)
            {
                min = 0.33;
                max = 0.38;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 0.38;
                max = 0.43;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 0.43;
                max = 0.48;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 40)
            {
                min = 0.48;
                max = 0.58;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 0.58;
                max = 0.66;
            }
        }
        else if(materialName == "3) Copper" || materialName == "4) Duralumin D12")
        {
            if(toolDiameter >= 2 && toolDiameter <= 4)
            {
                min = 0.12;
                max = 0.18;
            }
            else if(toolDiameter >= 4 && toolDiameter <= 6)
            {
                min = 0.18;
                max = 0.27;
            }
            else if(toolDiameter >= 6 && toolDiameter <= 8)
            {
                min = 0.27;
                max = 0.36;
            }
            else if(toolDiameter >= 8 && toolDiameter <= 10)
            {
                min = 0.36;
                max = 0.45;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 12)
            {
                min = 0.45;
                max = 0.55;
            }
            else if(toolDiameter >= 12 && toolDiameter <= 16)
            {
                min = 0.55;
                max = 0.66;
            }
            else if(toolDiameter >= 16 && toolDiameter <= 20)
            {
                min = 0.66;
                max = 0.78;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 0.76;
                max = 0.89;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 0.89;
                max = 0.96;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 40)
            {
                min = 0.96;
                max = 1.19;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 1.19;
                max = 1.36;
            }
        }
        else if(materialName == "5) Cast iron gray")
        {
            if(toolDiameter >= 2 && toolDiameter <= 4)
            {
                min = 0.09;
                max = 0.12;
            }
            else if(toolDiameter >= 4 && toolDiameter <= 6)
            {
                min = 0.12;
                max = 0.18;
            }
            else if(toolDiameter >= 6 && toolDiameter <= 8)
            {
                min = 0.18;
                max = 0.24;
            }
            else if(toolDiameter >= 8 && toolDiameter <= 10)
            {
                min = 0.24;
                max = 0.31;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 12)
            {
                min = 0.31;
                max = 0.35;
            }
            else if(toolDiameter >= 12 && toolDiameter <= 16)
            {
                min = 0.35;
                max = 0.41;
            }
            else if(toolDiameter >= 16 && toolDiameter <= 20)
            {
                min = 0.41;
                max = 0.47;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 0.47;
                max = 0.54;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 0.54;
                max = 0.60;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 40)
            {
                min = 0.60;
                max = 0.71;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 0.71;
                max = 0.81;
            }
        }
        break;
    case Countersinking:
        if(materialName == "1) Steel1: 12X18H9T" || materialName == "2) Steel2: 20X23H18")
        {
            if(toolDiameter <= 15)
            {
                min = 0.5;
                max = 0.6;
            }
            else if(toolDiameter >= 15 && toolDiameter <= 20)
            {
                min = 0.6;
                max = 0.7;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 0.7;
                max = 0.9;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 0.8;
                max = 1.0;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 35)
            {
                min = 0.9;
                max = 1.1;
            }
            else if(toolDiameter >= 35 && toolDiameter <= 40)
            {
                min = 0.9;
                max = 1.2;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 1.0;
                max = 1.3;
            }
            else if(toolDiameter >= 50 && toolDiameter <= 60)
            {
                min = 1.1;
                max = 1.3;
            }
            else if(toolDiameter >= 60 && toolDiameter <= 80)
            {
                min = 1.2;
                max = 1.5;
            }
        }
        else
        {
            if(toolDiameter <= 15)
            {
                min = 0.7;
                max = 0.9;
            }
            else if(toolDiameter >= 15 && toolDiameter <= 20)
            {
                min = 0.9;
                max = 1.1;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 1.0;
                max = 1.2;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 1.1;
                max = 1.3;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 35)
            {
                min = 1.2;
                max = 1.5;
            }
            else if(toolDiameter >= 35 && toolDiameter <= 40)
            {
                min = 1.4;
                max = 1.7;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 1.6;
                max = 2.0;
            }
            else if(toolDiameter >= 50 && toolDiameter <= 60)
            {
                min = 1.8;
                max = 2.2;
            }
            else if(toolDiameter >= 60 && toolDiameter <= 80)
            {
                min = 2.0;
                max = 2.4;
            }
        }
        break;
    case Reaming:
        if(materialName == "1) Steel1: 12X18H9T" || materialName == "2) Steel2: 20X23H18")
        {
            if(toolDiameter >= 2 && toolDiameter <= 4)
            {
                min = 0.16;
                max = 0.20;
            }
            else if(toolDiameter >= 4 && toolDiameter <= 6)
            {
                min = 0.20;
                max = 0.30;
            }
            else if(toolDiameter >= 6 && toolDiameter <= 8)
            {
                min = 0.30;
                max = 0.40;
            }
            else if(toolDiameter >= 8 && toolDiameter <= 10)
            {
                min = 0.40;
                max = 0.50;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 12)
            {
                min = 0.50;
                max = 0.56;
            }
            else if(toolDiameter >= 12 && toolDiameter <= 16)
            {
                min = 0.56;
                max = 0.66;
            }
            else if(toolDiameter >= 16 && toolDiameter <= 20)
            {
                min = 0.66;
                max = 0.76;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 0.76;
                max = 0.86;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 0.86;
                max = 0.96;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 40)
            {
                min = 0.96;
                max = 1.16;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 1.16;
                max = 1.32;
            }
        }
        else if(materialName == "3) Copper" || materialName == "4) Duralumin D12")
        {
            if(toolDiameter >= 2 && toolDiameter <= 4)
            {
                min = 0.24;
                max = 0.36;
            }
            else if(toolDiameter >= 4 && toolDiameter <= 6)
            {
                min = 0.36;
                max = 0.54;
            }
            else if(toolDiameter >= 6 && toolDiameter <= 8)
            {
                min = 0.54;
                max = 0.72;
            }
            else if(toolDiameter >= 8 && toolDiameter <= 10)
            {
                min = 0.72;
                max = 0.90;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 12)
            {
                min = 0.90;
                max = 1.10;
            }
            else if(toolDiameter >= 12 && toolDiameter <= 16)
            {
                min = 1.10;
                max = 1.32;
            }
            else if(toolDiameter >= 16 && toolDiameter <= 20)
            {
                min = 1.32;
                max = 1.56;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 1.56;
                max = 1.78;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 1.78;
                max = 1.92;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 40)
            {
                min = 1.92;
                max = 2.38;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 2.38;
                max = 2.72;
            }
        }
        else if(materialName == "5) Cast iron gray")
        {
            if(toolDiameter >= 2 && toolDiameter <= 4)
            {
                min = 0.18;
                max = 0.24;
            }
            else if(toolDiameter >= 4 && toolDiameter <= 6)
            {
                min = 0.24;
                max = 0.36;
            }
            else if(toolDiameter >= 6 && toolDiameter <= 8)
            {
                min = 0.36;
                max = 0.48;
            }
            else if(toolDiameter >= 8 && toolDiameter <= 10)
            {
                min = 0.48;
                max = 0.62;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 12)
            {
                min = 0.62;
                max = 0.70;
            }
            else if(toolDiameter >= 12 && toolDiameter <= 16)
            {
                min = 0.70;
                max = 0.82;
            }
            else if(toolDiameter >= 16 && toolDiameter <= 20)
            {
                min = 0.82;
                max = 0.94;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 0.94;
                max = 1.08;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 1.08;
                max = 1.20;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 40)
            {
                min = 1.20;
                max = 1.42;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 1.42;
                max = 1.62;
            }
        }
        break;
    case Deployment:
        if(materialName == "1) Steel1: 12X18H9T" || materialName == "2) Steel2: 20X23H18")
        {
            if(toolDiameter <= 10)
            {
                min = 0.8;
                max = 0.8;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 15)
            {
                min = 0.9;
                max = 0.9;
            }
            else if(toolDiameter >= 15 && toolDiameter <= 20)
            {
                min = 1.0;
                max = 1.0;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 1.1;
                max = 1.1;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 1.2;
                max = 1.2;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 35)
            {
                min = 1.3;
                max = 1.3;
            }
            else if(toolDiameter >= 35 && toolDiameter <= 40)
            {
                min = 1.4;
                max = 1.4;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 1.5;
                max = 1.5;
            }
            else if(toolDiameter >= 50 && toolDiameter <= 60)
            {
                min = 1.7;
                max = 1.7;
            }
            else if(toolDiameter >= 60 && toolDiameter <= 80)
            {
                min = 2.0;
                max = 2.0;
            }
        }
        else
        {
            if(toolDiameter <= 10)
            {
                min = 2.2;
                max = 2.2;
            }
            else if(toolDiameter >= 10 && toolDiameter <= 15)
            {
                min = 2.4;
                max = 2.4;
            }
            else if(toolDiameter >= 15 && toolDiameter <= 20)
            {
                min = 2.6;
                max = 2.6;
            }
            else if(toolDiameter >= 20 && toolDiameter <= 25)
            {
                min = 2.7;
                max = 2.7;
            }
            else if(toolDiameter >= 25 && toolDiameter <= 30)
            {
                min = 3.1;
                max = 3.1;
            }
            else if(toolDiameter >= 30 && toolDiameter <= 35)
            {
                min = 3.2;
                max = 3.2;
            }
            else if(toolDiameter >= 35 && toolDiameter <= 40)
            {
                min = 3.4;
                max = 3.4;
            }
            else if(toolDiameter >= 40 && toolDiameter <= 50)
            {
                min = 3.8;
                max = 3.8;
            }
            else if(toolDiameter >= 50 && toolDiameter <= 60)
            {
                min = 4.3;
                max = 4.3;
            }
            else if(toolDiameter >= 60 && toolDiameter <= 80)
            {
                min = 5.0;
                max = 5.0;
            }
        }
        break;
    }
}

void Material::setK_lv(const double &K_lv)
{
    this->K_lv = K_lv;
}

void Material::setV(const double &v)
{
    this->v = v;
}

void Material::setN(const double &n)
{
    this->n = n;
}

void Material::setT()
{
    if(materialName == "1) Steel1: 12X18H9T")
    {
        if(toolDiameter <= 5.0)
        {
            T = 15.0;
        }
        else if(toolDiameter>=6 && toolDiameter<=10)
        {
            T = 25.0;
        }
        else if(toolDiameter>=11 && toolDiameter<=20)
        {
            T = 45.0;
        }
        else if(toolDiameter>=21 && toolDiameter<=30)
        {
            T = 50.0;
        }
        else if(toolDiameter>=31 && toolDiameter<=40)
        {
            T = 70.0;
        }
        else if(toolDiameter>=41 && toolDiameter<=50)
        {
            T = 90.0;
        }
        else if(toolDiameter>=51 && toolDiameter<=60)
        {
            T = 110.0;
        }
        else if(toolDiameter>=61 && toolDiameter<=80)
        {
            T = 110.0;
        }
    }
    else if(materialName == "2) Steel2: 20X23H18")
    {
        if(toolDiameter <= 5.0)
        {
            T = 15.0;
        }
        else if(toolDiameter>=6 && toolDiameter<=10)
        {
            T = 25.0;
        }
        else if(toolDiameter>=11 && toolDiameter<=20)
        {
            T = 45.0;
        }
        else if(toolDiameter>=21 && toolDiameter<=30)
        {
            T = 50.0;
        }
        else if(toolDiameter>=31 && toolDiameter<=40)
        {
            T = 70.0;
        }
        else if(toolDiameter>=41 && toolDiameter<=50)
        {
            T = 90.0;
        }
        else if(toolDiameter>=51 && toolDiameter<=60)
        {
            T = 110.0;
        }
        else if(toolDiameter>=61 && toolDiameter<=80)
        {
            T = 110.0;
        }
    }
    else if(materialName=="3) Copper")
    {
        if(toolDiameter <= 5.0)
        {
            T = 25.0;
        }
        else if(toolDiameter>=6 && toolDiameter<=10)
        {
            T = 35.0;
        }
        else if(toolDiameter>=11 && toolDiameter<=20)
        {
            T = 60.0;
        }
        else if(toolDiameter>=21 && toolDiameter<=30)
        {
            T = 75.0;
        }
        else if(toolDiameter>=31 && toolDiameter<=40)
        {
            T = 105.0;
        }
        else if(toolDiameter>=41 && toolDiameter<=50)
        {
            T = 140.0;
        }
        else if(toolDiameter>=51 && toolDiameter<=60)
        {
            T = 170.0;
        }
        else if(toolDiameter>=61 && toolDiameter<=80)
        {
            T = 170.0;
        }
    }
    else if(materialName=="4) Duralumin D12")
    {
        if(toolDiameter <= 5.0)
        {
            T = 25.0;
        }
        else if(toolDiameter>=6 && toolDiameter<=10)
        {
            T = 35.0;
        }
        else if(toolDiameter>=11 && toolDiameter<=20)
        {
            T = 60.0;
        }
        else if(toolDiameter>=21 && toolDiameter<=30)
        {
            T = 75.0;
        }
        else if(toolDiameter>=31 && toolDiameter<=40)
        {
            T = 105.0;
        }
        else if(toolDiameter>=41 && toolDiameter<=50)
        {
            T = 140.0;
        }
        else if(toolDiameter>=51 && toolDiameter<=60)
        {
            T = 170.0;
        }
        else if(toolDiameter>=61 && toolDiameter<=80)
        {
            T = 170.0;
        }
    }
    else if(materialName=="5) Cast iron gray")
    {
        if(toolDiameter <= 5.0)
        {
            T = 25.0;
        }
        else if(toolDiameter>=6 && toolDiameter<=10)
        {
            T = 35.0;
        }
        else if(toolDiameter>=11 && toolDiameter<=20)
        {
            T = 60.0;
        }
        else if(toolDiameter>=21 && toolDiameter<=30)
        {
            T = 75.0;
        }
        else if(toolDiameter>=31 && toolDiameter<=40)
        {
            T = 105.0;
        }
        else if(toolDiameter>=41 && toolDiameter<=50)
        {
            T = 140.0;
        }
        else if(toolDiameter>=51 && toolDiameter<=60)
        {
            T = 170.0;
        }
        else if(toolDiameter>=61 && toolDiameter<=80)
        {
            T = 170.0;
        }
    }
}

void Material::setValues()
{
    switch (mode)
    {
    case Drilling:
        K_js = K_os = 1;
        K_is = 0.6;
        K_mv = K_iv = K_nv = 1;

        if(materialName == "1) Steel1: 12X18H9T")
        {
            Cv = 3.5;
            q = 0.5;
            y = 0.45;
            m = 0.12;
            setT();
        }
        else if(materialName == "2) Steel2: 20X23H18")
        {
            S <= 0.2 ? Cv = 7 : Cv = 9.8;
            q = 0.4;
            S <= 0.2 ? y = 0.7 : y = 0.5;
            m = 0.2;
            setT();
        }
        else if(materialName=="3) Copper")
        {
            S <= 0.3 ? Cv = 28.1 : Cv = 32.6;
            q = 0.25;
            S <= 0.3 ? y = 0.55 : y = 0.4;
            m = 0.125;
            setT();
        }
        else if(materialName=="4) Duralumin D12")
        {
            S <= 0.3 ? Cv = 26.3 : Cv = 40.7;
            q = 0.25;
            S <= 0.3 ? y = 0.55 : y = 0.4;
            m = 0.125;
            setT();
        }
        else if(materialName=="5) Cast iron gray")
        {
            S <= 0.3 ? Cv = 14.7 : Cv = 17.1;
            q = 0.25;
            S <= 0.3 ? y = 0.55 : y = 0.4;
            m = 0.2;
            setT();
        }
        break;
    case Countersinking:
        K_js = K_os = 1;
        K_is = 0.6;
        K_lv = K_mv = K_iv = K_nv = 1;

        if(materialName=="5) Cast iron gray")
        {
            Cv = 18.8;
            x = 0.1;
            q = 0.2;
            y = 0.4;
            m = 0.125;
            setT();
        }
        else
        {
            Cv = 16.3;
            x = 0.2;
            q = 0.3;
            y = 0.5;
            m = 0.3;
            setT();
        }
        break;
    case Reaming:
        K_js = K_os = 1;
        K_is = 0.6;
        K_lv = K_mv = K_iv = 1;
        K_nv = 0.1;

        if(materialName=="5) Cast iron gray")
        {
            Cv = 23.4;
            x = 0.1;
            q = 0.25;
            y = 0.4;
            m = 0.125;
            setT();
        }
        else
        {
            Cv = 16.2;
            x = 0.2;
            q = 0.4;
            y = 0.5;
            m = 0.2;
            setT();
        }
        break;
    case Deployment:
        K_js = K_os = 1;
        K_is = 0.6;
        K_lv = K_mv = K_iv = 1;
        K_nv = 0.9;

        if(materialName=="5) Cast iron gray")
        {
            Cv = 15.6;
            x = 0.1;
            q = 0.2;
            y = 0.5;
            m = 0.3;
            setT();
        }
        else
        {
            Cv = 10.5;
            x = 0.2;
            q = 0.3;
            y = 0.65;
            m = 0.4;
            setT();
        }
        break;
    default:
        break;
    }
}
