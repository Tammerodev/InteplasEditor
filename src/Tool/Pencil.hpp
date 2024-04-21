#pragma once
#include "Tool.hpp"

class Pencil : public Tool {
    public:
        void use(sf::Vector2i pos, EditImage& image) {
            image.getImage().setPixel(pos.x, pos.y, sf::Color::Blue);
        }

};