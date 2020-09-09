#include<gtk/gtk.h>
int main(int argc ,char *argv[])
{
	GtkWidget *window;
	gtk_init(&argc,&argv);
	//setting window at top level
	window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//taking container for setting width and button etc
	gtk_container_set_border_width(GTK_CONTAINER(window),300);
	//showing window
	gtk_widget_show(window);
	//monitoring pointer Eg:clicks or direction or posistion
	gtk_main();
	return 0;
}
