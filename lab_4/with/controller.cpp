#include <algorithm>

#include "controller.h"

#include "pages.h"
#include "view2.h"
#include "types.h"
#include "entry.h"
#include "utils.h"
#include "realDigitalClock.h"
#include "analogClock.h"
#include "adapter.h"

Controller::Controller(View* view) : QObject(view), m_view{view} {
    // connect signals with slots
    //lab1
    connect(m_view, &View::lab1Clicked, this, &Controller::onLab1Clicked);
    connect(m_view, &View::lab2Clicked, this, &Controller::onLab2Clicked);
    connect(m_view, &View::lab3Clicked, this, &Controller::onLab3Clicked);
    //lab2
    connect(m_view->view2(), &View2::createClicked, this, &Controller::onCreateLab2);
    connect(m_view->view2(), &View2::loadClicked,   this, &Controller::onLoadLab2);
    connect(m_view->view2(), &View2::exportClicked, this, &Controller::onExportLab2);
    //lab3
    connect(m_view->view3(), &View3::calculatingClicked, this, &Controller::onCalculatingClicked);
}

void Controller::onLab1Clicked() {
    m_view->setPage(Lab1Page);
}

void Controller::onLab2Clicked() {
    m_view->setPage(Lab2Page);
}

void Controller::onLab3Clicked() {
    m_view->setPage(Lab3Page);
}

void Controller::onCreateLab2() {
    View2* v2 = m_view->view2();

    Types type = parseType(v2->selectedType());
    Entry* obj = createConcreteClass(type);
    obj->setType(type);

    if (!obj) return;

    int row = v2->table()->rowCount();
    v2->table()->insertRow(row);
    v2->table()->setItem(row, 0, new QTableWidgetItem(parseTypeToString(obj->getType())));

    delete obj;
}

void Controller::onLoadLab2() {
    View2* v2 = m_view->view2();

    std::vector<QString> rawLines;
    std::vector<QStringList> entries =
        fromFile("/home/mikhail/projs/pattern/lab_4/in.tsv", rawLines);

    v2->table()->setRowCount(0);

    // 1) считаем макс. число колонок
    int maxCols = 0;
    for (const auto& parts : entries) {
        maxCols = std::max(maxCols, static_cast<int>(parts.size()));
    }

    v2->table()->setColumnCount(maxCols);

    // 2) заполняем таблицу
    for (const auto& parts : entries) {

        Types type = parseType(parts[0]);
        Entry* obj = createConcreteClass(type);
        obj->init(parts);

        int row = v2->table()->rowCount();
        v2->table()->insertRow(row);

        for (int col = 0; col < parts.size(); col++) {
            v2->table()->setItem(row, col, new QTableWidgetItem(parts[col]));
        }

        delete obj;
    }
}

void Controller::onExportLab2() {
    View2* v2 = m_view->view2();

    std::vector<QString> lines;

    for (int row = 0; row < v2->table()->rowCount(); row++) {

        QStringList parts;

        for (int col = 0; col < v2->table()->columnCount(); col++) {
            auto item = v2->table()->item(row, col);
            parts << (item ? item->text() : "");
        }

        lines.push_back(parts.join("\t"));
    }

    toFile("/home/mikhail/projs/pattern/lab_4/ou.tsv", lines);
}

void Controller::onCalculatingClicked() {
    View3* v3 = m_view->view3();

    QString time = v3->getText();

    RealDigitalClock real;
    real.setTime(time);

    AnalogClock analog;
    Adapter adapter(&analog);
    adapter.setTime(time);

    v3->setDigit(real.getTime().toString("hh:mm:ss"));
    v3->setAnalog(adapter.getTime().toString("hh:mm:ss"));
}
