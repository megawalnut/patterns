#include "view2.h"

View2::View2(QWidget *parent) : QWidget{parent} {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // adding label
    QLabel* label = new QLabel("Factory pattern");
    layout->addWidget(label);

    // adding localBar in layout
    QHBoxLayout* localBar = new QHBoxLayout();
    QPushButton* load = new QPushButton("Load from file");
    QPushButton* exp = new QPushButton("Export to file");
    localBar->addWidget(load);
    localBar->addWidget(exp);
    layout->addLayout(localBar);

    // adding table in layout
    m_table = new QTableWidget(this);
    layout->addWidget(m_table);

    // adding toolBar in layout
    QHBoxLayout* toolBar = new QHBoxLayout();
    QPushButton* create = new QPushButton("Create field");
    m_typeBox = new QComboBox();
    m_typeBox->addItem("player");
    m_typeBox->addItem("team");
    m_typeBox->addItem("match");
    toolBar->addWidget(create);
    toolBar->addWidget(m_typeBox);
    layout->addLayout(toolBar);

    connect(create, &QPushButton::clicked, this, &View2::createClicked);
    connect(exp, &QPushButton::clicked, this, &View2::exportClicked);
    connect(load, &QPushButton::clicked, this, &View2::loadClicked);
}

QString View2::selectedType() const {
    return m_typeBox->currentText();
}

QTableWidget* View2::table() const {
    return m_table;
}
