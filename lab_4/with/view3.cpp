#include "view3.h"

View3::View3(QWidget *parent) : QWidget{parent} {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // adding label
    QLabel* label = new QLabel("Adapter pattern");
    label->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    layout->addWidget(label);

    // adding localBar in layout
    QHBoxLayout* localBar = new QHBoxLayout();

    // adding digital clock
    QVBoxLayout* digit = new QVBoxLayout();
    QLabel* digitLabel = new QLabel("Digital clock");
    m_digitTime= new QLabel("-");
    digit->addWidget(digitLabel);
    digit->addWidget(m_digitTime);
    digit->setAlignment(Qt::AlignCenter);
    localBar->addLayout(digit);

    // adding analog clock
    QVBoxLayout* analog = new QVBoxLayout();
    QLabel* analogLabel = new QLabel("Analog clock");
    m_analogTime = new QLabel("-");
    analog->addWidget(analogLabel);
    analog->addWidget(m_analogTime);
    analog->setAlignment(Qt::AlignCenter);
    localBar->addLayout(analog);

    layout->addLayout(localBar);

    // adding line for time
    m_lineEdit = new QLineEdit();
    m_lineEdit->setAlignment(Qt::AlignCenter);
    layout->addWidget(m_lineEdit);

    // adding button for calculating time
    QPushButton* calculating = new  QPushButton("calculating");
    layout->addWidget(calculating);

    connect(calculating, &QPushButton::clicked, this, &View3::calculatingClicked);
}

QString View3::getText() const {
    return m_lineEdit->text();
}

void View3::setAnalog(const QString& time) {
    m_analogTime->setText(time);
}

void View3::setDigit(const QString& time) {
    m_digitTime->setText(time);
}
