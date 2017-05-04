/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

var edad;
var sexo;
var sumaEdades = 0;
var cantVarM20 = 0;
var minEdad;

for (var i=1;i<101;i++)
    {
        edad = parseInt( prompt("Ingrese la edad de la "+ i +"º persona") );
        while ( isNaN(edad) || edad < 0 || edad > 100 )
            { edad = parseInt( prompt("El dato ingresado es inválido!! Reingrese la edad de la "+ i +"º persona") ); }
        
        sumaEdades = sumaEdades + edad;

        if ( edad < minEdad || i==1 )
            { minEdad = edad; } 

        sexo = prompt("Ingrese el sexo de la "+ i +"º persona").toLowerCase();
        while ( sexo != "f" && sexo != "m" )
            { sexo = prompt("El dato ingresado es inválido!! Reingrese el sexo de la "+ i +"º persona").toLowerCase(); }

        if ( edad >= 20  && sexo=="m" )
            { cantVarM20 = cantVarM20 + 1; } 
    }


alert( "El promedio de edad es: " + (sumaEdades/100).toFixed(2) );
alert( "La edad mas baja es: " + minEdad );
alert( "La cantidad de varones cuya edad es mayor o igual a 20 es: " + cantVarM20 );

}




function Id()
{


}

