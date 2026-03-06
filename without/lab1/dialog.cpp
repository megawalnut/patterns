#include <QFile>

#include "dialog.h"

Dialog::Dialog(QWidget* parent, QLineEdit* lineEdit, QListWidget* listWidget):
    QObject(parent),
    m_line(lineEdit),
    m_list(listWidget) {

    qDebug() << "Dialog::Dialog()";

    connect(m_line, &QLineEdit::textChanged,
            this, [this]() { return notify(m_line, TextChanged); });

    if(!loadData()) {
        qDebug() << "Failed to loadData!";
        return;
    }
}

void Dialog::notify(QWidget* sender, const Command event) const {
    Q_UNUSED(sender)// sender will be used in future implementation
    qDebug() << "Dialog::notify(" << event << ")";

    switch(event){
    case TextChanged: {
        QString displayText = m_line->text();

        for(int i = 0; i < m_list->count(); ++i) {
            const bool match = m_list->item(i)->text().startsWith(displayText, Qt::CaseInsensitive);
            m_list->item(i)->setHidden(!match);
            if(match && m_list->currentItem() == nullptr)
                m_list->setCurrentItem(m_list->item(i));
        }
        break;
    }
    }
}

bool Dialog::loadData() {
    qDebug() << "Dialog::loadData";
    bool result = false;

    QFile file("/home/mikhail/projs/pattern/lab_1/data.txt");
    QTextStream in(&file);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file " << file.fileName();
        m_list->addItem("no data");
        file.close();
        return false;
    }

    while(!in.atEnd()) {
        const QString& str = in.readLine();
        if(!str.isEmpty())
            m_list->addItem(str);
    }

    result = true;
    file.close();
    return result;
}
