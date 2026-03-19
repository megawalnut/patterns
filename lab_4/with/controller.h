#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "view.h"

class Controller : public QObject {
    Q_OBJECT
public:
    explicit Controller(View* view);

private slots:
    //lab1
    void onLab1Clicked();
    void onLab2Clicked();
    void onLab3Clicked();

    //lab2
    void onCreateLab2();
    void onLoadLab2();
    void onExportLab2();

    //lab3
    void onCalculatingClicked();

private:
    View* m_view;
};

#endif // CONTROLLER_H
