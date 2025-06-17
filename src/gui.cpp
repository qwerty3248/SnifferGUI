#include "../include/gui.hpp"
#include "../include/sniffer.hpp"
#include <QVBoxLayout>
#include <QPushButton>

NetSnifferGUI::NetSnifferGUI(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;

    table = new QTableWidget(0, 4);
    table->setHorizontalHeaderLabels({"Origen", "Destino", "Protocolo", "Tamaño"});
    layout->addWidget(table);

    QPushButton *refreshBtn = new QPushButton("Capturar paquetes");
    layout->addWidget(refreshBtn);
    connect(refreshBtn, &QPushButton::clicked, this, &NetSnifferGUI::loadPackets);

    central->setLayout(layout);
    setCentralWidget(central);
    setWindowTitle("NetSnifferLite");
    resize(600, 400);
}

void NetSnifferGUI::loadPackets() {
    table->setRowCount(0);
    auto packets = capturePackets(20);
    for (const auto &pkt : packets) {
        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pkt.srcIP)));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(pkt.dstIP)));
        table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(pkt.protocol)));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(pkt.length)));
    }
}
