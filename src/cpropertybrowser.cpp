#include "cpropertybrowser.h"





#include <QHeaderView>
#include <QDebug>


CPropertyBrowser::CPropertyBrowser(QWidget *parent) :
    QTreeWidget(parent)
{

    this->setColumnCount(2);
    QStringList headers;
    headers << "properties" << "values";
    this->setHeaderLabels(headers);
    this->header()->setResizeMode(QHeaderView::Stretch);

    this->setAlternatingRowColors(true);
    setAlternatingRowColors(1);

    setStyleSheet(" QTreeView {\n     alternate-background-color: rgb(200, 220, 220);\n }\n\n QTreeView {\n     show-decoration-selected: 1;\n }\n\n QTreeView::item {\n      border: 1px solid #d9d9d9;\n     border-top-color: transparent;\n     border-bottom-color: transparent;\n }\n\n QTreeView::item:hover {\n     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);\n     border: 1px solid #bfcde4;\n }\n\n QTreeView::item:selected {\n     border: 1px solid #567dbc;\n }\n\n QTreeView::item:selected:active{\n     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);\n }\n\n QTreeView::item:selected:!active {\n     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6b9be8, stop: 1 #577fbf);\n }\n\n\nQTreeView::branch:has-siblings:!adjoins-item {\n     border-image: url(:/vline.png) 0;\n }\n\n QTreeView::branch:has-siblings:adjoins-item {\n     border-image: url(:/branch-more.png) 0;\n }\n\n QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n     border-image: url(:/branch-end.png) 0;\n }\n\n QTreeView::branch:has-children:!has-siblings:closed,\n QTreeView::branch:closed:has-children:has-siblings {\n         border-image: none;\n         image: url(:/branch-closed.png);\n }\n\n QTreeView::branch:open:has-children:!has-siblings,\n QTreeView::branch:open:has-children:has-siblings  {\n         border-image: none;\n         image: url(:/branch-open.png);\n }");



}

CPropertyBrowser::~CPropertyBrowser()
{

}

void CPropertyBrowser::addProperty(CProperty* p, CProperty* parent)
{
    if(parent == NULL)
    {
        addTopLevelItem(p->item());
    }
    else
    {
        parent->item()->addChild(p->item());
    }

    setItemWidget(p->item(), 1, p->widget());
    connect(p, SIGNAL(valueChanged(CProperty*)), this, SLOT(propertyValueChanged(CProperty*)));
}


void CPropertyBrowser::propertyValueChanged(CProperty* p)
{
    emit valueChanged(p);
}
