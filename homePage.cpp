#include <gtk/gtk.h>
#include <assert.h>
#include <cstring>


// static void closeWindow(GtkWidget* window)
// {
//   // GtkWidget* window1;
//   // window1 = window;
//   gtk_widget_destroy(GTK_WIDGET(window));
// }


static void dispensePage(int argc, char *argv[])
{
  GtkWidget *window2;
  GtkWidget *fixed;

  GtkWidget *oneLiter;
  GtkWidget *twoLiters;
  GtkWidget *threeLiters;
  GtkWidget *accountBalance;
  GtkWidget *newTransaction;
  int value = 0;

  gtk_init(&argc, &argv);

  window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_realize(window2);
  gtk_window_fullscreen((GtkWindow*)window2);
  gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window2), fixed);

  oneLiter = gtk_button_new_with_label("Dispense 1 Liter");
  gtk_fixed_put(GTK_FIXED(fixed), oneLiter, 150, 100);
  gtk_widget_set_size_request(oneLiter, 225, 75);

  twoLiters = gtk_button_new_with_label("Dispense 2 Liters");
  gtk_fixed_put(GTK_FIXED(fixed), twoLiters, 150, 205);
  gtk_widget_set_size_request(twoLiters, 225, 75);

  threeLiters = gtk_button_new_with_label("Dispense 3 Liters");
  gtk_fixed_put(GTK_FIXED(fixed), threeLiters, 150, 310);
  gtk_widget_set_size_request(threeLiters, 225, 75);
  
  accountBalance = gtk_button_new_with_label("Check Account Balance");
  gtk_fixed_put(GTK_FIXED(fixed), accountBalance, 150, 415);
  gtk_widget_set_size_request(accountBalance, 225, 75);
  
  newTransaction = gtk_button_new_with_label("Finish Transaction");
  gtk_fixed_put(GTK_FIXED(fixed), newTransaction, 150, 520);
  gtk_widget_set_size_request(newTransaction, 225, 75);
  // g_signal_connect (button, "clicked", G_CALLBACK (hello), &value);
    g_signal_connect (window2,"delete-event", G_CALLBACK (gtk_true),NULL);
  //g_signal_connect(G_OBJECT(newTransaction), "clicked", G_CALLBACK(gtk_object_destroy), window2);
  g_signal_connect (window2, "destroy",G_CALLBACK (gtk_main_quit),NULL);
  g_signal_connect_swapped (newTransaction, "clicked",G_CALLBACK (gtk_widget_destroy),window2);
  
  g_signal_connect(G_OBJECT(window2), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window2);

  gtk_main();
}

int main (int argc, char *argv[])
{
    GtkWidget *window,*button,*fixed;
    GtkWidget *icon_view,*dispenseButton;
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "FE Water Kiosk");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    gtk_widget_realize(window);
    gtk_window_fullscreen((GtkWindow*)window);
    
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window),fixed);
    dispenseButton = gtk_button_new_with_label("Begin New Transaction");
    gtk_fixed_put(GTK_FIXED(fixed),dispenseButton,300,250);
    gtk_widget_set_size_request(dispenseButton,400,200);
    
    g_signal_connect(dispenseButton,"clicked", G_CALLBACK (dispensePage), (gpointer) "dispenseButton");

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
    
}