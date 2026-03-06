#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QObject>
#include <QLineEdit>
#include <QListWidget>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget mainWindow;
    mainWindow.setWindowTitle("Without Mediator's Pattern");

    // Create box with components
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    // Create components
    QLineEdit* textField = new QLineEdit(&mainWindow);
    QListWidget* listWidget = new QListWidget(&mainWindow);

    // Adding
    layout->addWidget(textField);
    layout->addWidget(listWidget);

    // Create listMediator
    Dialog listMediator(&mainWindow, textField, listWidget);

    mainWindow.show();
    return a.exec();
}
