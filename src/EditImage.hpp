#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EditorGlobals.hpp"

class EditImage {
    public:
        void load(sf::Vector2f size);
        void input(sf::Event& ev);
        void render(sf::RenderWindow& target);
        void update();

        const sf::Vector2f getCursorPosition(sf::RenderWindow &window) {
            return window.mapPixelToCoords(mousePosition) + sf::Vector2f(image.getSize() / 2u);
        }

        sf::Vector2i boundToImage(const sf::Vector2i& pos) {
            sf::Vector2i boundPos = pos;

            if(pos.x < 0) boundPos.x = 0;
            if(pos.y < 0) boundPos.y = 0;
            if(pos.x >= image.getSize().x - 1) boundPos.x = image.getSize().x - 1;
            if(pos.y >= image.getSize().y - 1) boundPos.y = image.getSize().y - 1;

            return boundPos;
        }

        sf::Image& getImage() {
            return image;
        }
        
    private:
        sf::Vector2i mousePosition;

        sf::View view;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Image image;

        std::string path = "";
};