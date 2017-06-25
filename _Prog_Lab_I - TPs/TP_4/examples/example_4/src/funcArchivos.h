
/**
 * \brief obtiene la cantidad de elementos guardados en el archivo
 * \param recibe el puntero al archivo como parametro
 * \return retorna la cantidad de elementos guardados en el archivo o -1 en caso de error
 */
int contarElementosEnArchivo(FILE* pArchivo);


/**
 *  Cierra un archivo ya abierto
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @return retorna 0 si se pudo cerrar correctamente o -1 si no se pudo
 */
int cerrarArchivo(FILE* pArchivo);


/**
 *  Abre un archivo binario
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @param paramArch Se le pasa la ubicacion, nombre y extension del archivo
 *  @return retorna 0 si se pudo abrir correctamente o -1 si no se pudo
 */
int abrirArchBinModoAppend(FILE* pFile, char paramArch[]);


/**
 *  Abre un archivo binario en modo lectura
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @param paramArch Se le pasa la ubicacion, nombre y extension del archivo
 *  @return retorna 0 si se pudo abrir correctamente o -1 si no se pudo
 */
int abrirArchBinModoLectura(FILE* pFile, char paramArch[]);


/**
 *  Abre un archivo binario en modo lectura escritura
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @param paramArch Se le pasa la ubicacion, nombre y extension del archivo
 *  @return retorna 0 si se pudo abrir correctamente o -1 si no se pudo
 */
int abrirArchBinModoEscritura(FILE* pFile, char paramArch[]);



void actualizarArchivoBinario(void* elemento,char* nombreArchivo,int size);

//void sobreEscribirArchivo(ArrayList* lista,int size,char* nombre);
