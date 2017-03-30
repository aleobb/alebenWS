function Mostrar()
{

    var cantDiv = 2
    var divisor;

    var num = parseInt(prompt("Ingrese un numero"));
    while( isNaN(num) || num < 1 )
        {  num=parseInt(prompt("El dato ingresado es incorrecto!!. Reingrese un numero mayor a cero."));  }

    for ( var i=2 ; i<num ; i++ )
        {   divisor = num % i;
            if (divisor == 0)
                { cantDiv++; }
        }
    
    if ( cantDiv==2 )
        {  document.write("El numero es un número primo");  }
    else
        {  document.write("El numero NO es un número primo");  }

}//FIN DE LA FUNCIÓN