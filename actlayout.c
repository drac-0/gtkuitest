#include <gtk/gtk.h>
#include "gio/gio.h"
#include "glib-object.h"
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>

#define keylen 20

void dummyprint(){
  printf("HELLo\n");
}

static void activation(GtkApplication *app, gpointer user_data){
  char *keyr1[keylen] = {
    "`",
    "1","2","3","4","5","6","7","8","9","0",
    "-","+","backspace"
  };

  char *keyr2[keylen] = {
    "tab", "q", "w", "e", "r", "t",
    "y", "u", "i", "o", "p", "[", "]"
  };

  char *keyr3[keylen] = {
    "caps", "a", "s", "d","f","g","h",
    "j","k", "l", ";", "'","enter"
  };

  char *keyr4[keylen] = {
    "shift", "z", "x","c","v",
    "b","n","m",",",".","/","shift"
  };

  bool unexpandable = false;
  GtkWidget *window ;
  GtkWidget *button;
  GtkWidget *grid;
  GtkWidget *box;

  int width = 500;
  int height = 500;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "main frame");
  gtk_window_set_default_size(GTK_WINDOW(window), width, height);
  gtk_window_set_resizable(GTK_WINDOW(window), unexpandable);

  //container or frame that contains all the GtkWidget
  grid = gtk_grid_new();

  gtk_window_set_child(GTK_WINDOW(window), grid);

  for (int i = 0; i < keylen ; i++){
    if (keyr1[i] == NULL) break;
    button = gtk_button_new_with_label(keyr1[i]);
    g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, i*2, 0, 2, 2);
  }

  for (int x = 0;  x < keylen; x++){
    if (keyr2[x] == NULL) break;
    button = gtk_button_new_with_label(keyr2[x]);
    g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);
    gtk_grid_attach((GTK_GRID(grid)), button, x*2, 2, 2, 2);
  }

  for (int a = 0; a < keylen; a++){
    if (keyr3[a] == NULL) break;
    button = gtk_button_new_with_label(keyr3[a]);
    g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);
    gtk_grid_attach((GTK_GRID(grid)), button, a*2, 4, 2, 2);
  }

  for (int a = 0; a < keylen; a++){
    if (keyr3[a] == NULL) break;
    button = gtk_button_new_with_label(keyr3[a]);
    g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);
    gtk_grid_attach((GTK_GRID(grid)), button, a*2, 4, 2, 2);
  }

  for (int a = 0; a < keylen; a++){
    if (keyr4[a] == NULL) break;
    button = gtk_button_new_with_label(keyr4[a]);
    g_signal_connect(button, "clicked", G_CALLBACK(dummyprint), NULL);
    gtk_grid_attach((GTK_GRID(grid)), button, a*2, 6, 2, 2);
  }

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


