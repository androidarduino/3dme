#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

namespace Manila
{

class Seat;

class Boss;

class Sailor
{
public:
    Sailor();
    int d_profit;
    Boss * d_boss;
    Seat * d_seat;
public:
    bool takeSeat(Seat* seat);
    void getProfit();
    void handInProfit();
};

class Seat
{
public:
    Seat(int cost);
    int d_cost;
    Sailor* d_owner;
};

class Goods
{
public:
    Goods();
    QString d_name;
    QString d_picture;
    int d_seatsCount;
};

class Dock
{
};

class Pilot
{

};

class PirateBoat
{

};

class Insurance
{

};

class Boat
{
public:
    Boat();
    QColor d_color;
    Goods * d_goods;
    QList<Seat*> d_seats;
public:
    void move(int steps);
    bool takeSeat(Sailor* sailor);
};

class Board
{
public:
    Board(int playerCount=3, int initFund=30);
public:
    QList<Player*> players;
private:
    Dock * goalA, * goalB, * goalC;
    Dock * failA, * failB, * failC;
    PirateBoat* pirateBoat;
    Pilot * smallPilot, * bigPilot;
    Insurance * insurance;
};

}
#endif // WIDGET_H
