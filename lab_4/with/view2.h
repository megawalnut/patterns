#ifndef VIEW2_H
#define VIEW2_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>

class View2 : public QWidget {
    Q_OBJECT
public:
    explicit View2(QWidget *parent = nullptr);
    QString selectedType() const;
    QTableWidget* table() const;
signals:
    void createClicked();
    void exportClicked();
    void loadClicked();

private:
    QTableWidget* m_table = nullptr;
    QComboBox* m_typeBox = nullptr;
};

#endif // VIEW2_H
