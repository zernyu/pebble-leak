#include <pebble.h>

static Window *window;
static Window *window_too;

static void init(void) {
  window = window_create();
  window_stack_push(window, true);

  window_too = window_create();
  window_stack_push(window_too, true);
}

static void deinit(void) {
  window_stack_pop_all(false);
  window_destroy(window);
  window_destroy(window_too);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
