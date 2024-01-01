#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

///Definiciones - Interfaz

///Struct
///AXIOMAS
///1- 'nombre': menos de 20 caracteres, sin tildes ni caracteres especiales
///2- 'edad': entero mayor a 0
///3- 'peso': real mayor a 0
///4- 'identificacion': entero mayor a 0
struct MascotaE;
///PRE: debe existir'struct MascotaE'
///POST: permite el manejo de 'struct MascotaE' como un puntero
typedef struct MascotaE* Mascota;

///Opción
///PRE: la opción ingresada debe ser un entero entre 0 y 7
///POST: almacena la opción ingresada para usar el menú
int pedirOpcion ();

///Constructor
///PRE: debe existir el puntero 'Mascota'
///POST: reserva memoria para una 'Mascota' y la carga con datos "filtro"
Mascota crearMascotaSinDatos ();
///PRE: debe existir el arreglo 'Mascota mascotas' y 'cantidadMascotas' ser mayor a 0
///POST: mismas funcionalidades que 'crearMascotaSinDatos'. Las realiza 'cantidadMascotas' veces
void crearMascotasSinDatos (Mascota mascotas []);

///Cargar
///PRE: debe existir el puntero 'Mascota'
///POST: reserva memoria para una 'Mascota' y la carga con los datos ingresados por teclado
Mascota cargarMascotaTeclado ();

///Mostrar
///PRE: debe existir el puntero 'Mascota' y estar cargado
///POST: muestra los datos de 'Mascota mascota'
void mostrarMascota (Mascota mascota);
///PRE: debe existir el arreglo 'Mascota mascotas', estar cargado en todas sus posiciones y 'cantidadMascotas' ser mayor a 0
///POST: mismas funcionalidades que 'mostrarMascota'. Las realiza 'cantidadMascotas' veces
void mostrarMascotas (Mascota mascotas []);

///Buscar
///PRE: debe existir el arreglo 'Mascota mascotas', estar cargado en todas sus posiciones, 'cantidadMascotas'
///ser mayor a 0 y 'busco' un entero
///POST: busca 'busco' en 'Mascota mascotas' y devuelve un entero (-1 si no lo encuentra)
int pedirIdentificacionMascotaBuscada ();
int buscar (Mascota mascotas [], int busco);
void mostrarMascotaSiCorresponde (Mascota mascota, int posicion);

///Agregar
///PRE: debe existir 'cargarMascotaTeclado', 'buscar', el arreglo 'Mascota mascotas' y 'cantidadMascotas' ser mayor a 0
///POST: solo si hay una posición libre en 'Mascota mascotas' agrega la mascota
void agregarMascota (Mascota mascotas [], char nombre [20], int edad, float peso, int identificacion);

///Borrar
///PRE: debe existir el arreglo 'Mascota mascotas' e 'identificacion' ser mayor a 0
///POST: si existe una mascota con #'identificación' en el registro, la "borra" guardando en sus atributos "datos filtro", sino no
void borrarMascota (Mascota mascotas [], int identificacion);

///Modificar
///PRE: debe existir el arreglo 'Mascota mascotas' e 'identificacionMascotaAModificar' ser mayor a 0
///POST: si existe una mascota con #'identificaciónMascotaABorrar' en el registro, permite modificar sus datos, sino no
void modificarMascota (Mascota mascotas [], int identificacionMascotaAModificar);

///Ordenar
///PRE: debe existir el arreglo 'Mascota mascotas'
///POST: ordena las mascotas por edad de manera descendente
void ordenarPorEdad (Mascota mascotas []);

///Limpiar
///PRE: ninguna
///POST: si no existe el archivo, lo crea. Si existe, limpia su contenido. El archivo se llama "mascota.txt"
void limpiarArchivo ();

///Guardar
///PRE: tiene que existir 'Mascota mascota'
///POST: guarda los atributos de 'Mascota mascota' separados por un '+' en una línea del archivo
void guardarMascota (Mascota mascota);
///PRE: debe existir el arreglo 'Mascota mascotas'
///POST: llama a 'guardarMascota' 'CANTIDAD_MASCOTAS' veces
void guardarMascotas (Mascota mascotas []);

///Leer
///PRE: debe existir el arreglo 'Mascota mascotas'
///POST: lee todas las líneas del archivo y llama a 'Mascota convertirTextoAMascota' y guarda la mascota en cada posición de 'Mascota mascotas'
void leerMascotas (Mascota mascotas []);
///PRE: debe existir un arreglo donde guardar el texto de cada línea ('datos') y 'tamanio' ser mayor a 0
///POST: consigue separar lo que corresponda a cada atributo de la mascota de todo lo que hay en 'datos', guarda cada "pedacito"
///en el atributo que corresponda de una mascota y retorna la mascota cargada
Mascota convertirTextoAMascota (char datos [], int tamanio);

///Destruir
///PRE: debe existir 'Mascota mascota'
///POST: libera la memoria reservada para 'Mascota mascota'
void destruirMascota (Mascota mascota);
///PRE: debe existir el arreglo 'Mascota mascotas'
///POST: llama a 'destruirMascota' 'CANTIDAD_MASCOTAS' veces
void destruirMascotas (Mascota mascotas []);

#endif // MASCOTA_H_INCLUDED
