#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <QLineEdit>

#include "component.h"

// The concrete class - Component

class TextField : public Component {
    Q_OBJECT
public:
    explicit TextField(Mediator* parent = nullptr) : Component(parent), m_enteredText(new QLineEdit(nullptr)) {
        qDebug() << "TextField::TextField()";

        connect(m_enteredText, &QLineEdit::textEdited,
                this, &TextField::onTextChanged);
    }

    QWidget* getWidget() const override {
        qDebug() << "TextField::getWidget()";

        return m_enteredText;
    }

    QString getText() const override {
        qDebug() << "TextField::getText()";

        return m_enteredText->text();
    }

public slots:
    void onTextChanged() {
        qDebug() << "TextField::onTextChanged()";

        emit changed();
    }

private:
    QLineEdit* m_enteredText;
};

#endif // TEXTFIELD_H
