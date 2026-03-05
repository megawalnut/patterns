#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>


#include "textField.h"
#include "listWidget.h"
#include "listMediator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget mainWindow;
    mainWindow.setWindowTitle("Mediator Pattern Example");

    // Create box with components
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    // Create components
    TextField* textField = new TextField(nullptr);
    ListWidget* listWidget = new ListWidget(nullptr);

    // Adding
    layout->addWidget(textField->getWidget());
    layout->addWidget(listWidget->getWidget());

    // Create listMediator
    Mediator* listMediator = new ListMediator(&mainWindow, textField, listWidget);

    textField->setMediator(listMediator);
    listWidget->setMediator(listMediator);

    mainWindow.show();
    return a.exec();
}
