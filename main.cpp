#define SDL_MAIN_HANDLED

#include "cobra.cpp"

const int WIDTH = 1280;
const int HEIGHT = 720;

// here is that MainScene
class MainScene : public Scene {
public:

  MainScene() {
    // here i call the set_scene
    Cobra::set_scene(this);
  };

  void main() {
    std::cout << "test" << '\n';
  };
};

int main(int argc, char const *argv[]) {
  Cobra::init(Color(0), Vector2(WIDTH, HEIGHT));

  MainScene ms;

  while (ms.running) {
    Cobra::handle_all();
  };

  return 0;
};
