#pragma once
#include "EditorGlobals.hpp"
#include "GUI/GUIManager.hpp"
#include "EditImage.hpp"
#include "Tool/ToolManager.hpp"

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
        ToolManager toolManager;

        GUIManager guiManager;
        EditImage editImage;
};