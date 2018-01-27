#include <gtk/gtk.h>
#include <cstring>


static void toggled_func(GtkWidget* widget, gpointer data)
{
    if (strcmp((char*) data, "1") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("The %s button is set to active\n", (char*)data);
        else 
            g_print("The %s button is set to deactive\n", (char*)data);

    if (strcmp((char*) data, "2") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("The %s button is set to active\n", (char*)data);
        else 
            g_print("The %s button is set to deactive\n", (char*)data);

    if (strcmp((char*) data, "3") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("The %s button is set to active\n", (char*)data);
        else 
            g_print("The %s button is set to deactive\n", (char*)data);

    if (strcmp((char*) data, "4") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("The %s button is set to active\n", (char*)data);
        else 
            g_print("The %s button is set to deactive\n", (char*)data);
}

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget *window, *radio, *radio2, *vbox;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    gtk_widget_realize(window);
    gtk_window_fullscreen((GtkWindow*)window);
    g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);

    vbox = gtk_vbox_new(0,0);
    radio = gtk_radio_button_new_with_label(NULL,"label 1");
    gtk_box_pack_start(GTK_BOX(vbox),radio,0,0,0);
    g_signal_connect(radio,"toggled",G_CALLBACK(toggled_func),(gpointer)"1");

    
    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "label 2");
    gtk_box_pack_start(GTK_BOX(vbox),radio2,0,0,0);
    g_signal_connect(radio2,"toggled",G_CALLBACK(toggled_func),(gpointer)"2");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "label 3");
    gtk_box_pack_start(GTK_BOX(vbox),radio2,0,0,0);
    g_signal_connect(radio2,"toggled",G_CALLBACK(toggled_func),(gpointer)"3");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "label 4");
    gtk_box_pack_start(GTK_BOX(vbox),radio2,0,0,0);
    g_signal_connect(radio2,"toggled",G_CALLBACK(toggled_func),(gpointer)"4");
    gtk_container_add(GTK_CONTAINER(window),vbox);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}