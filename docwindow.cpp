#include "docwindow.h"


void DocWindowIK::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty())
        return;
    QFile file(str);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
    }
    m_strFileName=str;
    changeWindowTitle(m_strFileName);

}

void DocWindowIK::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);

    if(!str.isEmpty())
    {
        m_strFileName=str;
        slotSave();
    }
}

void DocWindowIK::slotSave()
{
    if(m_strFileName.isEmpty())
    {
        slotSaveAs();
        return;
    }

    QFile file(m_strFileName);

    if(file.open(QIODevice::WriteOnly))
        QTextStream(&file)<<toPlainText();

    file.close();
    changeWindowTitle(m_strFileName);
}

void DocWindowIK::slotColor()
{
    QColor color = QColorDialog::getColor(Qt::red, this);
    setTextColor(color);
}
