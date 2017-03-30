/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

var seguir;
var num;
var i = 0;
var cantPares = 0;
var suma = 0;
var max;
var min;


do  {
        i++
        num = parseInt( prompt("Ingrese el "+ i +"º numero" ) );
        while ( isNaN(num) || num <= 0 )
            { num = parseInt( prompt("El dato ingresado es inválido!! Reingrese el " + i + "º numero" ) ); }
        
        if ( (num % 2) == 0 ) 
            { cantPares = cantPares + 1 ; }

        suma = suma + num ;

        if (num < min || i == 1)
            {min = num}
        if (num > max || i == 1)
            {max = num}


        seguir = confirm ("Desea continuar ingresando numeros?");
    } while (seguir);


document.write( "</br> La cantidad de números pares es: " + cantPares + 
                "</br> El promedio de números ingresados es: " + (suma / i) +
                "</br> La suma de todos los números es: " + suma +
                "</br> El número máximo es: " + max +
                "</br> El número mínimo es: " + min );

}



function Id()
{


}

