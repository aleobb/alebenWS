function Mostrar()
{

    var cantDiv = 0; // Podría arrancar en 2 porque sé que el 1 y el numero tomado son divisores pero como los tengo que mostrar necesito arrancar de cero
    var divisor;

    var num = parseInt(prompt("Ingrese un numero"));
    while( isNaN(num) || num < 1 )
        {
            num=parseInt(prompt("El dato ingresado es incorrecto!!. Reingrese un numero"));
        }
        
    console.log ("Divisores:");
    for ( var i=1 ; i<=num ; i++ ) // Podria descartar hacer iteracion por 1 y por el numero tomado ya que sé que esos valores son divisores pero necesito mostrarlos asi que necesito
        {
            divisor = num % i;
            if (divisor == 0)
                {   console.log("Es divisor: " + i);
                    cantDiv++;  }
        }
    
    console.log("cantidad de divisores encontrados: " + cantDiv );


}//FIN DE LA FUNCIÓN