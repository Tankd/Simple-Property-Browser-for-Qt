#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include <QDebug>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>

#include "src/cvectorwidget.h"

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    browser = new CPropertyBrowser();



    CProperty* p0 = new CProperty("int", CProperty::Int);
    p0->setValue(10);
    browser->addProperty(p0);

    CProperty* p1 = new CProperty("double", CProperty::Double);
    p1->setValue(10.5);
    browser->addProperty(p1);

    CProperty* p2 = new CProperty("Bool", CProperty::Bool);
    p2->setValue(true);
    browser->addProperty(p2);

    CProperty* p3 = new CProperty("StringList", CProperty::Enum);
    QStringList list;
    list << "item 0" << "item 1" << "item 2" << "item 3";
    p3->setEnumList(list);
    p3->setValue(2);
    browser->addProperty(p3);

    CProperty* p4 = new CProperty("Text", CProperty::Text);
    p4->setValue("true");
    browser->addProperty(p4);

    CProperty* p5 = new CProperty("Pixmap", CProperty::Pixmap);
    browser->addProperty(p5);

    CProperty* p51 = new CProperty("Sub Int", CProperty::Int);
    browser->addProperty(p51, p5);

    CProperty *p6 = new CProperty("label", CProperty::Label);
    p6->setValue("label");
    browser->addProperty(p6);

    CProperty *p7 = new CProperty("vector2", CProperty::Vector2);
    p7->setValue(QVector2D(10, -3));
    browser->addProperty(p7);

    CProperty *p8 = new CProperty("vector3", CProperty::Vector3);
    p8->setValue(QVector3D(10, -3, 0));
    browser->addProperty(p8);


    this->setCentralWidget(browser);

    connect(browser, SIGNAL(valueChanged(CProperty*)), this, SLOT(valueChanged(CProperty*)));

}

CMainWindow::~CMainWindow()
{
    //delete browser;
    delete ui;
}

void CMainWindow::valueChanged(CProperty* p)
{
    qDebug() << "value changed";
    qDebug() << p->label();
    qDebug() << p->value();
}


