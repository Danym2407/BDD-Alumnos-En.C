#include "local.h"
#include <gtk/gtk.h>

GtkWidget *create_menu() ;
void on_menu_ingresar_alumnos_activate(GtkMenuItem *menuitem, gpointer user_data);
void on_menu_ingresar_materias_activate(GtkMenuItem *menuitem, gpointer user_data);
void on_menu_modificar_alumno_activate(GtkMenuItem *menuitem, gpointer user_data);
void on_menu_modificar_materias_activate(GtkMenuItem *menuitem, gpointer user_data);
GtkWidget *create_menu();


int main(gint argc, gchar *argv[]) {

    int x, y, z;
    // Inicializar el ambiente
    gtk_init(&argc, &argv);

    // Crear widgets
    principal *presentacion = malloc(sizeof(principal));

    if (presentacion == NULL) {
        printf("No se encontró memoria");
        return 1;
    }

    presentacion->ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    for (x = 0; x < 5; x++) {
        presentacion->cajaHorizontal[x] = gtk_hbox_new(TRUE, 5);
    }

    for (y = 0; y < 10; y++) {
        presentacion->cajaVertical[y] = gtk_vbox_new(TRUE, 5);
    }

    for (z = 0; z < 10; z++) {
        presentacion->campo[z] = gtk_entry_new();
    }

    presentacion->boton[0] = gtk_button_new_with_label("Enviar");
    presentacion->boton[1] = gtk_button_new_with_label("Borrar");

    presentacion->etiqueta[0] = gtk_label_new("Nombre");
    presentacion->etiqueta[1] = gtk_label_new("Apellido paterno");
    presentacion->etiqueta[2] = gtk_label_new("Apellido materno");
    presentacion->etiqueta[3] = gtk_label_new("Telefono");
    presentacion->etiqueta[4] = gtk_label_new("Numero de cuenta");
    presentacion->etiqueta[5] = gtk_label_new("Sexo");
    presentacion->etiqueta[6] = gtk_label_new("Estatus");
    presentacion->etiqueta[7] = gtk_label_new("Pumpe");
    presentacion->etiqueta[8] = gtk_label_new("Datos de alumno");

    presentacion->imagen = gtk_image_new_from_file("disenio.jpg");

    // Fijar atributos
    gtk_window_set_title(GTK_WINDOW(presentacion->ventana), "Proyecto final");
    gtk_window_set_default_size(GTK_WINDOW(presentacion->ventana), 400, 300);




    // Crear el menú y agregarlo a la ventana
    GtkWidget *menu_bar = create_menu();
    
    gtk_box_pack_start(GTK_BOX(presentacion->cajaVertical[0]), menu_bar, FALSE, FALSE, 0);


    // Llamadas a funciones

    // Definir jerarquia


    // Se agrega la imagen a la caja horizontal principal
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[0]), presentacion->imagen);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[0]), presentacion->cajaVertical[0]);

    // Horizontal 1
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[1]), presentacion->etiqueta[8]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[2]), presentacion->etiqueta[0]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[2]), presentacion->campo[0]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[1]), presentacion->cajaVertical[2]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[3]), presentacion->etiqueta[1]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[3]), presentacion->campo[1]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[1]), presentacion->cajaVertical[3]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[4]), presentacion->etiqueta[2]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[4]), presentacion->campo[2]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[1]), presentacion->cajaVertical[4]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[1]), presentacion->cajaHorizontal[1]);

    // Horizontal 2
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[5]), presentacion->etiqueta[3]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[5]), presentacion->campo[3]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[2]), presentacion->cajaVertical[5]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[6]), presentacion->etiqueta[4]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[6]), presentacion->campo[4]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[2]), presentacion->cajaVertical[6]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[1]), presentacion->cajaHorizontal[2]);

    // Horizontal 3
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[7]), presentacion->etiqueta[5]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[7]), presentacion->campo[5]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[3]), presentacion->cajaVertical[7]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[8]), presentacion->etiqueta[6]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[8]), presentacion->campo[6]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[3]), presentacion->cajaVertical[8]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[9]), presentacion->etiqueta[7]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[9]), presentacion->campo[7]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[3]), presentacion->cajaVertical[9]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[1]), presentacion->cajaHorizontal[3]);

    // Botones
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[4]), presentacion->boton[0]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[4]), presentacion->boton[1]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaVertical[1]), presentacion->cajaHorizontal[4]);

    // Ventana vertical al contenedor horizontal principal
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->cajaHorizontal[0]), presentacion->cajaVertical[1]);

    gtk_container_add(GTK_CONTAINER(presentacion->ventana), presentacion->cajaHorizontal[0]);


    // Mostrar widgets
    gtk_widget_show_all(presentacion->ventana);

    gtk_main();
    return 0;
}
/********************************  fin ************************************/
void on_menu_ingresar_alumnos_activate(GtkMenuItem *menuitem, gpointer user_data) {
    // Lógica para la opción "Ingresar Alumnos"
    printf("Opción Ingresar Alumnos seleccionada\n");
    // Aquí tengo que llamar función para ingresar alumnos
}

void on_menu_ingresar_materias_activate(GtkMenuItem *menuitem, gpointer user_data) {
    // Lógica para la opción "Ingresar Materias"
    printf("Opción Ingresar Materias seleccionada\n");
    // ingresar materias
}

void on_menu_modificar_alumno_activate(GtkMenuItem *menuitem, gpointer user_data) {
    // Lógica para la opción "Modificar Alumno"
    printf("Opción Modificar Alumno seleccionada\n");
    // modificar alumnos
}

void on_menu_modificar_materias_activate(GtkMenuItem *menuitem, gpointer user_data) {
    // Lógica para la opción "Modificar Materias"
    printf("Opción Modificar Materias seleccionada\n");
    // modificar materias
}

GtkWidget *create_menu() {
    GtkWidget *menu_bar;
    GtkWidget *menu;
    GtkWidget *menu_item;
    GtkWidget *barraDeMenu, *menu1, *menu1Item1, *menuDeMenu1,*menu1Menu ;

    // Crea la barra de menú
    menu_bar = gtk_menu_bar_new();

    // Crea el menú
    menu = gtk_menu_new();

    // Crea la opción "Ingresar Alumnos"
    menu_item = gtk_menu_item_new_with_label("Ingresar Alumnos");
    g_signal_connect(menu_item, "activate", G_CALLBACK(on_menu_ingresar_alumnos_activate), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    // Crea la opción "Ingresar Materias"
    menu_item = gtk_menu_item_new_with_label("Ingresar Materias");
    g_signal_connect(menu_item, "activate", G_CALLBACK(on_menu_ingresar_materias_activate), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    // Crea la opción "Modificar Alumno"
    menu_item = gtk_menu_item_new_with_label("Modificar Alumno");
    g_signal_connect(menu_item, "activate", G_CALLBACK(on_menu_modificar_alumno_activate), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    // Crea la opción "Modificar Materias"
    menu_item = gtk_menu_item_new_with_label("Modificar Materias");
    g_signal_connect(menu_item, "activate", G_CALLBACK(on_menu_modificar_materias_activate), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    // Crea el elemento del menú en la barra de menú
    menu_item = gtk_menu_item_new_with_label("Alumnos");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

    return menu_bar;
}
