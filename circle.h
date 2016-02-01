#ifndef CIRCLE_H
#define CIRCLE_H




class circle {

public:
    circle();
    ~circle();

    void setX(int X_);
    void setY(int Y_);
    int getX();
    int getY();



    static int countCircle;
    int X,Y;

private:


    int radius,speed;
};

#endif // CIRCLE_H
