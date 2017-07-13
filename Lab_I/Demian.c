void guardarEnArchivo()
{
    char array_nombreArchivo[5][30];
    strcpy(array_nombreArchivo[LVALIDOS],"Usuarios_validos.csv");
    strcpy(array_nombreArchivo[LINVALIDOS],"Usuarios_invalidos.csv");
    strcpy(array_nombreArchivo[LVISA],"Usuarios_Visa.csv");
    strcpy(array_nombreArchivo[LMASTER],"Usuarios_MasterCard.csv");
    strcpy(array_nombreArchivo[LAMERICAN],"Usuarios_AMERICAN_E.csv");
    int i,j;
    Clientes* cliente;
    for(i=1;i<CANTIDADLISTAS;i++){
        pFile=fopen(array_nombreArchivo[i],"w");
        fprintf(pFile,"%s","id,first_name,last_name,email,card\n");
        for(j=0;j<listas[i]->len(listas[i]);j++){
            cliente=(Clientes*)listas[i]->get(listas[i],j);
            fprintf(pFile,"%s,%s,%s,%s,%s\n",cliente->id,cliente->nombre,cliente->apellido,cliente->email,cliente->tarjeta.numero);
        }
        fclose(pFile);
    }
}

int verificacionNumeroTarjeta(char* charNumero)
{
    int retorno=0;
    if(esNumeroChar(charNumero))
    {
        int len=strlen(charNumero);
        int entNumero[len];
        int suma=0;
        int i,j;
        for(i=0,j=len-1;i<len;j--,i++){
            sscanf(charNumero+i,"%1d",entNumero+j);
        }
        for(i=0;i<len;i++){
            if((i%2)!=0)
                entNumero[i]*=2;
            if(entNumero[i]>9)
                entNumero[i]-=9;
            suma+=entNumero[i];

        }
        if(!(suma%10))
            retorno=1;
    }
    return retorno;
}
