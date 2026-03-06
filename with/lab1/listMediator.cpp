#include <QFile>

#include "listMediator.h"
#include "component.h"

ListMediator::ListMediator(QWidget* parent, Component* lineEdit, Component* listWidget):
        Mediator(parent),
        m_enteredText(lineEdit),
        m_listFields(listWidget) {

    qDebug() << "ListMediator::ListMediator()";

    connect(m_enteredText, &Component::changed,
            this, [this]() { return notify(m_enteredText, TextChanged); });

    if(!loadData()) {
        qDebug() << "Failed to loadData!";
        return;
    }
}

void ListMediator::notify(Component* sender, const Command event) {
    Q_UNUSED(sender)// sender will be used in future implementation
    qDebug() << "ListMediator::notify(" << event << ")";

    switch(event){
    case TextChanged: {
        QString displayText = m_enteredText->getText();

        for(int i = 0; i < m_listFields->count(); ++i) {
            const bool match = m_listFields->itemText(i).startsWith(displayText, Qt::CaseInsensitive);
            m_listFields->setItemHidden(i, !match);
            if(match && m_listFields->getCurrentItem() == nullptr)
                m_listFields->setCurrentIndex(i);
        }
        break;
    }
    }
}

bool ListMediator::loadData() {
    qDebug() << "ListMediator::loadData";
    bool result = false;

    QFile file("/home/mikhail/projs/pattern/lab_1/data.txt");
    QTextStream in(&file);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file " << file.fileName();
        m_listFields->addItem("no data");
        file.close();
        return false;
    }

    while(!in.atEnd()) {
        const QString& str = in.readLine();
        if(!str.isEmpty())
            m_listFields->addItem(str);
    }

    result = true;
    file.close();
    return result;
}
