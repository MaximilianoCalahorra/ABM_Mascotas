#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"
#define CANTIDAD_MASCOTAS 100

int main()
{
    Mascota arregloMascotas [CANTIDAD_MASCOTAS];
    crearMascotasSinDatos (arregloMascotas);
    int opcionElegida = pedirOpcion ();
    while (opcionElegida != 0)
    {
        switch (opcionElegida)
        {
            break;
            case 1:
            {
                leerMascotas (arregloMascotas);
                mostrarMascotas (arregloMascotas);
            }
            break;
            case 2:
            {
                leerMascotas (arregloMascotas);
                int idMascotaBuscada = pedirIdentificacionMascotaBuscada ();
                int pos = buscar (arregloMascotas, idMascotaBuscada);
                mostrarMascotaSiCorresponde (arregloMascotas [pos], pos);
            }
            break;
            case 3:
            {
                Mascota m = cargarMascotaTeclado ();
                guardarMascota (m);
                mostrarMascota (m);
            }
            break;
            case 4:
            {
                agregarMascota (arregloMascotas, "Cande", 3, 6.8, 9381);
                int posMascotaAgregada = buscar (arregloMascotas, 9381);
                guardarMascota (arregloMascotas [posMascotaAgregada]);
                printf ("\nMascota agregada:\n");
                mostrarMascota (arregloMascotas [posMascotaAgregada]);
            }
            break;
            case 5:
            {
                leerMascotas (arregloMascotas);
                int idMascotaABorrar = pedirIdentificacionMascotaBuscada ();
                borrarMascota (arregloMascotas, idMascotaABorrar);
                limpiarArchivo ();
                guardarMascotas (arregloMascotas);
                mostrarMascotas (arregloMascotas);
            }
            break;
            case 6:
            {
                leerMascotas (arregloMascotas);
                int idMascotaAModificar = pedirIdentificacionMascotaBuscada ();
                modificarMascota (arregloMascotas, idMascotaAModificar);
                limpiarArchivo ();
                guardarMascotas (arregloMascotas);
                mostrarMascotas (arregloMascotas);
            }
            break;
            case 7:
            {
                leerMascotas (arregloMascotas);
                ordenarPorEdad (arregloMascotas);
                limpiarArchivo ();
                guardarMascotas (arregloMascotas);
                mostrarMascotas (arregloMascotas);
            }
            break;
        }
        opcionElegida = pedirOpcion ();
    }
    printf ("\nGracias por usar el programa!\n");
    destruirMascotas (arregloMascotas);
    return 0;
}
