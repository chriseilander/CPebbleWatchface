#include <pebble.h>
// https://developer.repebble.com/tutorials/watchface-tutorial/part1/

static Window *s_main_window; // Every Pebble app needs at least 1 Window.

// This will be called when the Window is loaded
static void main_window_load(Window *window) {}

// This will be called when the Window is unloaded
static void main_window_unload(Window *window) {}

// Initialization (called from main())
static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();
  
  // Set the background color
  window_set_background_color(s_main_window, GColorBlack); // Side note: What would happen if set to a color on the black/white watches? GColorVividCerulean
  
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load, // This function and the next one are above the init() function.
    .unload = main_window_unload
  });
  
  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true); // What does animated=true even mean? We don't have any animated parts (yet) as far as I know.
}

// Cleanup when the app exits
static void deinit() {
  // Note to myself: Every _create() call must be matched with a _destroy() call to free memory.
  // Destroy Window
  window_destroy(s_main_window);
}

// Main is the entry point
int main(void) {
  init();
  app_event_loop(); // Wait for system events
  deinit();
}