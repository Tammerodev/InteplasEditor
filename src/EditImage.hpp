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
    private:
        sf::View view;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Image image;

        std::string path = "";
};