#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class EditImage {
    public:
        void render(sf::RenderTarget& target);
        void update();
    private:
        sf::View view;
        sf::Texture texture;
        sf::Sprite sprite;
};