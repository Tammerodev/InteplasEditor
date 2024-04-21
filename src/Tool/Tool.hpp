#pragma once
#include "../EditImage.hpp"

class Tool {
    public:
        virtual void use(sf::Vector2i, EditImage& image) = 0;
    private:
};