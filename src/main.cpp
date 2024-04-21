#include <iostream>
#include "Editor.hpp"

int main() {
    auto path = std::filesystem::current_path(); //Get working paths
    path = path.parent_path();
    std::cout << "Current working path" << path << std::endl;
    std::filesystem::current_path(path); //Set working path


    Editor editor;
    editor.load();
    
    while(editor.running()) {
        editor.input();
        editor.update();

        editor.render();
    }
}