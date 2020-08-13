#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GL0cEntity.h"
#include "../component/GL0cControl.h"

class GL0cCamera: GL0cEntity {
public:
    GL0cCamera();
    ~GL0cCamera();

    void rotate(const float&, const glm::vec3&);
    void move(float, float);
    void reset(const glm::vec3&);
    void update(GLFWwindow*) override;
    void updatePerspective(float, float);
    glm::mat4 view() const;
    glm::mat4 projection() const;
    glm::vec3 right() const;

    GL0cControl mControl;

private:
    float mYaw = -90.0f;
    float mPitch = .0f;
    glm::vec3 mFront { .0f, .0f, -1.0f };
    glm::vec3 mUp { .0f, 1.0f, .0f };
    glm::vec3 mLocation { .0f, .0f, 3.0f };
    glm::mat4 mProjection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, .1f, 100.0f);
    
    static const float NORMALIZED_SPEED;
    static const float BASE_FOV;
    static const float NEAR;
    static const float FAR;

    void setup();
};