#ifndef LISTMEDIATOR_H
#define LISTMEDIATOR_H

#include "mediator.h"
#include "command.h"

// The concrete class - dialog

class ListMediator : public Mediator {
    Q_OBJECT
public:
    explicit ListMediator(Component* lineEdit = nullptr, Component* listWidget = nullptr, QWidget* parent = nullptr);
    void notify(Component* sender, const Command event) override;

private:
    bool loadData();

private:
    Component* m_enteredText;
    Component* m_listFields;
};

#endif // LISTMEDIATOR_H
