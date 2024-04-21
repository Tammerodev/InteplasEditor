#pragma once
#include "AboutPopup.hpp"

class GUIManager {
    public:
        void load(tgui::BackendGui& gui, tgui::Theme& theme) {
            aboutPopup.load(gui, theme);

            menu = tgui::MenuBar::create();
            menu->setRenderer(theme.getRenderer("MenuBar"));
            menu->setHeight(22.f);

            menu->addMenu("File");
                menu->addMenuItem("Load");
                menu->addMenuItem("Save");
                menu->addMenuItem("Exit");

            menu->addMenu("Edit");
                menu->addMenuItem("Copy");
                menu->addMenuItem("Paste");

            menu->addMenu("Help");
                menu->addMenuItem("About");

            menu->onMenuItemClick([this](const std::vector<tgui::String>& menuItem){
                if (menuItem[0] == "Help" && menuItem[1] == "About")
                    this->showAbout();
            });

            gui.add(menu);
        }

        void showAbout() {
            aboutPopup.show();
        }
    private:
        tgui::MenuBar::Ptr menu = nullptr;

        AboutPopup aboutPopup;
};