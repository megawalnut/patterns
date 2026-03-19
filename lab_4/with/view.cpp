#include "view.h"
#include "view1.h"
#include "view2.h"
#include "view3.h"

#include "pages.h"

View::View(QWidget* parent) : QWidget{parent} {
    // creating base components
    m_mainLayout = new QHBoxLayout(this);   // the view app |[MENU]|[WORKING AREA]|
    m_menuLayout = new QVBoxLayout();

    // adding menu buttons
    QPushButton* lab1 = new QPushButton("Lab 1");
    QPushButton* lab2 = new QPushButton("Lab 2");
    QPushButton* lab3 = new QPushButton("Lab 3");

    //MENU
    QLabel* label = new QLabel("MENU");
    label->setAlignment(Qt::AlignCenter);

    m_menuLayout->addWidget(label);
    m_menuLayout->addWidget(lab1);
    m_menuLayout->addWidget(lab2);
    m_menuLayout->addWidget(lab3);
    m_menuLayout->setAlignment(Qt::AlignCenter);

    // creating working pages
    m_pages = new QStackedWidget();

    // WORKING PAGES
    QWidget* basePage = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(basePage);

    QLabel* baseLabel = new QLabel("Choose a lab job");
    baseLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(baseLabel);

    // adding pages
    m_pages->addWidget(basePage);
    m_pages->addWidget(new View1());
    m_pages->addWidget(new View2());
    m_pages->addWidget(new View3());

    // current working area - none
    m_pages->setCurrentIndex(BasePage);

    // adding w.p. in mainView
    m_mainLayout->addLayout(m_menuLayout);
    m_mainLayout->addWidget(m_pages);

    // connecting signals with buttons
    connect(lab1, &QPushButton::clicked, this, &View::lab1Clicked);
    connect(lab2, &QPushButton::clicked, this, &View::lab2Clicked);
    connect(lab3, &QPushButton::clicked, this, &View::lab3Clicked);

}

void View::setPage(int index) {
    m_pages->setCurrentIndex(index);
}

View1* View::view1() const {
    return qobject_cast<View1*>(m_pages->widget(Lab1Page));
}

View2* View::view2() const {
    return qobject_cast<View2*>(m_pages->widget(Lab2Page));
}

View3* View::view3() const {
    return qobject_cast<View3*>(m_pages->widget(Lab3Page));
}
