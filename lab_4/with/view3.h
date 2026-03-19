#ifndef VIEW3_H
#define VIEW3_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

class View3 : public QWidget {
    Q_OBJECT
public:
    explicit View3(QWidget *parent = nullptr);
    QString getText() const;
    void setAnalog(const QString& time);
    void setDigit(const QString& time);
signals:
    void calculatingClicked();
private:
    QLineEdit* m_lineEdit;
    QLabel* m_digitTime;
    QLabel* m_analogTime;
};

#endif // VIEW3_H
