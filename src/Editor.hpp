#pragma once
#include "EditorGlobals.hpp"
#include "GUI/GUIManager.hpp"

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class Editor {
    public:
        void load();
        void update();
        void input();
        void render();

        bool running();

    private:
        sf::RenderWindow window;
        tgui::Gui gui;

        GUIManager guiManager;
};