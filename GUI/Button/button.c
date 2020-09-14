#include<gtk/gtk.h>
void hello(GtkWidget* widget, gpointer data)
{
	g_print("Hello world");
}	
void destroy(GtkWidget* widget, gpointer data)
{
	gtk_main_quit();
}
int main(int argc ,char *argv[])
{
        GtkWidget *window;
        GtkWidget *button;
        gtk_init(&argc,&argv);
        //setting window at top level
        window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);
        //taking container for setting width and button etc
        gtk_container_set_border_width(GTK_CONTAINER(window),300);
        button=gtk_button_new_with_label("click me");
	//button functioon
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(hello),NULL);
        gtk_container_add(GTK_CONTAINER(window),button);
        gtk_widget_show(button);

         //showing window
        gtk_widget_show(window);
        //monitoring pointer Eg:clicks or direction or posistion
        gtk_main();
        return 0;
}



