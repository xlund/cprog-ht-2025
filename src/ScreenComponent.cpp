#include "ScreenComponent.h"
GE::ScreenComponent::ScreenComponent() {}

int GE::ScreenComponent::getHeight() { return 0; }
int GE::ScreenComponent::getWidth() { return 0; }
int GE::ScreenComponent::getX() { return 0; }
int GE::ScreenComponent::getY() { return 0; }
int GE::ScreenComponent::getRotation() { return 0; }

void GE::ScreenComponent::setHeight(int h) { height = h; }
void GE::ScreenComponent::setWidth(int w) { width = w; }
void GE::ScreenComponent::setX(int x) { this->x = x; }
void GE::ScreenComponent::setY(int y) { this->y = y; }
void GE::ScreenComponent::setRotation(int rot) { rotation = rot; }
