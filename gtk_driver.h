#ifndef _GTK_DRIVER_H
#define _GTK_DRIVER_H

#define LEFT_ALIGN 1
#define CENTER_ALIGN 0
#define RIGHT_ALIGN 2

void draw_rectangle(uint8_t stroke_wdth, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity);
void draw_circle(uint8_t stroke_wdth, uint8_t x, uint8_t y, uint8_t radius, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity);
void draw_string(char text[], uint8_t size, uint8_t align, uint8_t x, uint8_t y, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity);
void draw_with_gtk(cairo_t *cr);

#endif /* _GTK_DRIVER_H */