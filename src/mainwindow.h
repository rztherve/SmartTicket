#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include "database.h"
#include "ticket.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(Database &db, QWidget *parent = nullptr);

private slots:
    void addTicket();

private:
    Database &m_db;
    QSqlTableModel *m_model;
    QLineEdit *typeInput;
    QLineEdit *priceInput;
};

#endif // MAINWINDOW_H
