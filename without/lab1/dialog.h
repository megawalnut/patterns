#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>
#include <QLineEdit>
#include <QListWidget>

class Dialog : public QObject {
    Q_OBJECT
public:
    enum Command : int {
        TextChanged = 0
    };

public:
    explicit Dialog(QWidget* parent, QLineEdit* lineEdit, QListWidget* listWidget);
    void notify(QWidget* sender, const Command event) const;

private:
    bool loadData();

private:
    QLineEdit* m_line;
    QListWidget* m_list;
};

#endif // DIALOG_H
