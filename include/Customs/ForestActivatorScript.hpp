#ifndef __FOREST_ACTIVATOR_SCRIPT__
#define __FOREST_ACTIVATOR_SCRIPT__

#include "Engine/Timer.hpp"
#include "Engine/GameController.hpp"
#include "Engine/InputSystem.hpp"
#include "Engine/GameObject.hpp"
#include "Engine/SceneManager.hpp"

#include "Components/Script.hpp"
#include "Components/Animator.hpp"
#include "Math/Vector.hpp"

#include <string>

/**
    @file ForestActivator.hpp
    @brief Class that defines methods and attributes for activating the forest script.
    @copyright LGPL. MIT License.
*/

class ForestActivatorScript : public Script {

public:
    ForestActivatorScript(GameObject *owner);
    std::string GetComponentName() override {
        return "ForestActivatorScript";
    };
    void FixedComponentUpdate() override;
    void Start() override;
    void Activate(){
        activate = 0;
    }

protected:
    void ComponentUpdate() override;

private:
    // tells whether the forest is activated or not
    int activate = -1;
    // tells whether the forest has been already shown or not
    bool runned = false;
    Timer time;
    void CreateAnimations();
    // user inputs (mouse, keyboard commands)
    InputSystem *input = nullptr;
    GameController *gamecontroller = nullptr;
    Animator *animator = nullptr;
    Vector *position = nullptr;
};

#endif
