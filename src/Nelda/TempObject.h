#ifndef TEMPOBJECT_H
#define TEMPOBJECT_H
class TempObject{
    public:
        void getPos(int& ,int&) const;
        void setPos(const int, const int);
    private:
    int x;
    int y;
};

#endif