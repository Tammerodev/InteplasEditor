#include "Editor.hpp"

void Editor::load() {
    tgui::Theme theme("res/themes/nanogui.style");

    window.create(sf::VideoMode(800, 800), "Inteplas Editor");
    gui.setWindow(window);

    editImage.load(sf::Vector2f(window.getSize()));
    toolManager.load();

    guiManager.load(gui, theme);
}

void Editor::update() {
    editImage.update();

    const sf::Vector2i &pos = sf::Vector2i(editImage.getCursorPosition(window));
    toolManager.update(pos, editImage);
}

void Editor::input() {
    sf::Event ev;

    while(window.pollEvent(ev)) {
        gui.handleEvent(ev);
        editImage.input(ev);
    }
}

void Editor::render() {
    window.clear(sf::Color(29, 27, 33));

    editImage.render(window);

    gui.draw();
    window.display();
}

bool Editor::running() {
    return window.isOpen();
}
