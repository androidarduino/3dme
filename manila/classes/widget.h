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

class VisibleItem
{
public:
    VisibleItem();
};

class Seat;

class Boss;

class Sailor: public VisibleItem
{
public:
    Sailor();
    int d_cash;
    Boss * d_boss;
    Seat * d_seat;
public:
    bool takeSeat(Seat* seat);
    void getProfit();
    void handInProfit();
};

class Seat: public VisibleItem
{
public:
    Seat(int cost);
    int d_cost;
    Sailor* d_owner;
public:
    void blink(bool blinkOrNot);
    bool takeSeat(Sailor* sailor);
};

class Stock: public VisibleItem
{
public:
    Stock();
public:
    QString d_type;
};

class Goods: public VisibleItem
{
public:
    Goods();
    QString d_type;
    int d_seatsCount;
};

class Dock
{
public:
    Dock();
public:
    Seat* d_seat;
    int d_profit;
    Boat* d_boat;
public:
    bool boatIn(Boat* boat);
    void calculateProfits();
};

class Pilot
{
public:
    Pilot();
    Seat * d_seat;
public:
    void calculateProfits();
};

class PirateBoat: public VisibleItem
{
public:
    PirateBoat();
public:
    Seat * d_seat1, * d_seat2;
public:
    void patrol();
    void invade(Boat* boat);
};

class Insurance: public VisibleItem
{
public:
    Insurance();
public:
    Seat * d_seat;
public:
    void compensate(Dock* dock);
};

class Bank
{
public:
    Bank();
    QList<Stock*> d_stocks;
    QMap<QString, int> d_stockPrices;
public:
    bool tradeInStock(Boss* boss, Stock* stock);
    bool purchaseStock(Boss* boss, Stock* stock);
    bool stockUp(QString type);
};

class Boss
{
public:
    Boss();
public:
    QList<Stock*> d_stocks;
    int d_cash;
public:
    void host();
    void playRound();
};

class Dice: public VisibleItem
{
public:
    Dice();
public:
    int throwDice();
};

class Boat: public VisibleItem
{
public:
    Boat();
    QColor d_color;
    Goods * d_goods;
    QList<Seat*> d_seats;
    int d_currentPosition;
    Dice * dice;
public:
    bool putOnGoods(Goods* good);
    bool move();
};

class Board
{
public:
    Board(int playerCount=3, int initFund=30);
    void setup();
    void doRound();
    void doStep();
public:
    QList<Boss*> bosses;
private:
    Dock * goalA, * goalB, * goalC;
    Dock * failA, * failB, * failC;
    PirateBoat* pirateBoat;
    Pilot * smallPilot, * bigPilot;
    Insurance * insurance;
    Bank * bank;
};

/*
void main()
{
    Board* board=new Board();
    board->setup();
    while(board->doRound())
    {
    }
    displayScore(board);
}
  */

}
#endif // WIDGET_H
