#include "ToolManager.hpp"

void ToolManager::load() {
    tools.push_back(std::make_shared<Pencil>());
}
 
void ToolManager::update(sf::Vector2i position, EditImage& editImage) {
    if(currentToolIndex < 0) currentToolIndex = 0;
    if(currentToolIndex >= tools.size() - 1) currentToolIndex = tools.size() - 1;

    std::cout << "Pos x " << position.x << ", y " << position.y << std::endl;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        tools.at(currentToolIndex)->use(editImage.boundToImage(position), editImage);
    }
}
