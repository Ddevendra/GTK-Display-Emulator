void draw_to_screen()
{

	// draw_rectangle(uint8_t stroke_wdth, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity)
	draw_rectangle(0, 0, 0, 240, 240, 0,0,0, 1); // black fill

	// draw_circle(uint8_t stroke_wdth, uint8_t x, uint8_t y, uint8_t radius, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity)
	draw_circle(0, 120, 120, 30, 0,30,200, 0.6);

	// draw_string(String text, uint8_t size, uint8_t align, uint8_t x, uint8_t y, uint8_t color_r, uint8_t color_g, uint8_t color_b, float opacity)
	draw_string("Tap To", 13, LEFT_ALIGN, 120, 60, 255,255,255, 0.5);
	draw_string("Tap To", 13, RIGHT_ALIGN, 120, 80, 255,255,255, 0.5);
	draw_string("START", 15, CENTER_ALIGN, 120, 125, 255,255,255, 0.8);
}