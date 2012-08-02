#ifndef CPROPBROWSER_H
#define CPROPBROWSER_H

#include "cproperty.h"
#include <QList>
#include <QTreeWidget>





/**
 * \class CPropertyBrowser
 * Widget for managing property browser, properties.
 * Based on QTreeWidget
 *
 */


class CPropertyBrowser : public QTreeWidget
{
    Q_OBJECT

    friend class CProperty;

signals:
    //value in browser changed
    void valueChanged(CProperty*);


    
public:
    explicit CPropertyBrowser(QWidget *parent = 0);
    ~CPropertyBrowser();

    /**
     * \brief    Add a child property to browser
     * \param p : property to add
     * \param parent : if null p is add in browser. Else p is add as parent child
     */
    void addProperty(CProperty* p, CProperty* parent = NULL);





protected slots:
    void propertyValueChanged(CProperty* p);


};

#endif // CPROPBROWSER_H
