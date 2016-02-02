#ifndef CIRCLE_H
#define CIRCLE_H

class circle {

public:
    circle();
    ~circle();

    void setX(int X_);
    void setY(int Y_);
    int getX() const;
    int getY() const;



    static int countCircle;
    int X,Y;

    int getID() const;
    void setID(int value);

private:

    int ID;
    int radius,speed;
};

#endif // CIRCLE_H
