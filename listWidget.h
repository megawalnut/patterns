#ifndef LISTMWIDGET_H
#define LISTMWIDGET_H

#include <QLineEdit>
#include <QListWidget>

#include "component.h"

// The concrete class - Component

class ListWidget : public Component {
    Q_OBJECT
public:
    explicit ListWidget(Mediator* parent = nullptr) : Component(parent), m_listWidget(new QListWidget(nullptr)) {
        qDebug() << "ListWidget::ListWidget()";
    }

    QWidget* getWidget() const override {
        qDebug() << "ListWidget::getWidget()";

        return m_listWidget;
    }

    int count() const override{
        qDebug() << "ListWidget::count()";

        return m_listWidget->count();
    }
    QString itemText(int i) const override {
        qDebug() << "ListWidget::itemText()";

        return m_listWidget->item(i)->text();
    }
    void setItemHidden(int i, bool hide) override {
        qDebug() << "ListWidget::setItemHidden()";

        m_listWidget->item(i)->setHidden(hide);
    }
    void setCurrentIndex(int i) override {
        qDebug() << "ListWidget::setCurrentIndex()";

        m_listWidget->setCurrentItem(m_listWidget->item(i));
    }
    void addItem(const QString& text) override {
        m_listWidget->addItem(text);
    }
    QListWidgetItem* getCurrentItem() const override {
        qDebug() << "ListWidget::getCurrentItem()";

        return m_listWidget->currentItem();
    }

private:
    QListWidget* m_listWidget;
};


#endif // LISTMWIDGET_H
