#ifndef CPROPERTY_H
#define CPROPERTY_H

#include <QVariant>
#include <QTreeWidgetItem>



/**
 * \class CProperty
 *  A property for insert in CPropertyBrowser
 */
class CProperty : public QObject
{
    Q_OBJECT

signals:
    void valueChanged(CProperty* p);
    
public:
    /**
     * \brief      CProperty Type
     * \details  Type define the Widget used
     */
    enum Type
    {
        Int,   /*!< QSpinBox               */
        Double, /*!<  QDoucleSpinBox               */
        Bool, /*!< QCheckBox               */
        Enum, /*!<  QComboboxBox               */
        Text, /*!<  QLineEdit               */
        Pixmap, /*!< QPushButton with pixmap icon               */
        Label, /*!< QLabel                */
        Vector2, /*!< 2x QDoubleSpinBox               */
        Vector3, /*!< 3x QDoubleSpinBox               */
        Vector4, /*!< 4x QDoubleSpinBox               */
    };

    /**
     * \brief      CProperty Constructor
     * \param label : label for this property
     * \param type : type of the property
     */
    CProperty(QString label, Type type, QWidget *parent = 0);
    ~CProperty();


    /**
     * \brief     set a new label for the property
     * \param label : label for this property
     */
    void setlabel(QString label);

    /**
     * \brief     set a new value for the property
     * emit valueChanged signal
     * \param value : new value for this property
     */
    void setValue(QVariant value);

    /**
     * \brief     set the list for Enum property
     * \param list : the list for the ComboBox
     */
    void setEnumList(QStringList list);


    /**
     * \return the type of the property
     */
    Type type();

    /**
     * \return the label of the property
     */
    QString label();

    /**
     * \return the value of the property
     */
    QVariant value();

    /**
     * \return the widget generated of the property
     */
    QWidget* widget();

    /**
     * \return the item of the property
     */
    QTreeWidgetItem* item();

    /**
     * \return the Enum list of the property
     */
    QStringList enumList();



protected slots:
    void widgetValueChanged();
    
private:

    QString _label;
    Type _type;

    QWidget *_valueWidget;
    QTreeWidgetItem* _item;
};

#endif // CPROPWIDGET_H
