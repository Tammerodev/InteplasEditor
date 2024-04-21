
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Pencil.hpp"

class ToolManager {
    public:
        void load();
        void update(sf::Vector2i position, EditImage& editImage);
    private:

        int currentToolIndex = 0;
        std::vector<std::shared_ptr<Tool>> tools;
};
