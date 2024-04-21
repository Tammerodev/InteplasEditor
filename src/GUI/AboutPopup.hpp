#pragma once
#include <TGUI/TGUI.hpp>

class AboutPopup {
    public:
        void load(tgui::BackendGui& gui, tgui::Theme& theme) {
            aboutWindow = tgui::ChildWindow::create("About Inteplas Editor");
            aboutWindow->hideWithEffect(tgui::ShowEffectType::Scale, tgui::Duration(0));

            gui.add(aboutWindow);
        }

        void show() {
            aboutWindow->showWithEffect(tgui::ShowEffectType::Scale, tgui::Duration(100));

        }
    private:    
        tgui::ChildWindow::Ptr aboutWindow;
};