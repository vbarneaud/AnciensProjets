/*
** CMainWindow.cpp for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 12:04:12 2013 vincent leroy
** Last update Sun Mar 10 12:17:43 2013 vincent leroy
*/

#include <QApplication>
#include "CMainWindow.h"

CMainWindow::CMainWindow() :
    QMainWindow(),
    _listDir(new QListWidget),
    _listMail(new QTableWidget(0, 3)),
    _hlay(new QHBoxLayout),
    _vlay(new QVBoxLayout),
    _textMail(new QTextEdit),
    _toolBar(new QToolBar),
    _refresh(NULL),
    _new(NULL),
    _edit(NULL),
    _delete(NULL),
    _newMsg(new NewMsg(this)),
    _setting(new Setting),
    _editAccount(new EditAccount),
    _timerRefresh(new QTimer),
    _socket(NULL),
    _smtp(NULL)
{
    setCentralWidget(new QWidget(this));

    QStringList list;
    list << "ID" << "Titre" << "Date";

    _listDir->setMaximumWidth(300);
    _textMail->setReadOnly(true);
    _new = _toolBar->addAction("New");
    _edit = _toolBar->addAction("Edit account");
    _refresh = _toolBar->addAction("Refresh");
    _delete = _toolBar->addAction("Delete");
    _toolBar->setFloatable(false);
    _toolBar->setMovable(false);
    _listMail->setShowGrid(false);
    _listMail->verticalHeader()->hide();
    _listMail->horizontalHeader()->setStretchLastSection(true);
    _listMail->setHorizontalHeaderLabels(list);
    _listMail->setColumnWidth(1, 200);

    addToolBar(_toolBar);
    centralWidget()->setLayout(_hlay);
    _hlay->addWidget(_listDir);
    _hlay->addLayout(_vlay);
    _vlay->addWidget(_listMail);
    _vlay->addWidget(_textMail);

    QObject::connect(_new, SIGNAL(triggered(bool)), this, SLOT(_new_triggered()));
    QObject::connect(_refresh, SIGNAL(triggered(bool)), this, SLOT(_refresh_triggered()));
    QObject::connect(_edit, SIGNAL(triggered(bool)), this, SLOT(_edit_triggered()));
    QObject::connect(_delete, SIGNAL(triggered(bool)), this, SLOT(_delete_triggered()));
    QObject::connect(_listDir, SIGNAL(currentRowChanged(int)), this, SLOT(_listDir_currentRowChanged(int)));
    QObject::connect(_listMail, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(_listMail_itemPressed(QTableWidgetItem*)));
    QObject::connect(_timerRefresh, SIGNAL(timeout()), this, SLOT(_refresh_triggered()));

    _init();

    _timerRefresh->start(300000);
}

CMainWindow::~CMainWindow()
{
}

Setting* CMainWindow::getSetting()
{
    return _setting;
}

void CMainWindow::reconnect()
{
    delete _socket;
    delete _smtp;

    _init();
}

void CMainWindow::majDir()
{
    QStringList strlist;
    std::list<std::string> list;

    try
    {
        list = _socket->getFolders();
        for (std::list<std::string>::iterator it = list.begin(); it != list.end(); ++it)
            strlist << it->c_str();
    }
    catch (const std::exception &e)
    {
        QMessageBox::critical(this, "Folders", "Get folders error " + QString(e.what()));
    }

    _listDir->clear();
    _listDir->addItems(strlist);
    _textMail->clear();
    _listMail->setRowCount(0);
}

void CMainWindow::sendMsg(const QString &to, const QString &subject, const QString &text)
{
    try
    {
        QApplication::setOverrideCursor(Qt::BusyCursor);
        if (!_smtp->sendMsg(qPrintable(to), qPrintable(_setting->getLogin()), qPrintable(subject), qPrintable(text)))
            QMessageBox::critical(this, "Send message", "Fail to send message");
    }
    catch (const std::exception &e)
    {
        QMessageBox::critical(this, "Send message", "Fail to send message " + QString(e.what()));
    }
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}

void CMainWindow::_init()
{
    if (_setting->getProtocol() == "IMAP")
        _socket = new Protocol::IMAP;
    else
        _socket = new Protocol::POP3;

    if (!_setting->getIpReceveur().isEmpty())
    {
        try
        {
            _socket->connect(qPrintable(_setting->getIpReceveur()), _setting->getPortReceveur());
            if (!_socket->login(qPrintable(_setting->getLogin()), qPrintable(_setting->getMdp())))
                QMessageBox::critical(this, "Login " + _setting->getProtocol(), "Authentification failure");
            try
            {
                _smtp = new Protocol::SMTP;
                _smtp->connect(qPrintable(_setting->getIpSender()), _setting->getPortSender());
                QByteArray login(qPrintable(_setting->getLogin()));
                QByteArray mdp(qPrintable(_setting->getMdp()));
                if (!_smtp->login(qPrintable(QString(login.toBase64())), qPrintable(QString(mdp.toBase64()))))
                    QMessageBox::critical(this, "Login SMTP", "Authentification failure");
            }
            catch (const std::exception &e)
            {
                QMessageBox::critical(this, "Connection", "Connection SMTP failure " + QString(e.what()));
            }
            majDir();
        }
        catch (const std::exception &e)
        {
            QMessageBox::critical(this, "Connection", "Connection" + _setting->getProtocol() + "failure " + QString(e.what()));
        }
    }
}

void CMainWindow::_delete_triggered()
{
    QList<QTableWidgetItem*> list = _listMail->selectedItems();
    QList<int> realList;

    for (int i = 0; i < list.size(); ++i)
    {
        if (!realList.contains(list[i]->row()))
            realList.append(list[i]->row());
    }
    qSort(realList.begin(), realList.end());
    for (int i = 0; i < realList.size(); ++i)
    {
        QTableWidgetItem *item = _listMail->item(realList[i], 0);
        try
        {
            _socket->removeMail(qPrintable(item->text()));
            _listMail->removeRow(realList[i]);
            for (int j = i; j < realList.size(); ++j)
                realList.replace(j, realList[j] - 1);
        }
        catch (const std::exception &e)
        {
        QMessageBox::critical(this, "Delete", "Can't delete row " + QString::number(realList[i] + 1));
        }
    }
}

void CMainWindow::_refresh_triggered()
{
    _listDir_currentRowChanged(_listDir->currentRow());
}

void CMainWindow::_new_triggered()
{
    _newMsg->show();
}

void CMainWindow::_edit_triggered()
{
    _editAccount->show();
}

void CMainWindow::_listDir_currentRowChanged(int row)
{
    std::list<std::vector<std::string> > list;
    int i;

    if (row >= 0)
    {
        QApplication::setOverrideCursor(Qt::BusyCursor);
        _listMail->setRowCount(0);
        i = 0;
        try
        {
            list = _socket->getMails(qPrintable(_listDir->currentItem()->text()));
            for (std::list<std::vector<std::string> >::iterator it = list.begin(); it != list.end(); ++it)
            {
                _listMail->setRowCount(_listMail->rowCount() + 1);
                for (int j = 0; j < 3; ++j)
                {
                    QTableWidgetItem *item = new QTableWidgetItem((*it)[j].c_str());
                    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
                    _listMail->setItem(i, j, item);
                }
                ++i;
            }
        }
        catch (const std::exception &e)
        {
            QMessageBox::critical(this, "Mails", "Get mails error " + QString(e.what()));
        }
        QApplication::setOverrideCursor(Qt::ArrowCursor);
    }
}

void CMainWindow::_listMail_itemPressed(QTableWidgetItem *item)
{
    if (!item)
        return ;
    QApplication::setOverrideCursor(Qt::BusyCursor);
    try
    {
        std::string mail = _socket->getMail(qPrintable(_listMail->item(item->row(), 0)->text()));
        if (mail.find("<html>") != std::string::npos)
            _textMail->setHtml(mail.c_str());
        else
            _textMail->setPlainText(mail.c_str());
    }
    catch (const std::exception &e)
    {
        QMessageBox::critical(this, "Mail", "Get mail error " + QString(e.what()));
    }
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}
