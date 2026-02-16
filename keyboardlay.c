#include "gio/gio.h"
#include "glib-object.h"
#include "glib.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdbool.h>

void test (){
  static int x = 0;
  x++;
  printf("%d\n",x);
}

static void create(GtkApplication *app){
  int width = 500;
  int height = 500;
  bool unexpandable = false;

  GtkWidget *window ;
  GtkWidget *box ;
  GtkWidget *button ;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "new window");
  gtk_window_set_resizable(GTK_WINDOW(window), unexpandable);
  gtk_window_set_default_size(GTK_WINDOW(window), width, height);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  gtk_window_set_child(GTK_WINDOW(window), box); //create a box child process on top of window
  
  button = gtk_button_new_with_label("hello button");

  g_signal_connect(button, "clicked", G_CALLBACK(test), NULL);

  gtk_box_append(GTK_BOX(box), button);

  gtk_window_present(GTK_WINDOW(window)); 
}

int main(int argc, char *argv[]){

  GtkApplication *app = gtk_application_new("EXAMPLE.org", G_APPLICATION_DEFAULT_FLAGS);
  int status;
  g_signal_connect(app, "activate", G_CALLBACK(create),NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status ;
}
