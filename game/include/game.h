public:
    Game(GLFWwindow* window);
    void init();
    void update(float deltaTime);
    GLFWwindow* getWindow() const { return window; } 