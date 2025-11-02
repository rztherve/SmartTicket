#include <QApplication>
#include "database.h"
#include "ticket.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Database db;
    if (!db.open("smartticket.db") || !db.init()) {
        qWarning() << "❌ Erreur critique de base de données. Sortie.";
        return -1;
    }

    MainWindow w(db);
    w.show();

    return app.exec();
}
