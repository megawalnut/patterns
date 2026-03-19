#include <QApplication>
#include <QWidget>

#include "view.h"
#include "controller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // MVC части
    View* view = new View();
    Controller* controller = new Controller(view);

    view->show();
    return a.exec();
}
