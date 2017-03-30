function Mostrar()
{

    var num = parseInt(prompt("Ingrese un numero"));
    while( isNaN(num) || num < 1 )
        {  num=parseInt(prompt("El dato ingresado es incorrecto!!. Reingrese un numero"));  }

    console.log ("Nros pares encontrados:");
    for ( var i=2 ; i<=num ; i=i+2 )
        {   console.log(i);  }
    
    console.log("Cantidad de nros. encontrados: " + (i-2)/2 );

}//FIN DE LA FUNCIÓN