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

            menu->onMenuItemClick([this, &gui, &theme](const std::vector<tgui::String>& menuItem){
                if (menuItem[0] == "Help" && menuItem[1] == "About")
                    this->showAbout(gui, theme);

                if (menuItem[0] == "File" && menuItem[1] == "Load") {
                    auto fileSelect = tgui::FileDialog::create();
         
                    fileSelect->onFileSelect(selectFile, std::ref(*fileSelect));

                    gui.add(fileSelect);
                }

            });

            gui.add(menu);
        }

        void showAbout(tgui::BackendGui& gui, tgui::Theme& theme) {
            aboutPopup.show(gui, theme);
        }
        
    private:

        static void selectFile(tgui::FileDialog& fileSelect) {
            std::string file = fileSelect.getSelectedPaths().at(0).asString().toStdString();
            std::cout << "PATH: " << file << std::endl;
        }

        tgui::MenuBar::Ptr menu = nullptr;

        AboutPopup aboutPopup;
};