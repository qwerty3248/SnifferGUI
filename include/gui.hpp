#pragma once
#include <QMainWindow>
#include <QTableWidget>

class NetSnifferGUI : public QMainWindow {
    Q_OBJECT
public:
    NetSnifferGUI(QWidget *parent = nullptr);
private:
    QTableWidget *table;
    void loadPackets();
};
