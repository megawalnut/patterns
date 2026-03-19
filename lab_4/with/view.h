#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QListView>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>

#include "view1.h"
#include "view2.h"
#include "view3.h"

class View : public QWidget {
    Q_OBJECT
public:
    explicit View(QWidget* parent = nullptr);
    void setPage(int index);

    View1* view1() const;
    View2* view2() const;
    View3* view3() const;
signals:
    void lab1Clicked();
    void lab2Clicked();
    void lab3Clicked();

private:
    QHBoxLayout* m_mainLayout = nullptr;
    QVBoxLayout* m_menuLayout = nullptr;
    QStackedWidget* m_pages = nullptr;
};

#endif // VIEW_H

