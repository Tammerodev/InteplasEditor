#include "Editor.hpp"

void Editor::load() {
    tgui::Theme theme("res/themes/nanogui.style");

    window.create(sf::VideoMode(800, 800), "Inteplas Editor");
    gui.setWindow(window);

    guiManager.load(gui, theme);
}

void Editor::update() {
    
}

void Editor::input() {
    sf::Event ev;

    while(window.pollEvent(ev)) {
        gui.handleEvent(ev);
    }
}

void Editor::render() {
    window.clear(sf::Color(29, 27, 33));

    gui.draw();
    window.display();
}

bool Editor::running() {
    return window.isOpen();
}
