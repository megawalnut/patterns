#include "view1.h"
#include "textField.h"
#include "listWidget.h"
#include "listMediator.h"

View1::View1(QWidget *parent) : QWidget{parent} {
    // Create box with components
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Create components
    QLabel* label = new QLabel("Mediator Pattern");
    TextField* textField = new TextField();
    ListWidget* listWidget = new ListWidget();

    // Adding
    layout->addWidget(label);
    layout->addWidget(textField->getWidget());
    layout->addWidget(listWidget->getWidget());

    // Create listMediator
    Mediator* listMediator = new ListMediator(textField, listWidget);

    textField->setMediator(listMediator);
    listWidget->setMediator(listMediator);
}
