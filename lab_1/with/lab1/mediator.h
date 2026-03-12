#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QWidget>

#include "command.h"

// The interface class for dialogs

class Component;    //forward declaration

class Mediator : public QWidget {
    Q_OBJECT
public:
    Mediator(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~Mediator() = default;
    virtual void notify(Component* sender, const Command event) = 0;
};

#endif // MEDIATOR_H
