#include <pebble.h>

Window *window;

TextLayer *hour;
TextLayer *minute;

static void window_load(Window *window) {
  hour = text_layer_create(GRect(0, 0, 72, 72));
  text_layer_set_background_color(hour, GColorClear);
  text_layer_set_text_color(hour, GColorBlack);
  text_layer_set_text_alignment(hour,GTextAlignmentRight);
 
  layer_add_child(window_get_root_layer(window), (Layer*) hour);
  text_layer_set_text(hour, "12");

  GFont bold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROBOTO_COND_BOLD_60));
  text_layer_set_font(hour, bold);

  minute = text_layer_create(GRect(72, 12, 58, 58));
  text_layer_set_background_color(minute, GColorClear);
  text_layer_set_text_color(minute, GColorBlack);
 
  layer_add_child(window_get_root_layer(window), (Layer*) minute);
  text_layer_set_text(minute, "25");

  GFont light = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROBOTO_COND_LIGHT_48));
  text_layer_set_font(minute, light);

}

static void window_unload(Window *window) {
  text_layer_destroy(hour);
  text_layer_destroy(minute);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(window, true);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
