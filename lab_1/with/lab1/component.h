#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QListWidgetItem>

#include "mediator.h"

// The interface class for UI components

class Component : public QObject {
    Q_OBJECT
public:
    explicit Component(Mediator* const parent = nullptr)
        : QObject(nullptr), m_parent(parent) {}

    void setMediator(Mediator* const other) {
        m_parent = other;
    }

    Mediator* getMediator() {
        return m_parent;
    }

    virtual QWidget* getWidget() const {
        return nullptr;
    }

    // for TextFieldComponents
    virtual QString getText() const {
        return QString();
    }

    // for ListWidgetComponents
    virtual int count() const {
        return 0;
    }
    virtual QString itemText(int i) const {
        return QString();
    }
    virtual void setItemHidden(int i, bool hide) {}
    virtual void setCurrentIndex(int i) {}
    virtual void addItem(const QString& text) {}
    virtual QListWidgetItem* getCurrentItem() const {
        return nullptr;
    }

    virtual ~Component() = default;

signals:
    void changed(); // the base signal

private:
    Mediator* m_parent = nullptr;
};

#endif // COMPONENT_H
