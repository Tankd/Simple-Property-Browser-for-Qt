#ifndef CVECTORWIDGET_H
#define CVECTORWIDGET_H

#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>

#include "cproperty.h"

class CVectorWidget : public QWidget
{
    Q_OBJECT

signals:
    void valueChanged();
public:
    explicit CVectorWidget(int count, QWidget *parent = 0);
    ~CVectorWidget();
    
    void setValue(QVariant v);
    QVariant value();


protected slots:
    void propValueChanged();


protected:
    QHBoxLayout* layout;
    QList<QDoubleSpinBox*> box;

    unsigned short _count;
    
};

#endif // CVECTORWIDGET_H
