/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

    var kilos;
    var max;
    var min;
    var dmax;
    var dmin;

    for (var d=1;d<5;d++)
        {
            kilos = Math.round( parseInt( prompt("Ingrese el peso en kilos del container nro. "+ d +":") ) );
            while ( isNaN(kilos) || kilos <= 0 )
                {kilos = Math.round( parseInt(prompt("El dato ingresado es inválido!! Reingrese el peso en kilos del container nro. "+ d +":")) );}
            if ( kilos < min || d==1 )
                {min = kilos;
                 dmin = d;}
            if ( kilos > max || d==1 )
                {max = kilos;
                dmax = d;}
        }
   
alert("El container mas pesado es el nro: " + dmax + ". El container menos pesado es el nro: " + dmin);


}




function Id()
{

alert("Id");
}

