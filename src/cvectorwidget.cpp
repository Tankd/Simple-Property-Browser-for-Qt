#include "cvectorwidget.h"


CVectorWidget::CVectorWidget(int count, QWidget *parent) :
    QWidget(parent), layout(0)
{    
    _count = count;
    _count = qBound<unsigned short>(2, _count, 4);




    layout = new QHBoxLayout();
    this->setLayout(layout);
    layout->setContentsMargins(QMargins(0, 0, 0, 0));
    layout->setSpacing(0);
    for(int i=0; i<count; i++)
    {
        box.append(new QDoubleSpinBox());
        box[i]->setMinimum(-99999999);
        box[i]->setMaximum(99999999);
        layout->addWidget(box[i]);
        connect(box[i], SIGNAL(valueChanged(double)), this, SLOT(propValueChanged()));
    }


}

CVectorWidget::~CVectorWidget()
{   

}

void CVectorWidget::propValueChanged()
{
    emit valueChanged();
}


void CVectorWidget::setValue(QVariant v)
{
    if(_count == 2)
    {
        box[0]->setValue(v.value<QVector2D>().x());
        box[1]->setValue(v.value<QVector2D>().y());
    }
    else if(_count == 3)
    {
        box[0]->setValue(v.value<QVector3D>().x());
        box[1]->setValue(v.value<QVector3D>().y());
        box[2]->setValue(v.value<QVector3D>().z());
    }
    else if(_count == 4)
    {
        box[0]->setValue(v.value<QVector4D>().x());
        box[1]->setValue(v.value<QVector4D>().y());
        box[2]->setValue(v.value<QVector4D>().z());
        box[3]->setValue(v.value<QVector4D>().w());
    }

    emit valueChanged();
}

QVariant CVectorWidget::value()
{

    if(_count == 2)
    {
        return QVector2D(box[0]->value(), box[1]->value());
    }
    else if(_count == 3)
    {
        return QVector3D(box[0]->value(), box[1]->value(), box[2]->value());
    }
    else if(_count == 4)
    {
        return QVector4D(box[0]->value(), box[1]->value(), box[2]->value(), box[3]->value());
    }

    return QVariant();
}
