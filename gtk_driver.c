#include <math.h>
#include "gtk_driver.h"
#include "lcd_UI.c"

cairo_t *cr;
cairo_text_extents_t extents;

void draw_with_gtk(cairo_t *cr2)
{
	cr = cr2;
	draw_to_screen();
}

void draw_rectangle(uint8_t stroke_wdth, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity)
{
  cairo_set_line_width(cr, stroke_wdth);
  cairo_set_source_rgb(cr, color_r, color_g, color_b);
  cairo_rectangle(cr, x, y, width, height);
  cairo_stroke_preserve(cr);

  cairo_set_source_rgba(cr, color_r, color_g, color_b, opacity);
  cairo_fill(cr);
}

void draw_circle(uint8_t stroke_wdth, uint8_t x, uint8_t y, uint8_t radius, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity)
{
  cairo_set_line_width(cr, stroke_wdth);  
  cairo_set_source_rgb(cr, color_r, color_g, color_b);
  cairo_arc(cr, x, y, radius, 0, 2 * M_PI);
  cairo_stroke_preserve(cr);

  cairo_set_source_rgba(cr, color_r, color_g, color_b, opacity);
  cairo_fill(cr);  
}

void draw_string(char text[], uint8_t size, uint8_t align, uint8_t x, uint8_t y, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity)
{
  cairo_set_source_rgba(cr, color_r, color_g, color_b, opacity);
  cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size(cr, size);

  switch (align)
  {
    case 0: 
            cairo_text_extents(cr, text, &extents);
            cairo_move_to(cr, x - extents.width/2, y);
            break;

    case 1: 
            cairo_move_to(cr, x, y);
            break;

    case 2:
            cairo_text_extents(cr, text, &extents);
            cairo_move_to(cr, x - extents.width, y);
            break;

  }

  cairo_show_text(cr, text);
}