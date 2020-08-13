#include <glm/gtc/matrix_transform.hpp>
#include "GL0cCamera.h"

const float GL0cCamera::NORMALIZED_SPEED = .005f;
const float GL0cCamera::BASE_FOV = 45.0f;
const float GL0cCamera::NEAR = .1f;
const float GL0cCamera::FAR = 100.0f;

GL0cCamera::GL0cCamera() {
    setup();
}

GL0cCamera::~GL0cCamera() { }

void GL0cCamera::rotate(const float& radians, const glm::vec3& axis) {
    // TODO: implement this, together with a Mouse class, mouse should contain a callback to be set from here
}

void GL0cCamera::move(float x, float z) {
    if (z == 0 && x == 0) return;
    mLocation += NORMALIZED_SPEED * mFront * z;
    mLocation += NORMALIZED_SPEED * right() * x;
}

void GL0cCamera::update(GLFWwindow* window) {
    GL0cEntity::update(window);
    mControl.update(window);
}

void GL0cCamera::updatePerspective(float width, float height) {
    mProjection = glm::perspective(BASE_FOV, width / height, NEAR, FAR);
}

glm::mat4 GL0cCamera::view() const {
    return glm::lookAt(mLocation, mLocation + mFront, mUp);
}

glm::mat4 GL0cCamera::projection() const {
    return mProjection;
}

glm::vec3 GL0cCamera::right() const {
    return glm::normalize(glm::cross(mFront, mUp));
}

void GL0cCamera::setup() {    
    mControl
    .poll(GLFW_KEY_D, GLFW_KEY_A, [=](float mag) {
        move(mag, .0f);
    })
    .poll(GLFW_KEY_W, GLFW_KEY_S, [=](float mag) {
        move(.0f, mag);
    });
}