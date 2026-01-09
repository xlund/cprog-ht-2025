#ifndef TEMPOBJECT_H
#define TEMPOBJECT_H
#include "../GameEngine/GameObject.h"

class TempObject : public GE::GameObject{
    public:
        TempObject(int,int);
        void getPos(int& ,int&) const;
        void setPos(const int, const int);
    private:
};

#endif