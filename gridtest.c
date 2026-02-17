#include <stdbool.h>
#include "gio/gio.h"
#include "glib-object.h"
#include <gtk/gtk.h>
#include <stdio.h>

void dummyprint(){
  printf("HELLO\n");
}

static void activation(GtkApplication *app, gpointer user_data){
  bool unexpandable = false;
  GtkWidget *window ;
  GtkWidget *button;
  GtkWidget *grid;

  int width = 200;
  int height = 200;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "main frame");
  gtk_window_set_default_size(GTK_WINDOW(window), width, height);
  gtk_window_set_resizable(GTK_WINDOW(window), unexpandable);

  //container or frame that contains all the GtkWidget
  grid = gtk_grid_new();

  gtk_window_set_child(GTK_WINDOW(window), grid);

  button = gtk_button_new_with_label("but 1");
  g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);

  //attach the button to the grid at pos (0,0), (1,1) argument after that is for the width and length
  gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
  
  //second button
  button = gtk_button_new_with_label("but 2");
  g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);

  //attach sec button on pos (1,0) with same size of but 1
  gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

  //quit button
  button = gtk_button_new_with_label("exit");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);

  //attach the quit button on pos +1 vertically
  gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

  gtk_window_present(GTK_WINDOW(window));
}


int main(int argc, char *argv[]){
  GtkApplication *app;
  int status;

  app = gtk_application_new("EXAMPLE.org", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activation), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}


