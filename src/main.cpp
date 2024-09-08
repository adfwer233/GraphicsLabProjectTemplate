#include <iostream>

#include "graphics_lab/project.hpp"

class ProjectTemplate : public IGraphicsLabProject {
    virtual void tick() override {
        std::cout << "tick" << std::endl;
    }
};

extern "C" __declspec(dllexport) IGraphicsLabProject* createProject() {
    return new ProjectTemplate();
}