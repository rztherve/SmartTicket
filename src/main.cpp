#include <QApplication>
#include "database.h"
#include "ticket.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Database db;
    if (!db.open("smartticket.db") || !db.init())
        return -1;


    MainWindow w(db);
    w.show();

    // // Test insertion
    // Ticket t1("Bus", 1.5);
    // t1.save(db);

    // // Lecture et affichage
    // auto tickets = Ticket::getAll(db);
    // for (const auto &t : tickets) {
    //     qDebug() << "ID:" << t.id
    //              << "| Type:" << t.type
    //              << "| Prix:" << t.price
    //              << "| Créé le:" << t.createdAt;
    // }

    return app.exec();
}
