#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include "src/cpropertybrowser.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

protected slots:
    void valueChanged(CProperty*);

    
private:
    Ui::CMainWindow *ui;

    CPropertyBrowser *browser;
};

#endif // CMAINWINDOW_H
