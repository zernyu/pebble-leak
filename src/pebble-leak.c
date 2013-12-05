#include <pebble.h>

static Window *window;
static Window *window_too;

static void window_load(Window *window) {
}

static void window_unload(Window *window) {
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(window, true);

  window_too = window_create();
  window_set_window_handlers(window_too, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(window_too, true);
}

static void deinit(void) {
  window_destroy(window);
  window_destroy(window_too);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
