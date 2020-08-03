// TODO: clean up includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "system/GL0cSystem.h"

int main() {
    auto system = GL0cSystem();
    system.loop();

    return 0;
}