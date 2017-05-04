/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{
    
var n1 = parseInt(prompt("Ingrese el 1º numero"));
while (isNaN(n1))
    {n1 = parseInt(prompt("El dato ingresado es inválido!! Reingrese el 1º numero"));}

var n2 = parseInt(prompt("Ingrese el 2º numero"));
while (isNaN(n2))
    {n2 = parseInt(prompt("El dato ingresado es inválido!! Reingrese el 2º numero"));}

if (n1==n2)
    { document.write("El producto es: "+ (n1*n2) ); }
else if (n1>n2)
    { document.write("La resta es: "+ (n1-n2) ); }
else
    { document.write("La suma es: "+ (n1+n2) ); }

}



function Id()
{


}

