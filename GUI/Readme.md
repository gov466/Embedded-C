## GUI programming in C Language

The popular C programming language is used for a huge range of applications,
from the tiny microcontrollers used in toasters and watches up to complete
operating systems. GTK (formerly GTK+, GNOME ToolKit) is a free and open-source cross-platform widget toolkit for creating graphical user interfaces (GUIs). It is licensed under the terms of the GNU Lesser General Public License, allowing both free and proprietary software to use it.

There is no native GUI in C. GTK is a popular GUI that works with C .

## What is GTK?
GTK (GIMP Toolkit) is a library for creating Graphical User Interfaces. The library is available underthe GPL license. Using this library, you can create open-source, free or commercial programs.
The library has the name GIMP toolkit (GTK) because it was originally created for developing GIMP(General Image Manipulation Program). 
The authors of GTK are:
-  Peter Mattis
-  Spencer Kimball
-  Josh MacDonald

GTK is object-oriented application user interface. Although written in C, it uses idea of classes and callback functions.

### Compiling
In order to compile GTK programs, you need to tell gcc what GTK libraries are and where they are. The gtk-config command is "knows" this.
``` gtk-config --cflags --libs ```
To compile a GTK program named hello.c, following command can be used: gcc -o hello hello.c ‘gtk-config --cflags --libs‘.
The input used after -o parameter is the name of compiled program. 

## First Program 
It is assumed that GTK is installed on your system. The lastest versions of GTk can found at ftp.gtk.org.Let’s write our first program. 
This program creates a 200x200 pixel wide, empty window.

```
#include <gtk/gtk.h>
int main( int   argc,          char *argv[] )
{ 
  GtkWidget *window;   
  gtk_init (&argc, &argv);    
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);  
  gtk_widget_show  (window);    
  gtk_main ();
  return(0);
  
} 
```


GtkWidget is a variable type to define various components like window, button, label... 
In this example,a window is defined like the following:

GtkWidget *window;

void gtk_init(int *argc,char argv) 

initiates the toolkit and gets the parameters entered in commandline. This function must be used after definening components.

GtkWidget *gtk_window_new(GtkWindowType windowtype) creates a new window.

Window type can be:
- GTK_WINDOW_TOPLEVEL
- GTK_WINDOW_DIALOG
- GTK_WINDOW_POPUP

void gtk_widget_show(GtkWidget *widget) is used to make the component appear in a window. After defining a component and changing attributes, this function must be used.void gtk_main(void) prepares windows and all components to appear in the screen. This function must be used at the end of GTK programs.

Let’s use some properties of window such as titles, size, position...

void gtk_window_set_title(GtkWindow *window,const gchar *title) is used to set or change the title of window. 
First parameter of this function is in GtkWindow type. But window variable is in GtkWidgettype. While compiling, we will be warned about it. Atlhough compiled program works, it is better to correct it. GTK_WINDOW(GtkWidget *widget) is used for that.
Second parameter title is in gchar type.gchar is defined in glib library and the same as char type.

void gtk_window_set_default_size(GtkWindow *window, gint width, gint height) sets the size ofwindow. Like gchar, gint is defined in glib and the same as int.

The function

void gtk_window_set_position(GtkWindow *window, GtkWindowPosition position)
sets the position of window.position can be:
- GTK_WIN_POS_NONE
- GTK_WIN_POS_CENTER
- GTK_WIN_POS_MOUSE
- GTK_WIN_POS_CENTER_ALWAYS

Here is an example:
```
#include <gtk/gtk.h>
int main( int   argc,          char *argv[] )
{
  GtkWidget *window; 
  gtk_init (&argc, &argv);  
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);  
  gtk_window_set_title(GTK_WINDOW(window),"Ýlk Program");  
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);  
  gtk_window_set_default_size(GTK_WINDOW(window),300,300);    
  gtk_widget_show  (window);    
  gtk_main ();    
  return(0);
 }
 ```
