/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{
    var importe;
    var max;
    var min;

    for (var d=1;d<25;d++)
        {
            importe = Math.round( parseInt( prompt("Ingrese el importe de ventas del dia "+ d +":") )*100 )/100;
            while ( isNaN(importe) || importe <= 0 )
                {importe = Math.round( parseInt(prompt("El dato ingresado es inválido!! Reingrese el importe de ventas del dia "+ d +":"))*100 )/100;}
            if ( importe < min || d==1 )
                {min = importe;}
            if ( importe > max || d==1 )
                {max = importe;}
        }
   
alert("El mayor importe de ventas fue: " + max + ". El menor importe de ventas fue: " + min);

}



function Id()
{

alert("Id");
}

