#include <QCoreApplication>
#include "database.h"
#include "ticket.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Database db;
    if (!db.open("smartticket.db"))
        return -1;

    if (!db.init())
        return -1;

    // Test insertion
    Ticket t1("Bus", 1.5);
    t1.save(db);

    // Lecture et affichage
    auto tickets = Ticket::getAll(db);
    for (const auto &t : tickets) {
        qDebug() << "ID:" << t.id
                 << "| Type:" << t.type
                 << "| Prix:" << t.price
                 << "| Créé le:" << t.createdAt;
    }

    return 0;
}
