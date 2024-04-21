#include "EditImage.hpp"

void EditImage::load(sf::Vector2f size) {
    view.setSize(size);
}

void EditImage::input(sf::Event &ev) {
    if(ev.type == sf::Event::MouseWheelScrolled) {
        view.zoom(1.0f - (ev.mouseWheelScroll.delta) * 0.1);
    }
}

void EditImage::render(sf::RenderWindow &target) {
    view.setCenter(sprite.getPosition());

    target.setView(view);
    target.draw(sprite);
}

void EditImage::update() {
    if(path != EditorGlobals::image_path) {
        image.loadFromFile(EditorGlobals::image_path);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }

    sprite.setTexture(texture);
    texture.update(image);
    
    sprite.setOrigin(sf::Vector2f(texture.getSize() / 2u));
}

