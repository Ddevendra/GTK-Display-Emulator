#include <cairo.h>
#include <gtk/gtk.h>
#include "gtk_driver.c"

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  draw_with_gtk(cr);

  return FALSE;
}


int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *darea;
  
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), darea);

  g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL); 
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  

  gtk_window_set_default_size(GTK_WINDOW(window), 240, 240); 
  gtk_window_set_title(GTK_WINDOW(window), "TFT Display");
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}