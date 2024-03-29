#define SDL_MAIN_HANDLED
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <functional>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include "SDL.h"

class Object {

public:
  Vector2 position;
  Vector2 size;
  Vector2 velocity;
  double mass;
  double damping = 1;
  Color color;
  bool centered;
  bool fill;
  SDL_Surface* surface;
  SDL_Texture* texture;
  std::string texture_dir;
  int z_index = 0;
  bool texture_setup = false;

  Object() {};

  Object(Vector2 nposition, Vector2 nsize, std::string texture_dirn, Color ncolor, int z_indexn = 0, bool centeredn = false, bool filln = true) {
    position = nposition;
    size = nsize;
    color = ncolor;
    fill = filln;
    centered = centeredn;
    texture_dir = texture_dirn;
    z_index = z_indexn;
    if (texture_dirn == "") {
      size = nsize;
      texture_setup = true;
    };
  };

  Object(const Object& obj) {
    position = obj.position;
    size = obj.size;
    color = obj.color;
    fill = obj.fill;
    centered = obj.centered;
    texture_dir = obj.texture_dir;
    z_index = obj.z_index;
    mass = obj.mass;
    velocity = obj.velocity;
    damping = obj.damping;
    surface = obj.surface;
    texture = obj.texture;
    texture_setup = obj.texture_setup;
  }

  void setup_texture(SDL_Renderer* renderer) {
    surface = IMG_Load(texture_dir.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    size = Vector2(surface->w, surface->h);
    texture_setup = true;
  };

  void apply_impulse(double x, double y) {
    velocity.x += x;
    velocity.y += y;
  };

  void apply_impulse(Vector2 impulse) {
    velocity += impulse;
  };

  void move(double x, double y) {
    position.x += x;
    position.y += y;
  };

  void update_velocity(double delta) {
    position += velocity * delta;
    velocity *= damping;
  };

};
