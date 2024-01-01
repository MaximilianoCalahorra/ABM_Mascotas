#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"
#define CANTIDAD_MASCOTAS 100

///Implementaciones

///Struct
struct MascotaE
{
    char nombre [20];
    int edad;
    float peso;
    int identificacion;
};

///Opción
int pedirOpcion ()
{
    int op;
    do
    {
        printf ("\n----------Bienvenido al registro de mascotas----------\n");
        printf ("Elija una de las siguientes opciones:\n");
        printf ("#1: leer mascotas del registro y visualizarlas por pantalla\n");
        printf ("#2: buscar una mascota en el registro y ver sus datos\n");
        printf ("#3: cargar una mascota y guardarla en el registro\n");
        printf ("#4: agregar una mascota al registro (no te pide los datos)\n");
        printf ("#5: borrar alguna mascota del registro\n");
        printf ("#6: modificar alguna mascota del registro\n");
        printf ("#7: ordenar mascotas del registro por edad de manera descendente, mostrar el resultado por pantalla y guardarlo en el registro\n");
        printf ("#0: cerrar programa\n");
        printf ("\nIngrese una de las opciones: #");
        scanf ("%d", &op);
    }
    while (op < 0 || op > 7);

    return op;
}

///Constructor

Mascota crearMascotaSinDatos ()
{
    Mascota m = malloc (sizeof (struct MascotaE));

    strcpy (m->nombre, " ");
    m->edad = -1;
    m->peso = -1;
    m->identificacion = -1;

    return m;
}

void crearMascotasSinDatos (Mascota arrayMascotas [])
{
    for (int i = 0; i < CANTIDAD_MASCOTAS; i++)
    {
        arrayMascotas [i] = crearMascotaSinDatos ();
    }
}

///Cargar
Mascota cargarMascotaTeclado ()
{
    Mascota m = malloc (sizeof (struct MascotaE));

    printf ("\nIngrese el nombre: ");
    fflush (stdin);
    gets (m->nombre);
    printf ("Ingrese la edad: ");
    scanf ("%d", &m->edad);
    printf ("Ingrese el peso: ");
    scanf ("%f", &m->peso);
    printf ("Ingrese el numero de identificacion: ");
    scanf ("%d", &m->identificacion);

    return m;
}

///Mostrar
void mostrarMascota (Mascota m)
{
    printf ("\nNombre: %s\n", m->nombre);
    printf ("Edad: %d\n", m->edad);
    printf ("Peso: %.2f\n", m->peso);
    printf ("Identificacion: %d\n", m->identificacion);
}

void mostrarMascotas (Mascota arrayMascotas [])
{
    for (int i = 0; i < CANTIDAD_MASCOTAS; i++)
    {
        if (arrayMascotas [i]->edad > 0)
        {
            printf ("\nDatos de la mascota:\n");
            mostrarMascota (arrayMascotas [i]);
        }
    }
}

///Buscar
int pedirIdentificacionMascotaBuscada ()
{
    int id;
    printf ("\nIngrese el numero de identificacion de la mascota: #");
    scanf ("%d", &id);
    return id;
}

int buscar (Mascota arrayMascotas [], int b)
{
    for (int i = 0; i < CANTIDAD_MASCOTAS; i++)
    {
        if (arrayMascotas [i]->identificacion == b)
        {
            return i;
        }
    }
    return -1; ///No hay más lugar
}

void mostrarMascotaSiCorresponde (Mascota m, int pos)
{
    if (pos != -1)
    {
        mostrarMascota (m);
    }
    else
    {
        printf ("\nNo existe la mascota en el registro\n");
    }
}

///Agregar
void agregarMascota (Mascota arrayMascotas [], char arrayNombre [20], int e, float p, int id)
{
    int posVacia = buscar (arrayMascotas, -1);
    if (posVacia != -1)
    {
        strcpy (arrayMascotas [posVacia]->nombre, arrayNombre);
        arrayMascotas [posVacia]->edad = e;
        arrayMascotas [posVacia]->peso = p;
        arrayMascotas [posVacia]->identificacion = id;
    }
    else
    {
        printf ("\nNo hay mas lugar\n");
    }
}

///Borrar
void borrarMascota (Mascota arrayMascotas [], int id)
{
    int posABorrar = buscar (arrayMascotas, id);
    if (posABorrar != -1)
    {
        strcpy (arrayMascotas [posABorrar]->nombre, " ");
        arrayMascotas [posABorrar]->edad = -1;
        arrayMascotas [posABorrar]->peso = -1;
        arrayMascotas [posABorrar]->identificacion = -1;
    }
    else
    {
        printf ("\nNo existe una mascota con identificacion %d\n", id);
    }
}

///Modificar - Set
void modificarMascota (Mascota arrayMascotas [], int idMascotaAModificar)
{
    int posAModificar = buscar (arrayMascotas, idMascotaAModificar);
    if (posAModificar != -1)
    {
        printf ("\nNuevos datos de la mascota:\n");
        arrayMascotas [posAModificar] = cargarMascotaTeclado ();
    }
    else
    {
        printf ("\nNo existe ninguna mascota con identificacion %d\n", idMascotaAModificar);
    }
}

void ordenarPorEdad (Mascota arrayMascotas [])
{
    Mascota aux;
    for (int i = 0; i < CANTIDAD_MASCOTAS - 1; i++)
    {
        for (int j = i + 1; j < CANTIDAD_MASCOTAS; j++)
        {
            if (arrayMascotas [j]->edad > arrayMascotas [i]->edad)
            {
                aux = arrayMascotas [j];
                arrayMascotas [j] = arrayMascotas [i];
                arrayMascotas [i] = aux;
            }
        }
    }
}

///Limpiar
void limpiarArchivo ()
{
    FILE* archivo;
    archivo = fopen ("mascota.txt", "w");
    fclose (archivo);
}

///Guardar
void guardarMascota (Mascota m)
{
    FILE* archivo;
    archivo = fopen ("mascota.txt", "a");
    if (m->identificacion > 0)
    {
        fprintf (archivo, "%s+%d+%.2f+%d\n", m->nombre, m->edad, m->peso, m->identificacion);
    }
    fclose (archivo);
}

void guardarMascotas (Mascota arrayMascotas [])
{
    for (int i = 0; i < CANTIDAD_MASCOTAS; i++)
    {
        guardarMascota (arrayMascotas [i]);
    }
}

///Leer
void leerMascotas (Mascota arrayMascotas [])
{
    FILE* archivo;
    archivo = fopen ("mascota.txt", "r");

    if (archivo != NULL)
    {
        int i = 0;
        while (!feof (archivo))
        {
            destruirMascota (arrayMascotas [i]);
            char dat [30] = " ";
            fgets (dat, 30, archivo);
            arrayMascotas [i] = convertirTextoAMascota (dat, 30);
            i = i + 1;
        }
    }
    else
    {
        printf ("\nNo existe un archivo con ese dominio\n");
    }

    fclose (archivo);
}

Mascota convertirTextoAMascota (char dat [], int t)
{
    int posDelDelimitador1;
    for (int i = 0; i < t; i++)
    {
        if (dat [i] == '+')
        {
            posDelDelimitador1 = i;
            i = t;
        }
    }
    int posDelDelimitador2;
    for (int i = posDelDelimitador1 + 1; i < t; i++)
    {
        if (dat [i] == '+')
        {
            posDelDelimitador2 = i;
            i = t;
        }
    }
    int posDelDelimitador3;
    for (int i = posDelDelimitador2 + 1; i < t; i++)
    {
        if (dat [i] == '+')
        {
            posDelDelimitador3 = i;
            i = t;
        }
    }
    char auxNombre [30] = " ";
    for (int i = 0; i < posDelDelimitador1; i++)
    {
        auxNombre [i] = dat [i];
    }
    char auxEdad [30] = " ";
    for (int i = posDelDelimitador1 + 1; i < posDelDelimitador2; i++)
    {
        auxEdad [i - posDelDelimitador1 -1] = dat [i];
    }
    char auxPeso [30] = " ";
    for (int i = posDelDelimitador2 + 1; i < posDelDelimitador3; i++)
    {
        auxPeso [i - posDelDelimitador2 - 1] = dat [i];
    }
    char auxIdentificacion [30] = " ";
    for (int i = posDelDelimitador3 + 1; i < t; i++)
    {
        auxIdentificacion [i - posDelDelimitador3 - 1] = dat [i];
    }

    Mascota m = malloc (sizeof (struct MascotaE));

    strcpy (m->nombre, auxNombre);
    m->edad = atoi (auxEdad);
    m->peso = atof (auxPeso);
    m->identificacion = atoi (auxIdentificacion);

    return m;
}

///Destruir
void destruirMascota (Mascota m)
{
    free (m);
}

void destruirMascotas (Mascota arrayMascotas [])
{
    for (int i = 0; i < CANTIDAD_MASCOTAS; i++)
    {
        destruirMascota (arrayMascotas [i]);
    }
}
