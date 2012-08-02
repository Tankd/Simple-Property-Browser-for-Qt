#include "cproperty.h"

#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include "cvectorwidget.h"

#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QApplication>
#include <QLabel>

CProperty::CProperty(QString label, Type type, QWidget *parent) :
    QObject(parent),
    _type(type),
    _label(label),
    _valueWidget(NULL)
{
    _item = new QTreeWidgetItem();
    _item->setText(0, _label);


    if(_type == CProperty::Int)
    {
        QSpinBox* spin = new QSpinBox();
        spin->setMinimum(-99999999);
        spin->setMaximum(99999999);

        _valueWidget = spin;
        connect(spin, SIGNAL(valueChanged(int)), this, SLOT(widgetValueChanged()));
    }

    else if (_type == CProperty::Double)
    {
        QDoubleSpinBox* spin = new QDoubleSpinBox();
        spin->setMinimum(-99999999);
        spin->setMaximum(99999999);

        _valueWidget = spin;
        connect(spin, SIGNAL(valueChanged(double)), this, SLOT(widgetValueChanged()));
    }
    else if (_type == CProperty::Bool)
    {
        QCheckBox *box = new QCheckBox();
        _valueWidget = box;
        connect(box, SIGNAL(stateChanged(int)), this, SLOT(widgetValueChanged()));

    }
    else if(_type == CProperty::Enum)
    {
        QComboBox* box = new QComboBox();
        _valueWidget = box;
        connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(widgetValueChanged()));
    }
    else if(_type == CProperty::Text)
    {
        QLineEdit* edit = new QLineEdit();
        _valueWidget = edit;
        connect(edit, SIGNAL(returnPressed()), this, SLOT(widgetValueChanged()));
    }
    else if(_type == CProperty::Pixmap)
    {
        QPushButton* button = new QPushButton();
        button->setMinimumHeight(32);
        button->setIconSize(QSize(64, 32));
        button->setText("none");
        _valueWidget = button;
        connect(button, SIGNAL(clicked()), this, SLOT(widgetValueChanged()));
    }
    else if(_type == CProperty::Label)
    {
        QLabel* label = new QLabel();
        _valueWidget = label;
        //connect(label, SIGNAL, this, SLOT(widgetValueChanged()));
    }
    else if(_type == CProperty::Vector2)
    {
        CVectorWidget* w = new CVectorWidget(2);
        _valueWidget = w;
        connect(w, SIGNAL(valueChanged()), this, SLOT(widgetValueChanged()));
    }
    else if(_type == CProperty::Vector3)
    {
        CVectorWidget* w = new CVectorWidget(3);
        _valueWidget = w;
        connect(w, SIGNAL(valueChanged()), this, SLOT(widgetValueChanged()));
    }
    else if(_type == CProperty::Vector4)
    {
        CVectorWidget* w = new CVectorWidget(4);
        _valueWidget = w;
        connect(w, SIGNAL(valueChanged()), this, SLOT(widgetValueChanged()));
    }



}

CProperty::~CProperty()
{


}



void CProperty::widgetValueChanged()
{
    if(_type == Pixmap)
    {
        QString fileName = QFileDialog::getOpenFileName(NULL, "Pixmap", "", "*.png *.jpg *.jpeg");
        if(fileName.isEmpty()) return;

        fileName.remove(0, QApplication::applicationDirPath().size()+1);

        QPushButton* button = reinterpret_cast<QPushButton*>(_valueWidget);
        button->setIcon(QIcon(fileName));
        button->setText(fileName);
    }


    emit valueChanged(this);

}


void CProperty::setlabel(QString label)
{
    _label =  label;
}

void CProperty::setValue(QVariant value)
{
    if(_type == CProperty::Int)
    {
        QSpinBox* spin = reinterpret_cast<QSpinBox*>(_valueWidget);
        spin->setValue(value.toInt());

    }

    else if (_type == CProperty::Double)
    {
        QDoubleSpinBox* spin = reinterpret_cast<QDoubleSpinBox*>(_valueWidget);
        spin->setValue(value.toDouble());
    }
    else if (_type == CProperty::Bool)
    {
        QCheckBox* box = reinterpret_cast<QCheckBox*>(_valueWidget);
        box->setChecked(value.toBool());
    }
    else if(_type == CProperty::Enum)
    {
        QComboBox* box = reinterpret_cast<QComboBox*>(_valueWidget);
        box->setCurrentIndex(value.toInt());

    }
    else if(_type == CProperty::Text)
    {
        QLineEdit* edit = reinterpret_cast<QLineEdit*>(_valueWidget);
        edit->setText(value.toString());
    }
    else if(_type == CProperty::Pixmap)
    {

        QPushButton* button = reinterpret_cast<QPushButton*>(_valueWidget);
        button->setIcon(QIcon(value.toString()));
        button->setText(value.toString());
    }
    else if(_type == CProperty::Label)
    {
        QLabel* label = reinterpret_cast<QLabel*>(_valueWidget);
        label->setText(value.toString());
    }
    else if(_type == CProperty::Vector2)
    {
        CVectorWidget* w = reinterpret_cast<CVectorWidget*>(_valueWidget);
        w->setValue(value);
    }
    else if(_type == CProperty::Vector3)
    {
        CVectorWidget* w = reinterpret_cast<CVectorWidget*>(_valueWidget);
        w->setValue(value);
    }
    else if(_type == CProperty::Vector4)
    {
        CVectorWidget* w = reinterpret_cast<CVectorWidget*>(_valueWidget);
        w->setValue(value);
    }


    emit valueChanged(this);
}

void CProperty::setEnumList(QStringList list)
{
    if(_type == CProperty::Enum)
    {
        QComboBox* box = reinterpret_cast<QComboBox*>(_valueWidget);
        box->clear();
        box->addItems(list);
    }
}




CProperty::Type CProperty::type()
{
    return _type;
}

QString CProperty::label()
{
    return _label;
}

QVariant CProperty::value()
{
    if(_type == CProperty::Int)
    {
        QSpinBox* spin = reinterpret_cast<QSpinBox*>(_valueWidget);
        return spin->value();
    }

    else if (_type == CProperty::Double)
    {
        QDoubleSpinBox* spin = reinterpret_cast<QDoubleSpinBox*>(_valueWidget);
        return spin->value();
    }
    else if (_type == CProperty::Bool)
    {
        QCheckBox* box = reinterpret_cast<QCheckBox*>(_valueWidget);
        return box->isChecked();

    }
    else if(_type == CProperty::Enum)
    {

        QComboBox* box = reinterpret_cast<QComboBox*>(_valueWidget);
        return box->currentIndex();
    }
    else if(_type == CProperty::Text)
    {
        QLineEdit* edit = reinterpret_cast<QLineEdit*>(_valueWidget);
        return edit->text();
    }
    else if(_type == CProperty::Pixmap)
    {
        QPushButton* button = reinterpret_cast<QPushButton*>(_valueWidget);
        return button->text();
    }
    else if(_type == CProperty::Label)
    {
        QLabel* label = reinterpret_cast<QLabel*>(_valueWidget);
        return label->text();
    }
    else if(_type == CProperty::Vector2)
    {
        CVectorWidget* w = reinterpret_cast<CVectorWidget*>(_valueWidget);
        return w->value();
    }
    else if(_type == CProperty::Vector3)
    {
        CVectorWidget* w = reinterpret_cast<CVectorWidget*>(_valueWidget);
        return w->value();
    }
    else if(_type == CProperty::Vector4)
    {
        CVectorWidget* w = reinterpret_cast<CVectorWidget*>(_valueWidget);
        return w->value();
    }

    return QVariant();
}

QWidget* CProperty::widget()
{
    return _valueWidget;
}

QTreeWidgetItem* CProperty::item()
{
    return _item;
}

QStringList CProperty::enumList()
{

    if(_type == CProperty::Enum)
    {
        QComboBox* box = reinterpret_cast<QComboBox*>(_valueWidget);
        QStringList list;
        for(int i=0; i<box->count(); i++)
            list.append(box->itemText(i));

        return list;
    }

    return QStringList();
}
