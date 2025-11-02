#include "mainwindow.h"
#include <QMessageBox>
#include <QDoubleValidator>

MainWindow::MainWindow(Database &db, QWidget *parent)
    : QMainWindow(parent), m_db(db)
{
    // Table
    m_model = new QSqlTableModel(this, m_db.db());
    m_model->setTable("tickets");
    m_model->select();

    auto *tableView = new QTableView;
    tableView->setModel(m_model);

    // Formulaire
    typeInput = new QLineEdit;
    priceInput = new QLineEdit;
    QDoubleValidator *priceValidator = new QDoubleValidator(0.00, 9999.99, 2, this);
    priceInput->setValidator(priceValidator);
    auto *addButton = new QPushButton("Ajouter un ticket");

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTicket);

    // Layout
    auto *layout = new QVBoxLayout;
    layout->addWidget(tableView);
    layout->addWidget(typeInput);
    layout->addWidget(priceInput);
    layout->addWidget(addButton);

    auto *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    setWindowTitle("SmartTicket - Billettique Démo");
}

void MainWindow::addTicket() {
    QString type = typeInput->text();
    double price = priceInput->text().toDouble();

    if (type.isEmpty() || price <= 0) {
        QMessageBox::warning(this, "Erreur", "Champs invalides !");
        return;
    }

    Ticket t(type, price);
    if (t.save(m_db)) {
        m_model->select(); // refresh view
        typeInput->clear();
        priceInput->clear();
    }
}
